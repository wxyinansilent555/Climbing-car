#ifndef _CAR_H
#define _CAR_H

#include "msp430.h"

void IO_init();//IO口初始化

void zhen_1(int v);//正转速度0-100

void zhen_2(int v);

void zhen_3(int v);

void zhen_4(int v);

void fan_1(int v);//反转速度0-100

void fan_2(int v);

void fan_3(int v);

void fan_4(int v);


void qian();

void hou();

void you();

void zuo();

void stop();



#endif