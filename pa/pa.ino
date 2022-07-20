#include <Servo.h>
//#include <LiquidCrystal.h>
 
//蜂鸣器端口定义
#define Buzz P2_3 //控制蜂鸣器
 
//前轮舵机端口定义
Servo carservo;
#define Servopin P1_2//控制舵机
 
//LCD显示屏端口定义
//LiquidCrystal lcd(P8_1, P8_2, P4_3, P4_0, P3_7, P7_4);
 
//右电机端口定义
#define MotorRpin1   P1_0  //IN1
#define MotorRpin2   P1_1  //IN2
#define MotorRpwm    P2_1  //使能调速 ENA
#define MotorRcountA P1_5 //编码器A
 
//左电机端口定义
#define MotorLpin1   P1_3  //IN3
#define MotorLpin2   P1_4 //IN4
#define MotorLpwm    P2_2  //使能调速 ENB
#define MotorLcountA P2_0  //编码器B
 
//三路传感器
#define sensor1 P2_6
#define sensor2 P2_5
#define sensor3 P2_4
 
//控速变量
volatile float motorL=0;//中断变量，左轮子脉冲计数
volatile float motorR=0;//中断变量，右轮子脉冲计数
float V_L=0; //左轮速度 单位cm/s
float V_R=0; //右边轮速 单位cm/s
int v1=0;  //单位cm/s
int v2=0;  //单位cm/s
float Target_V_L=13,Target_V_R=13;   //目标速度，单位cm/s
int Pwm_L=0,Pwm_R=0;  //左右轮PWM
int Pwm_min = 150;//50 92 105 
//PID变量
float kp=0.8,ki=0,kd=0.2;  //PID参数
 
 
/**************************************
 * 初始化函数
 *************************************/
void setup() {
   //LCD初始化
   //lcd.begin(16, 2);
   //lcd.print("Start");
   Motor_Init();//电机端口初始化
   Servo_Init();//舵机端口初始化
   pinMode(Buzz,OUTPUT);//蜂鸣器初始化
   //循迹初始化
   pinMode(sensor1,INPUT);
   pinMode(sensor2,INPUT);
   pinMode(sensor3,INPUT);
   digitalWrite(Buzz,LOW);
}
 
void Servo_Init(){
   carservo.attach(Servopin); 
   carservo.write(82); 
   delay(15);
}
 
void Motor_Init(){
  //左电机
  pinMode(MotorLpin1,OUTPUT);  //驱动芯片控制引脚
  pinMode(MotorLpin2,OUTPUT);  //驱动芯片控制引脚
  pinMode(MotorLpwm,OUTPUT);   //驱动芯片控制引脚，PWM调速
  pinMode(MotorLcountA,INPUT); //左轮编码器B引脚
  
  //右电机
  pinMode(MotorRpin1,OUTPUT);  //驱动芯片控制引脚
  pinMode(MotorRpin2,OUTPUT);  //驱动芯片控制引脚
  pinMode(MotorRpwm,OUTPUT);   //驱动芯片控制引脚，PWM调速
  pinMode(MotorRcountA,INPUT); //右轮编码器B引脚
 
  //驱动芯片控制引脚全部拉低
  digitalWrite(MotorLpin1,LOW); //左电机
  digitalWrite(MotorLpin2,LOW);
  digitalWrite(MotorLpwm,LOW);
  digitalWrite(MotorRpin1,LOW); //右电机
  digitalWrite(MotorRpin2,LOW);
  digitalWrite(MotorRpwm,LOW);
}
 
 
/*********************************************************
 * 函数功能：增量式PI控制器(左轮)
 *********************************************************/
 int Incremental_Pi_L(int current_speed,int target_speed){
  static float pwm,bias,last_bias,prev_bias;  //静态变量存在程序全周期：pwm:增量输出,bias:本次偏差,last_bias:上次偏差,prev_bais_:上上次偏差
  bias=current_speed-target_speed;    //计算本次偏差e(k)
  pwm-=(kp*(bias-last_bias)+ki*bias+kd*(bias-2*last_bias+prev_bias));   //增量式PID控制器
  prev_bias=last_bias;  //保存上上次偏差
  last_bias=bias;     //保存上一次偏差
  //PWM 限幅度  Arduino的PWM 最高为255 限制在250 最低在153 限制在153
  if(pwm<-250)
  {
    pwm=250;     
  }
  if(Pwm_min<pwm<0)
  {
    pwm = Pwm_min;//0度 50 爬坡153
  }
  if(pwm>250)
  {
    pwm=250;  
  }
  if(0<pwm<Pwm_min)
  {
    pwm = Pwm_min;
  }
  return pwm;         //增量输出
 }
 
//右轮速度增量式PID控制器
int Incremental_Pi_R(float current_speed,float target_speed){
  static float pwm,bias,last_bias,prev_bias;  //静态变量存在程序全周期：pwm:增量输出,bias:本次偏差,last_bias:上次偏差,prev_bais_:上上次偏差
  bias=current_speed-target_speed;    //计算本次偏差e(k)
  pwm-=(kp*(bias-last_bias)+ki*bias+kd*(bias-2*last_bias+prev_bias));   //增量式PID控制器
  prev_bias=last_bias;  //保存上上次偏差
  last_bias=bias;     //保存上一次偏差
 
  //PWM 限幅度  Arduino的PWM 最高为255限制在250,最小在153限制在153
  if(pwm<-250)
  {
    pwm=250;     
  }
  
  if(Pwm_min<pwm<0)
  {
    pwm = Pwm_min;
  }
  
  if(pwm>250)
  {
    pwm=250;  
  }
  
  if(0<pwm<Pwm_min)
  {
    pwm = Pwm_min;
  }
  return pwm;         //增量输出
 }
 
