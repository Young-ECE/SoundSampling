#ifndef __USART_H
#define __USART_H
#define EN_USART2_RX 1
#include "System_Init.h"

void USART2_SendData_AutoClrFlag(USART_TypeDef* USARTx, uint16_t Data);
void Usart_Config(uint32_t baud);
#endif