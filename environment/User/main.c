
#include "System_Init.h"
#include "key.h"
#include "led.h"
#include "oled.h"
#include "hard_usart.h"
#include "sound_sensor.h"
RCC_ClocksTypeDef  get_rcc_clock;
uint8_t chr[2048]={"abcd"};

int main()
{
	RCC_GetClocksFreq(&get_rcc_clock);//SYSCLK=168MHz,HCLK=168MHz,PCLK1=42KHz,PCLK2=84KHz
	
	/***************************************************/
	System_Init();//系统初始化
	Timer_Config();//定时器，用于测试程序运行时间
	
	/***************************************************/
	Led_Config();
	Key_Start();
	OLED_Start();
	
	/***************************************************/
  Usart_Start();//用于通信
	Sound_Sensor_Start();//用于采集数据
	
	/******************DMA模式*********************/
	Adc_Dma_Config();
	/*
  OLED_Fill(0xff);
	delay_ms(1000);
	OLED_Fill(0x00);
	delay_ms(1000);
	OLED_ShowStr(16*3,3,"YOUNG!",2);
	delay_ms(2000);
	OLED_CLr();
	OLED_ShowStr(0,0,"Key_func Init...",1);
	delay_ms(200);
	OLED_ShowStr(0,2,"Led_func Init...",1);
	delay_ms(300);
	OLED_ShowStr(0,4,"Usart_func Init...",1);
	delay_ms(300);
	OLED_ShowStr(0,6,"Adc_func Init...",1);
	delay_ms(1500);
	*/
	
	OLED_CLr();
	
	OLED_ShowStr(16*1,2,"Press the key1",2);
	while(1)
	{
		if(keyValue==KEY_3_PRESS)
		{
			
			ADC_SoftwareStartConv(ADC1);//启动ADC
			OLED_CLr();
			OLED_ShowStr(16*1,2,"AD&Sending ...",2);
			OLED_ShowStr(0,6,"Press key0 to stop ",1);
			
			break;
		}
	}

	while(1)
	{
			WaterFlow_LED(300);
		if(keyValue==KEY_4_PRESS)
		{
      ADC_Cmd(ADC1, DISABLE);
			DMA_Cmd(DMA2_Stream0, DISABLE);
      break; 
		}
	}	
	OLED_CLr();
	OLED_ShowStr(16*1,3,"Finished",2);
	LED_Both_ON();

}








