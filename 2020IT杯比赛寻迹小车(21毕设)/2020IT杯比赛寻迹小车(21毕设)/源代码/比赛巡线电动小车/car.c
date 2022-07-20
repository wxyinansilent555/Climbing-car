/*-------------------------------
泊车系统库函数
作者：明邦松
时间：2019.08.04
地址：创客基地
---------------------------------*/
#include "car.h"

#define wheel_PWM1  TBCCR1
#define wheel_PWM2  TBCCR2
#define wheel_PWM3  TBCCR3
#define wheel_PWM4  TBCCR4

#define wheel_zhen1 P6OUT&=~BIT1
#define wheel_zhen2 P6OUT&=~BIT2
#define wheel_zhen3 P6OUT&=~BIT3
#define wheel_zhen4 P6OUT&=~BIT4

#define wheel_fan1 P6OUT|=BIT1
#define wheel_fan2 P6OUT|=BIT2
#define wheel_fan3 P6OUT|=BIT3
#define wheel_fan4 P6OUT|=BIT4
/********************************************************************/
//延时函数，IAR自带，经常使用到
#define CPU_F ((double)8000000)   //外部高频晶振8MHZ
//#define CPU_F ((double)32768)   //外部低频晶振32.768KHZ
#define delay_us(x) __delay_cycles((long)(CPU_F*(double)x/1000000.0)) 
#define delay_ms(x) __delay_cycles((long)(CPU_F*(double)x/1000.0)) 
//串口波特率计算，当BRCLK=CPU_F时用下面的公式可以计算，否则要根据设置加入分频系数
#define baud           9600                                //设置波特率的大小
#define baud_setting   (uint)((ulong)CPU_F/((ulong)baud))  //波特率计算公式
#define baud_h         (uchar)(baud_setting>>8)            //提取高位
#define baud_l         (uchar)(baud_setting)               //低位
//自定义数据结构，方便使用
#define uchar unsigned char
#define uint  unsigned int
#define ulong unsigned long

void IO_init()//IO口初始化
{
  P6DIR = 0Xff;//P63 p64做正反转控制
  P6OUT = 0x00;
  
  P2DIR = 0Xff;//P63 p64做正反转控制
  P2OUT = 0xff;
}

void zhen_1(int v)//正转速度0-100
{
  wheel_zhen1;
  TBCCR1=10*v;
}
void zhen_2(int v)
{
  wheel_zhen2;
  TBCCR2=10*v;
}
void zhen_3(int v)
{
  wheel_zhen3;
  TBCCR3=10*v;
}
void zhen_4(int v)
{
  wheel_zhen4;
  TBCCR4=10*v;
}

void fan_1(int v)//反转速度0-100
{
  wheel_fan1;
  TBCCR1=1000-10*v;
}
void fan_2(int v)
{
  wheel_fan2;
  TBCCR2=1000-10*v;
}
void fan_3(int v)
{
  wheel_fan3;
  TBCCR3=1000-10*v;
}
void fan_4(int v)
{
  wheel_fan4;
  TBCCR4=1000-10*v;
}


void qian()
{
  zhen_1(90);
  zhen_2(95);
  zhen_3(100);
  zhen_4(100);
}
void hou()
{
  fan_1(100);
  fan_2(100);
  fan_3(100);
  fan_4(100);
}
void you()
{
  fan_1(100);
  fan_2(100);
  zhen_3(100);
  zhen_4(100);
}
void zuo()
{
  fan_3(100);
  fan_4(100);
  zhen_1(100);
  zhen_2(100);
}
void stop()
{
  wheel_zhen1;TBCCR1=0;
  wheel_zhen2;TBCCR2=0;
  wheel_zhen3;TBCCR3=0;
  wheel_zhen4;TBCCR4=0;
}
