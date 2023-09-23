#include "timer.h"

uint32_t tim_start;
uint32_t tim_end;
uint32_t tim;
void Timer_Config()
{ 
  	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	    
	  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);  // 使能TIM2时钟
	  
    TIM_TimeBaseStructure.TIM_Period = 0xffffffff;  // 定时器自动重载值
    TIM_TimeBaseStructure.TIM_Prescaler = 84-1;  // 定时器时钟预分频系数
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;  // 时钟分割
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  // 定时器计数模式：向上计数
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);  // 初始化定时器
}



/*TIM_Cmd(TIM2,ENABLE);
  tim_start=TIM_GetCounter(TIM2);

	  tim_end=TIM_GetCounter(TIM2);
	  tim=tim_end-tim_start;
   TIM_Cmd(TIM2,DISABLE);
	
	USART2_SendData_AutoClrFlag(USART2,tim); 
	USART2_SendData_AutoClrFlag(USART2,tim>>8); 
	USART2_SendData_AutoClrFlag(USART2,tim>>16); 
	USART2_SendData_AutoClrFlag(USART2,tim>>24); 
	*/