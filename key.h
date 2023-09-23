#ifndef __KEY_H
#define __KEY_H
#include "sys.h"
#include "delay.h"
#include "exti.h"

#define KEY_3 GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3)
#define KEY_4 GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4)

#define KEY_3_PRESS 3
#define KEY_4_PRESS 4

void Key_Config(void);
void Key_Start();
#endif