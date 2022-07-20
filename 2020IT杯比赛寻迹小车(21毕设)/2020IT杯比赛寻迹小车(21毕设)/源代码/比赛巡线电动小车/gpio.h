#ifndef __GPIO_H
#define __GPIO_H
#include "msp430.h"
/*************************************************/
/*     独立io口 P6.0~P6.7  定义   功能：输出     */
/*************************************************/
void GPIO6_Pin_0(unsigned int Pi);


void GPIO6_Pin_1(unsigned int Pi);


void GPIO6_Pin_2(unsigned int Pi);

void GPIO6_Pin_3(unsigned int Pi);              


void GPIO6_Pin_4(unsigned int Pi);

void GPIO6_Pin_5(unsigned int Pi);

void GPIO6_Pin_6(unsigned int Pi);

void GPIO6_Pin_7(unsigned int Pi);

/*************************************************/
/*     独立io口 P5.0~P5.7  定义   功能：输出     */
/*************************************************/
void GPIO5_Pin_0(unsigned int Pi);

void GPIO5_Pin_1(unsigned int Pi);

void GPIO5_Pin_2(unsigned int Pi);


void GPIO5_Pin_3(unsigned int Pi);                


void GPIO5_Pin_4(unsigned int Pi);


void GPIO5_Pin_5(unsigned int Pi);


void GPIO5_Pin_6(unsigned int Pi);


void GPIO5_Pin_7(unsigned int Pi);

/*************************************************/
/*     独立io口 P4.0~P4.7  定义   功能：输出     */
/*************************************************/
void GPIO4_Pin_0(unsigned int Pi);


void GPIO4_Pin_1(unsigned int Pi);


void GPIO4_Pin_2(unsigned int Pi);

void GPIO4_Pin_3(unsigned int Pi);

void GPIO4_Pin_4(unsigned int Pi);

void GPIO4_Pin_5(unsigned int Pi);

void GPIO4_Pin_6(unsigned int Pi);

void GPIO4_Pin_7(unsigned int Pi);

/*************************************************/
/*     独立io口 P3.0~P3.7  定义   功能：输出     */
/*************************************************/
void GPIO3_Pin_0(unsigned int Pi);


void GPIO3_Pin_1(unsigned int Pi);


void GPIO3_Pin_2(unsigned int Pi);


void GPIO3_Pin_3(unsigned int Pi);               


void GPIO3_Pin_4(unsigned int Pi);


void GPIO3_Pin_5(unsigned int Pi);

void GPIO3_Pin_6(unsigned int Pi);


void GPIO3_Pin_7(unsigned int Pi);

/*************************************************/
/*     独立io口 P2.0~P2.7  定义   功能：输出     */
/*************************************************/
void GPIO2_Pin_0(unsigned int Pi);

void GPIO2_Pin_1(unsigned int Pi);


void GPIO2_Pin_2(unsigned int Pi);

void GPIO2_Pin_3(unsigned int Pi);                


void GPIO2_Pin_4(unsigned int Pi);


void GPIO2_Pin_5(unsigned int Pi);


void GPIO2_Pin_6(unsigned int Pi);

void GPIO2_Pin_7(unsigned int Pi);

/*************************************************/
/*     独立io口 P1.0~P1.7  定义   功能：输出     */
/*************************************************/
void GPIO1_Pin_0(unsigned int Pi);

void GPIO1_Pin_1(unsigned int Pi);


void GPIO1_Pin_2(unsigned int Pi);

void GPIO1_Pin_3(unsigned int Pi);

void GPIO1_Pin_4(unsigned int Pi);

void GPIO1_Pin_5(unsigned int Pi);

void GPIO1_Pin_6(unsigned int Pi);


void GPIO1_Pin_7(unsigned int Pi);

/////////////////////////////////////////////////////////////////////////////
//                                                                         //
/////////////////////////////////////////////////////////////////////////////


/****************************************************************************/
/*    独立io口读操作   读0 读1   默认:读1    P1.0~P1.7                      */
/****************************************************************************/
#define Read_GPIO1_Pin_0 (P1IN&0X01)//0000 0001   读P1.0的值 宏定义  默认高电平
#define Read_GPIO1_Pin_1 (P1IN&0X02)//0000 0010   读P1.1的值 宏定义  默认高电平
#define Read_GPIO1_Pin_2 (P1IN&0X04)//0000 0100   读P1.2的值 宏定义  默认高电平
#define Read_GPIO1_Pin_3 (P1IN&0X08)//0000 1000   读P1.3的值 宏定义  默认高电平
#define Read_GPIO1_Pin_4 (P1IN&0X10)//0001 0000   读P1.4的值 宏定义  默认高电平
#define Read_GPIO1_Pin_5 (P1IN&0X20)//0010 0000   读P1.5的值 宏定义  默认高电平
#define Read_GPIO1_Pin_6 (P1IN&0X40)//0100 0000   读P1.6的值 宏定义  默认高电平
#define Read_GPIO1_Pin_7 (P1IN&0X80)//1000 0000   读P1.7的值 宏定义  默认高电平