void Set_Pwm(int speed_L,int speed_R){
  //前进模式
  //左电机
  digitalWrite(MotorLpin1,LOW);
  digitalWrite(MotorLpin2,HIGH);
  analogWrite(MotorLpwm,speed_L);
  //右电机
  digitalWrite(MotorRpin1,LOW);
  digitalWrite(MotorRpin2,HIGH);
  analogWrite(MotorRpwm,speed_R);
 // Serial.println("lello");
}
 
 
/***********************************
 * 电机实际速度计算：
 * 公式：
 * 已知参数：
 *     车轮直径65mm,
 *     左边轮子一圈：390脉冲（RISING）,
 *     右边轮子一圈：390脉冲（RISING），
 * 单位时间读两个轮子脉冲读取两个轮子脉冲
 ***********************************/
 void Read_Moto_V(){
  unsigned long nowtime=0;
  motorL=0;
  motorR=0;
  nowtime=millis()+50;//读50毫秒
  attachInterrupt(digitalPinToInterrupt(MotorLcountA),Read_Moto_L,RISING);//左轮脉冲开中断计数
  attachInterrupt(digitalPinToInterrupt(MotorRcountA),Read_Moto_R,RISING);//右轮脉冲开中断计数
  while(millis()<nowtime); //达到50毫秒关闭中断
  detachInterrupt(digitalPinToInterrupt(MotorLcountA));//左轮脉冲关中断计数
  detachInterrupt(digitalPinToInterrupt(MotorRcountA));//右轮脉冲关中断计数
  //Serial.println(motorL*100);
  //Serial.println(motorR*100);
  V_L=((motorL/390)*6.5*PI)/0.05;   //单位cm/s
  V_R=((motorR/390)*6.5*PI)/0.05;   //单位cm/s
  v1=V_L;
  v2=V_R;
}
 
 
/***************************
 * 中断函数：读左轮脉冲
 **************************/
void Read_Moto_L(){
  motorL++;
}
 
 
/**************************
 * 中断函数：读右轮脉冲
 *************************/
void Read_Moto_R(){
  motorR++;
}
 
//前进函数
void RUN(int RV,int LV){
   Target_V_L=LV,Target_V_R=RV;
   Read_Moto_V();//读取脉冲计算速度
   Pwm_L=Incremental_Pi_L(V_L,Target_V_L);//左轮PI运算
   Pwm_R=Incremental_Pi_R(V_R,Target_V_R);//右轮PI运算
   //Serial.println(V_L);  //直接用串口绘图画出速度曲线
   Set_Pwm(Pwm_L,Pwm_R);  //设置左右轮速度
}
 
 
 
//终点停车函数
void Stop(){
   //左电机
   digitalWrite(MotorLpin1,LOW);
   digitalWrite(MotorLpin2,LOW);
   //右电机
   digitalWrite(MotorRpin1,LOW);
   digitalWrite(MotorRpin2,LOW);
   //声音提示
   digitalWrite(Buzz,HIGH);
   delay(500);
   digitalWrite(Buzz,LOW);
   delay(1000);
   while(1);
}

/*
void LCDshow(){
   lcd.setCursor(0, 0);
   lcd.print("Speed:");
   lcd.setCursor(6, 0);
   lcd.print(V_L);
   lcd.setCursor(11, 0);
   lcd.print("cm/s");
   lcd.setCursor(0, 1);
   lcd.print("Time:");
   lcd.setCursor(5, 1);
   lcd.print(millis()*0.001);
   lcd.setCursor(10, 1);
   lcd.print("s");
}
*/
 
void Track()
{
   int data[3];
   data[0] = digitalRead(sensor1);//读取三个传感器值
   data[1] = digitalRead(sensor2);
   data[2] = digitalRead(sensor3);
   
   if(data[0]== 0 &&data[1] == 1 &&data[2] == 0)
   {
    // 0    1    0
       carservo.write(85);
       delay(15);
       RUN(6,6);
    }
   else if((data[0] == 0 && data[1] == 0 && data[2] == 0 ) && carservo.read()<100&&carservo.read()>70)
   {
    //0    0    0     70<servo<100
    RUN(10,0);
    }
   else if((data[0] == 0 && data[1] == 0 && data[2] == 0) && carservo.read()>100)
   {
    //0    0    0      100<servo
    RUN(0,10);
    }
   else if(data[0] == 1 && data[1] == 0 && data[2] == 0)
       Turn_right();   // 1    0    0
   else if(data[0] == 0 && data[1] == 0 && data[2] == 1)
       Turn_left();    // 0    0    1
   else if(data[0] == 1 && data[1] == 1 && data[2] == 1)
       Stop();        //  1    1    1
   /*Serial.println(data[0]);
   Serial.println(data[1]);
   Serial.println(data[2]);
   Serial.println("--------------");*/
}
//右转函数
void Turn_right(){
  carservo.write(145);//调整舵机角度 140 9.8 2.2//160
  delay(35);
  RUN(5,12);//后轮差速（右，左），左快右慢
}
 
//左转函数
void Turn_left()
{
  carservo.write(35);//调整舵机角度
  delay(30);//20
  RUN(10,6);//后轮差速（右，左），左慢右快  
}
 
/***************************************
 * 主循环
 ***************************************/
void loop() {
   //LCDshow();
   Track();
}
