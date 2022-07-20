#ifndef _PID_H
#define _PID_H

/*
调试
输入速度30
P=0.100,I=0.00,D=0.0     没什么反应 响声很小
P=0.500,I=0.0,D=0.0      没什么反应 有点响声
P=0.700,I=0.00,D=0.0     没什么反应 动了一下
P=0.800,I=0.00,D=800.0   动了一下  输出28
P=1.200,I=0.00,D=800.0   一快一慢  输出38
P=0.000,I=0.10,D=0.0     反应很猛 一下就max
P=0.000,I=0.05,D=0.0     反应比较猛 一快一慢
P=0.000,I=0.02,D=0.0     反应较猛 一快一慢
P=0.000,I=0.01,D=0.0    反应灵敏 一快一慢 周期2S
P=0.000,I=0.007,D=0.0    反应平缓 一快一慢 周期4S
P=0.000,I=0.004,D=0.0    反应平缓 一快一慢 周期8S
P=0.000,I=0.001,D=0.0    反应及慢 加速需要十几秒
P=0.700,I=0.007,D=0.0    反应平缓 一快一慢 周期3S
P=0.700,I=0.003,D=0.0    反应平缓 一快一慢 周期4S
P=0.700,I=0.001,D=0.0    反应平缓 一快一慢 周期4S
P=0.400,I=0.001,D=0.0    反应平缓 一快一慢 周期5S
P=0.400,I=0.001,D=0.0    反应平缓 一快一慢 周期5S
P=0.100,I=0.001,D=100.0  反应迟钝  加速9秒 突然快 然后匀速   
P=0.300,I=0.003,D=500.0  反应迟钝  加速6秒 突然快  然后匀速   
P=0.500,I=0.008,D=500.0  反应迟钝  加速3秒  突然快  然后匀速   
P=0.500,I=0.008,D=900.0  反应灵敏  加速1秒  一快一慢3次  然后匀速   
P=0.600,I=0.003,D=900.0  反应灵敏  加速1秒  一快一慢3次 
P=0.600,I=0.002,D=900.0  反应灵敏  加速1秒  一快一慢3次 
P=0.600,I=0.001,D=900.0  反应灵敏  加速1秒  一快一慢3次 
P=0.400,I=0.003,D=900.0  反应灵敏  加速2秒  突然快  然后匀速   
P=0.400,I=0.005,D=900.0  反应灵敏  加速1秒  突然快  然后匀速   
*/



float P=2.300,I=0.030,D=10.0,Set_Temp=60;//初始化P,I,D，当前值，设置值 常数
float PID_OUT=0,PWM_Duty=0;    //PID输出           
float P_OUT=0,I_OUT=0,D_OUT=0;    //比例输出，积分输出，微分输出
float Current_Error=0, Last_Error=0;    //当前误差  最后误差
float Sum_Error=0,Prev_Error=0;     //误差积分 
float Gain=1.2,PID_I_MAX=100.0,PID_I_MIN=-100.0,V_DATA_MAX=100,V_DATA_MIN=0;

float Set_Temp1=60;//初始化P,I,D，当前值，设置值 常数
float PID_OUT1=0,PWM_Duty1=0;    //PID输出           
float P_OUT1=0,I_OUT1=0,D_OUT1=0;    //比例输出，积分输出，微分输出
float Current_Error1=0, Last_Error1=0;    //当前误差  最后误差
float Sum_Error1=0,Prev_Error1=0;     //误差积分 
float Gain1=1.2,PID_I_MAX1=100.0,PID_I_MIN1=-100.0,V_DATA_MAX1=100,V_DATA_MIN1=0;

float Set_Temp2=60;//初始化P,I,D，当前值，设置值 常数
float PID_OUT2=0,PWM_Duty2=0;    //PID输出           
float P_OUT2=0,I_OUT2=0,D_OUT2=0;    //比例输出，积分输出，微分输出
float Current_Error2=0, Last_Error2=0;    //当前误差  最后误差
float Sum_Error2=0,Prev_Error2=0;     //误差积分 
float Gain2=1.2,PID_I_MAX2=100.0,PID_I_MIN2=-100.0,V_DATA_MAX2=100,V_DATA_MIN2=0;

