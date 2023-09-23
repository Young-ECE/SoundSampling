#include "stm32f4xx.h"
#include "delay.h"

void Led_Config(void)
{
	   	 
  GPIO_InitTypeDef  GPIO_InitStructure;

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);//ʹ��GPIOAʱ��

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;//LED0��LED1��ӦIO��
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//��ͨ���ģʽ
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
  GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ��GPIO
  GPIO_SetBits(GPIOA,GPIO_Pin_6 | GPIO_Pin_7);//Ĭ������Ϊ����ߵ�ƽ
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