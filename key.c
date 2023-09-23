
#include "key.h"

void Key_Config(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);//使能GPIOA时钟

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_4;//LED0和LED1对应IO口
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//输入模式
  GPIO_InitStructure.GPIO_Speed = GPIO_High_Speed;//100MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
  GPIO_Init(GPIOE, &GPIO_InitStructure);//初始化GPIO
  
}

void Key_Start()

{
	Key_Config();
	EXTIx_Config();
}
	