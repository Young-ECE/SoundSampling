#include "stm32f4xx.h"
#include "delay.h"

void Led_Config(void)
{
	   	 
  GPIO_InitTypeDef  GPIO_InitStructure;

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);//使能GPIOA时钟

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;//LED0和LED1对应IO口
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//普通输出模式
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
  GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化GPIO
  GPIO_SetBits(GPIOA,GPIO_Pin_6 | GPIO_Pin_7);//默认设置为输出高电平
}

void WaterFlow_LED(uint16_t xms)
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_6);
	GPIO_SetBits(GPIOA,GPIO_Pin_7);
	delay_ms(xms);
	GPIO_SetBits(GPIOA,GPIO_Pin_6);
	GPIO_ResetBits(GPIOA,GPIO_Pin_7);
	delay_ms(xms);
}
void LED2_ON()
{
  GPIO_ResetBits(GPIOA,GPIO_Pin_6);
	GPIO_SetBits(GPIOA,GPIO_Pin_7);

}
void LED3_ON()
{
	GPIO_SetBits(GPIOA,GPIO_Pin_6);
	GPIO_ResetBits(GPIOA,GPIO_Pin_7);
}
void LED_Both_ON()
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_6 | GPIO_Pin_7);
}
void LED_Both_OFF()
{
	GPIO_SetBits(GPIOA,GPIO_Pin_6 | GPIO_Pin_7);
}