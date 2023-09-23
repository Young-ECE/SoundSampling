#include "System_Init.h"
void System_Init(void)
{
	HSE_RCC_Configuration(8,336,2,7);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	delay_Config(168);
}
