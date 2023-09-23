#ifndef __DMA_H
#define __DMA_H
#define BUFFER_SIZE 1024
#include "System_Init.h"

extern uint16_t AdcToDma_buffer[BUFFER_SIZE];
extern uint16_t AdcToDma_buffer_1[BUFFER_SIZE];

void Adc_Dma_Config();

#endif