/****************************************************************************/
/*    独立io口读操作   读0 读1   默认:读1    P2.0~P2.7                      */
/****************************************************************************/
#define Read_GPIO2_Pin_0 (P2IN&0X01)//0000 0001   读P2.0的值 宏定义  默认高电平
#define Read_GPIO2_Pin_1 (P2IN&0X02)//0000 0010   读P2.1的值 宏定义  默认高电平
#define Read_GPIO2_Pin_2 (P2IN&0X04)//0000 0100   读P2.2的值 宏定义  默认高电平
#define Read_GPIO2_Pin_3 (P2IN&0X08)//0000 1000   读P2.3的值 宏定义  默认高电平
#define Read_GPIO2_Pin_4 (P2IN&0X10)//0001 0000   读P2.4的值 宏定义  默认高电平
#define Read_GPIO2_Pin_5 (P2IN&0X20)//0010 0000   读P2.5的值 宏定义  默认高电平
#define Read_GPIO2_Pin_6 (P2IN&0X40)//0100 0000   读P2.6的值 宏定义  默认高电平
#define Read_GPIO2_Pin_7 (P2IN&0X80)//1000 0000   读P2.7的值 宏定义  默认高电平


/****************************************************************************/
/*    独立io口读操作   读0 读1   默认:读1    P3.0~P3.7                      */
/****************************************************************************/
#define Read_GPIO3_Pin_0 (P3IN&0X01)//0000 0001   读P3.0的值 宏定义  默认高电平
#define Read_GPIO3_Pin_1 (P3IN&0X02)//0000 0010   读P3.1的值 宏定义  默认高电平
#define Read_GPIO3_Pin_2 (P3IN&0X04)//0000 0100   读P3.2的值 宏定义  默认高电平
#define Read_GPIO3_Pin_3 (P3IN&0X08)//0000 1000   读P3.3的值 宏定义  默认高电平
#define Read_GPIO3_Pin_4 (P3IN&0X10)//0001 0000   读P3.4的值 宏定义  默认高电平
#define Read_GPIO3_Pin_5 (P3IN&0X20)//0010 0000   读P3.5的值 宏定义  默认高电平
#define Read_GPIO3_Pin_6 (P3IN&0X40)//0100 0000   读P3.6的值 宏定义  默认高电平
#define Read_GPIO3_Pin_7 (P3IN&0X80)//1000 0000   读P3.7的值 宏定义  默认高电平


/****************************************************************************/
/*    独立io口读操作   读0 读1   默认:读1    P4.0~P4.7                      */
/****************************************************************************/
#define Read_GPIO4_Pin_0 (P4IN&0X01)//0000 0001   读P4.0的值 宏定义  默认高电平
#define Read_GPIO4_Pin_1 (P4IN&0X02)//0000 0010   读P4.1的值 宏定义  默认高电平
#define Read_GPIO4_Pin_2 (P4IN&0X04)//0000 0100   读P4.2的值 宏定义  默认高电平
#define Read_GPIO4_Pin_3 (P4IN&0X08)//0000 1000   读P4.3的值 宏定义  默认高电平
#define Read_GPIO4_Pin_4 (P4IN&0X10)//0001 0000   读P4.4的值 宏定义  默认高电平
#define Read_GPIO4_Pin_5 (P4IN&0X20)//0010 0000   读P4.5的值 宏定义  默认高电平
#define Read_GPIO4_Pin_6 (P4IN&0X40)//0100 0000   读P4.6的值 宏定义  默认高电平
#define Read_GPIO4_Pin_7 (P4IN&0X80)//1000 0000   读P4.7的值 宏定义  默认高电平


/****************************************************************************/
/*    独立io口读操作   读0 读1   默认:读1    P5.0~P5.7                      */
/****************************************************************************/
#define Read_GPIO5_Pin_0 (P5IN&0X01)//0000 0001   读P5.0的值 宏定义  默认高电平
#define Read_GPIO5_Pin_1 (P5IN&0X02)//0000 0010   读P5.1的值 宏定义  默认高电平
#define Read_GPIO5_Pin_2 (P5IN&0X04)//0000 0100   读P5.2的值 宏定义  默认高电平
#define Read_GPIO5_Pin_3 (P5IN&0X08)//0000 1000   读P5.3的值 宏定义  默认高电平
#define Read_GPIO5_Pin_4 (P5IN&0X10)//0001 0000   读P5.4的值 宏定义  默认高电平
#define Read_GPIO5_Pin_5 (P5IN&0X20)//0010 0000   读P5.5的值 宏定义  默认高电平
#define Read_GPIO5_Pin_6 (P5IN&0X40)//0100 0000   读P5.6的值 宏定义  默认高电平
#define Read_GPIO5_Pin_7 (P5IN&0X80)//1000 0000   读P5.7的值 宏定义  默认高电平


/****************************************************************************/
/*    独立io口读操作   读0 读1   默认:读1    P6.0~P6.7                      */
/****************************************************************************/
#define Read_GPIO6_Pin_0 (P6IN&0X01)//0000 0001   读P6.0的值 宏定义  默认高电平
#define Read_GPIO6_Pin_1 (P6IN&0X02)//0000 0010   读P6.1的值 宏定义  默认高电平
#define Read_GPIO6_Pin_2 (P6IN&0X04)//0000 0100   读P6.2的值 宏定义  默认高电平
#define Read_GPIO6_Pin_3 (P6IN&0X08)//0000 1000   读P6.3的值 宏定义  默认高电平
#define Read_GPIO6_Pin_4 (P6IN&0X10)//0001 0000   读P6.4的值 宏定义  默认高电平
#define Read_GPIO6_Pin_5 (P6IN&0X20)//0010 0000   读P6.5的值 宏定义  默认高电平
#define Read_GPIO6_Pin_6 (P6IN&0X40)//0100 0000   读P6.6的值 宏定义  默认高电平
#define Read_GPIO6_Pin_7 (P6IN&0X80)//1000 0000   读P6.7的值 宏定义  默认高电平
#endif