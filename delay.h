#ifndef __DELAY_H
#define __DELAY_H
#include  "sys.h"

void delay_Config(uint8_t SysCLK);
void delay_us(uint32_t nus);
void delay_ms(uint16_t nms);
#endif