#ifndef _PID_H
#define _PID_H

/*
����
�����ٶ�30
P=0.100,I=0.00,D=0.0     ûʲô��Ӧ ������С
P=0.500,I=0.0,D=0.0      ûʲô��Ӧ �е�����
P=0.700,I=0.00,D=0.0     ûʲô��Ӧ ����һ��
P=0.800,I=0.00,D=800.0   ����һ��  ���28
P=1.200,I=0.00,D=800.0   һ��һ��  ���38
P=0.000,I=0.10,D=0.0     ��Ӧ���� һ�¾�max
P=0.000,I=0.05,D=0.0     ��Ӧ�Ƚ��� һ��һ��
P=0.000,I=0.02,D=0.0     ��Ӧ���� һ��һ��
P=0.000,I=0.01,D=0.0    ��Ӧ���� һ��һ�� ����2S
P=0.000,I=0.007,D=0.0    ��Ӧƽ�� һ��һ�� ����4S
P=0.000,I=0.004,D=0.0    ��Ӧƽ�� һ��һ�� ����8S
P=0.000,I=0.001,D=0.0    ��Ӧ���� ������Ҫʮ����
P=0.700,I=0.007,D=0.0    ��Ӧƽ�� һ��һ�� ����3S
P=0.700,I=0.003,D=0.0    ��Ӧƽ�� һ��һ�� ����4S
P=0.700,I=0.001,D=0.0    ��Ӧƽ�� һ��һ�� ����4S
P=0.400,I=0.001,D=0.0    ��Ӧƽ�� һ��һ�� ����5S
P=0.400,I=0.001,D=0.0    ��Ӧƽ�� һ��һ�� ����5S
P=0.100,I=0.001,D=100.0  ��Ӧ�ٶ�  ����9�� ͻȻ�� Ȼ������   
P=0.300,I=0.003,D=500.0  ��Ӧ�ٶ�  ����6�� ͻȻ��  Ȼ������   
P=0.500,I=0.008,D=500.0  ��Ӧ�ٶ�  ����3��  ͻȻ��  Ȼ������   
P=0.500,I=0.008,D=900.0  ��Ӧ����  ����1��  һ��һ��3��  Ȼ������   
P=0.600,I=0.003,D=900.0  ��Ӧ����  ����1��  һ��һ��3�� 
P=0.600,I=0.002,D=900.0  ��Ӧ����  ����1��  һ��һ��3�� 
P=0.600,I=0.001,D=900.0  ��Ӧ����  ����1��  һ��һ��3�� 
P=0.400,I=0.003,D=900.0  ��Ӧ����  ����2��  ͻȻ��  Ȼ������   
P=0.400,I=0.005,D=900.0  ��Ӧ����  ����1��  ͻȻ��  Ȼ������   
*/



float P=2.300,I=0.030,D=10.0,Set_Temp=60;//��ʼ��P,I,D����ǰֵ������ֵ ����
float PID_OUT=0,PWM_Duty=0;    //PID���           
float P_OUT=0,I_OUT=0,D_OUT=0;    //������������������΢�����
float Current_Error=0, Last_Error=0;    //��ǰ���  ������
float Sum_Error=0,Prev_Error=0;     //������ 
float Gain=1.2,PID_I_MAX=100.0,PID_I_MIN=-100.0,V_DATA_MAX=100,V_DATA_MIN=0;

float Set_Temp1=60;//��ʼ��P,I,D����ǰֵ������ֵ ����
float PID_OUT1=0,PWM_Duty1=0;    //PID���           
float P_OUT1=0,I_OUT1=0,D_OUT1=0;    //������������������΢�����
float Current_Error1=0, Last_Error1=0;    //��ǰ���  ������
float Sum_Error1=0,Prev_Error1=0;     //������ 
float Gain1=1.2,PID_I_MAX1=100.0,PID_I_MIN1=-100.0,V_DATA_MAX1=100,V_DATA_MIN1=0;

float Set_Temp2=60;//��ʼ��P,I,D����ǰֵ������ֵ ����
float PID_OUT2=0,PWM_Duty2=0;    //PID���           
float P_OUT2=0,I_OUT2=0,D_OUT2=0;    //������������������΢�����
float Current_Error2=0, Last_Error2=0;    //��ǰ���  ������
float Sum_Error2=0,Prev_Error2=0;     //������ 
float Gain2=1.2,PID_I_MAX2=100.0,PID_I_MIN2=-100.0,V_DATA_MAX2=100,V_DATA_MIN2=0;