float Set_Temp3=60;//初始化P,I,D，当前值，设置值 常数
float PID_OUT3=0,PWM_Duty3=0;    //PID输出           
float P_OUT3=0,I_OUT3=0,D_OUT3=0;    //比例输出，积分输出，微分输出
float Current_Error3=0, Last_Error3=0;    //当前误差  最后误差
float Sum_Error3=0,Prev_Error3=0;     //误差积分 
float Gain3=1.2,PID_I_MAX3=100.0,PID_I_MIN3=-100.0,V_DATA_MAX3=100,V_DATA_MIN3=0;
void PID_calc(void)//PID算法
{
  float Rate;//误差变化率
  Current_Error = Set_Temp - V_1;//当前误差
  Sum_Error +=Current_Error;//误差积分
  Prev_Error = Last_Error;//存储误差积分
  Last_Error = Current_Error;//存储误差分析
  Rate = Current_Error-Last_Error;//变化速率计算
  
        
  if(Rate>10)//不让ta大于5也不让ta小于5
    Rate = 10;
  if(Rate<-10)
    Rate = -10;
  
  P_OUT = P*Gain*Current_Error;//比列项
  I_OUT = I*Gain*Sum_Error;//积分项
  
  //积分限幅处理
  if( I_OUT>PID_I_MAX )  I_OUT = PID_I_MAX;//不能超过最大值不能低于最小值
  if( I_OUT<PID_I_MIN )  I_OUT = PID_I_MIN;

  //微分输出处理
  D_OUT = D*Gain*Rate;
  PID_OUT =  P_OUT  +  I_OUT  +  D_OUT ;
  if ( PID_OUT >= V_DATA_MAX )  PID_OUT = V_DATA_MAX;
  if ( PID_OUT <= V_DATA_MIN )  PID_OUT = V_DATA_MIN;
/*******************************************************/
  float Rate1;//误差变化率
  Current_Error1 = Set_Temp1 - V_2;//当前误差
  Sum_Error1 +=Current_Error1;//误差积分
  Prev_Error1 = Last_Error1;//存储误差积分
  Last_Error1 = Current_Error1;//存储误差分析
  Rate1 = Current_Error1-Last_Error1;//变化速率计算
  
 
  if(Rate1>10)//不让ta大于5也不让ta小于5
    Rate1 = 10;
  if(Rate1<-10)
    Rate1 = -10;
  
  P_OUT1 = P*Gain1*Current_Error1;//比列项
  I_OUT1 = I*Gain1*Sum_Error1;//积分项
  
  //积分限幅处理
  if( I_OUT1>PID_I_MAX1 )  I_OUT1 = PID_I_MAX1;//不能超过最大值不能低于最小值
  if( I_OUT1<PID_I_MIN1 )  I_OUT1 = PID_I_MIN1;

  //微分输出处理
  D_OUT1 = D*Gain*Rate1;
  PID_OUT1 =  P_OUT1  +  I_OUT1  +  D_OUT1 ;
  if ( PID_OUT1 >= V_DATA_MAX1 )  PID_OUT1 = V_DATA_MAX1;
  if ( PID_OUT1 <= V_DATA_MIN1 )  PID_OUT1 = V_DATA_MIN1;
 /*******************************************************/
  
  
  
  
  
  float Rate2;//误差变化率
  Current_Error2 = Set_Temp2 - V_3;//当前误差
  Sum_Error2 +=Current_Error2;//误差积分
  Prev_Error2 = Last_Error2;//存储误差积分
  Last_Error2 = Current_Error2;//存储误差分析
  Rate2 = Current_Error2-Last_Error2;//变化速率计算
  
        
  if(Rate2>10)//不让ta大于5也不让ta小于5
    Rate2 = 10;
  if(Rate2<-10)
    Rate2 = -10;
  
  P_OUT2 = P*Gain2*Current_Error2;//比列项
  I_OUT2 = I*Gain2*Sum_Error2;//积分项
  
  //积分限幅处理
  if( I_OUT2>PID_I_MAX2 )  I_OUT2 = PID_I_MAX2;//不能超过最大值不能低于最小值
  if( I_OUT2<PID_I_MIN2)  I_OUT2 = PID_I_MIN2;

  //微分输出处理
  D_OUT2 = D*Gain2*Rate2;
  PID_OUT2 =  P_OUT2  +  I_OUT2  +  D_OUT2 ;
  if ( PID_OUT2 >= V_DATA_MAX2 )  PID_OUT2 = V_DATA_MAX2;
  if ( PID_OUT2 <= V_DATA_MIN2 )  PID_OUT2 = V_DATA_MIN2;
  /*******************************************************/
  float Rate3;//误差变化率
  Current_Error3 = Set_Temp3 - V_4;//当前误差
  Sum_Error3 +=Current_Error3;//误差积分
  Prev_Error3 = Last_Error3;//存储误差积分
  Last_Error3 = Current_Error3;//存储误差分析
  Rate3 = Current_Error3-Last_Error3;//变化速率计算
  
        
  if(Rate3>10)//不让ta大于5也不让ta小于5
    Rate3 = 10;
  if(Rate3<-10)
    Rate3 = -10;
  
  P_OUT3 = P*Gain3*Current_Error3;//比列项
  I_OUT3 = I*Gain3*Sum_Error3;//积分项
  
  //积分限幅处理
  if( I_OUT3>PID_I_MAX3 )  I_OUT3 = PID_I_MAX3;//不能超过最大值不能低于最小值
  if( I_OUT3<PID_I_MIN3 )  I_OUT3 = PID_I_MIN3;

  //微分输出处理
  D_OUT3 = D*Gain3*Rate3;
  PID_OUT3 =  P_OUT3  +  I_OUT3  +  D_OUT3 ;
  if ( PID_OUT3 >= V_DATA_MAX3 )  PID_OUT3 = V_DATA_MAX3;
  if ( PID_OUT3 <= V_DATA_MIN3 )  PID_OUT3 = V_DATA_MIN3;
}  


#endif