#include "sys.h"

void HSE_RCC_Configuration(uint16_t M,uint16_t N,uint16_t P,uint16_t Q)
{
	__IO uint32_t HSEStartUpStatus = 0;
	
	RCC_DeInit();
	RCC_HSEConfig(RCC_HSE_ON);
	HSEStartUpStatus = RCC_WaitForHSEStartUp();
	
	if(HSEStartUpStatus == SUCCESS)
	{
		RCC->AHB1ENR |= RCC_APB1ENR_PWREN;
		PWR->CR |= PWR_CR_VOS;
		
		
		RCC_HCLKConfig(RCC_SYSCLK_Div1);
		RCC_PCLK2Config(RCC_HCLK_Div2);
		RCC_PCLK1Config(RCC_HCLK_Div4);
		
		RCC_PLLConfig(RCC_PLLSource_HSE,M,N,P,Q);
		
		RCC_PLLCmd(ENABLE);
		
		while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET);

FLASH->ACR = FLASH_ACR_PRFTEN
		        | FLASH_ACR_ICEN
		        | FLASH_ACR_DCEN
		        | FLASH_ACR_LATENCY_5WS;
		
		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
		while(RCC_GetSYSCLKSource() != 0x08);
		
	}
	else
	{
		
	}
	
	
	
}