float Set_Temp3=60;//��ʼ��P,I,D����ǰֵ������ֵ ����
float PID_OUT3=0,PWM_Duty3=0;    //PID���           
float P_OUT3=0,I_OUT3=0,D_OUT3=0;    //������������������΢�����
float Current_Error3=0, Last_Error3=0;    //��ǰ���  ������
float Sum_Error3=0,Prev_Error3=0;     //������ 
float Gain3=1.2,PID_I_MAX3=100.0,PID_I_MIN3=-100.0,V_DATA_MAX3=100,V_DATA_MIN3=0;
void PID_calc(void)//PID�㷨
{
  float Rate;//���仯��
  Current_Error = Set_Temp - V_1;//��ǰ���
  Sum_Error +=Current_Error;//������
  Prev_Error = Last_Error;//�洢������
  Last_Error = Current_Error;//�洢������
  Rate = Current_Error-Last_Error;//�仯���ʼ���
  
        
  if(Rate>10)//����ta����5Ҳ����taС��5
    Rate = 10;
  if(Rate<-10)
    Rate = -10;
  
  P_OUT = P*Gain*Current_Error;//������
  I_OUT = I*Gain*Sum_Error;//������
  
  //�����޷�����
  if( I_OUT>PID_I_MAX )  I_OUT = PID_I_MAX;//���ܳ������ֵ���ܵ�����Сֵ
  if( I_OUT<PID_I_MIN )  I_OUT = PID_I_MIN;

  //΢���������
  D_OUT = D*Gain*Rate;
  PID_OUT =  P_OUT  +  I_OUT  +  D_OUT ;
  if ( PID_OUT >= V_DATA_MAX )  PID_OUT = V_DATA_MAX;
  if ( PID_OUT <= V_DATA_MIN )  PID_OUT = V_DATA_MIN;
/*******************************************************/
  float Rate1;//���仯��
  Current_Error1 = Set_Temp1 - V_2;//��ǰ���
  Sum_Error1 +=Current_Error1;//������
  Prev_Error1 = Last_Error1;//�洢������
  Last_Error1 = Current_Error1;//�洢������
  Rate1 = Current_Error1-Last_Error1;//�仯���ʼ���
  
 
  if(Rate1>10)//����ta����5Ҳ����taС��5
    Rate1 = 10;
  if(Rate1<-10)
    Rate1 = -10;
  
  P_OUT1 = P*Gain1*Current_Error1;//������
  I_OUT1 = I*Gain1*Sum_Error1;//������
  
  //�����޷�����
  if( I_OUT1>PID_I_MAX1 )  I_OUT1 = PID_I_MAX1;//���ܳ������ֵ���ܵ�����Сֵ
  if( I_OUT1<PID_I_MIN1 )  I_OUT1 = PID_I_MIN1;

  //΢���������
  D_OUT1 = D*Gain*Rate1;
  PID_OUT1 =  P_OUT1  +  I_OUT1  +  D_OUT1 ;
  if ( PID_OUT1 >= V_DATA_MAX1 )  PID_OUT1 = V_DATA_MAX1;
  if ( PID_OUT1 <= V_DATA_MIN1 )  PID_OUT1 = V_DATA_MIN1;
 /*******************************************************/
  
  
  
  
  
  float Rate2;//���仯��
  Current_Error2 = Set_Temp2 - V_3;//��ǰ���
  Sum_Error2 +=Current_Error2;//������
  Prev_Error2 = Last_Error2;//�洢������
  Last_Error2 = Current_Error2;//�洢������
  Rate2 = Current_Error2-Last_Error2;//�仯���ʼ���
  
        
  if(Rate2>10)//����ta����5Ҳ����taС��5
    Rate2 = 10;
  if(Rate2<-10)
    Rate2 = -10;
  
  P_OUT2 = P*Gain2*Current_Error2;//������
  I_OUT2 = I*Gain2*Sum_Error2;//������
  
  //�����޷�����
  if( I_OUT2>PID_I_MAX2 )  I_OUT2 = PID_I_MAX2;//���ܳ������ֵ���ܵ�����Сֵ
  if( I_OUT2<PID_I_MIN2)  I_OUT2 = PID_I_MIN2;

  //΢���������
  D_OUT2 = D*Gain2*Rate2;
  PID_OUT2 =  P_OUT2  +  I_OUT2  +  D_OUT2 ;
  if ( PID_OUT2 >= V_DATA_MAX2 )  PID_OUT2 = V_DATA_MAX2;
  if ( PID_OUT2 <= V_DATA_MIN2 )  PID_OUT2 = V_DATA_MIN2;
  /*******************************************************/
  float Rate3;//���仯��
  Current_Error3 = Set_Temp3 - V_4;//��ǰ���
  Sum_Error3 +=Current_Error3;//������
  Prev_Error3 = Last_Error3;//�洢������
  Last_Error3 = Current_Error3;//�洢������
  Rate3 = Current_Error3-Last_Error3;//�仯���ʼ���
  
        
  if(Rate3>10)//����ta����5Ҳ����taС��5
    Rate3 = 10;
  if(Rate3<-10)
    Rate3 = -10;
  
  P_OUT3 = P*Gain3*Current_Error3;//������
  I_OUT3 = I*Gain3*Sum_Error3;//������
  
  //�����޷�����
  if( I_OUT3>PID_I_MAX3 )  I_OUT3 = PID_I_MAX3;//���ܳ������ֵ���ܵ�����Сֵ
  if( I_OUT3<PID_I_MIN3 )  I_OUT3 = PID_I_MIN3;

  //΢���������
  D_OUT3 = D*Gain3*Rate3;
  PID_OUT3 =  P_OUT3  +  I_OUT3  +  D_OUT3 ;
  if ( PID_OUT3 >= V_DATA_MAX3 )  PID_OUT3 = V_DATA_MAX3;
  if ( PID_OUT3 <= V_DATA_MIN3 )  PID_OUT3 = V_DATA_MIN3;
}  


#endif