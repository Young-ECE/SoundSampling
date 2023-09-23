#ifndef __OLED_IIC_H
#define __OLED_IIC_H
#include "delay.h"
#include "iic.h"
extern unsigned char F_16x16[];
extern const unsigned char F_6x8[][6];
extern const unsigned char F_8x16[][16];
extern unsigned char BMP1[];


void OLED_Config(void);
void OLED_Start(void);
void OLED_SetPos(unsigned char x, unsigned char y);
void OLED_Fill(unsigned char fill_Data);
void OLED_CLr(void);
void OLED_ON(void);
void OLED_OFF(void);
void OLED_ShowStr(unsigned char x, unsigned char y,  char* chr, unsigned char TextSize);
void OLED_ShowChinese(unsigned char x, unsigned char y, unsigned char N);
void OLED_DrawBMP(unsigned char x0,unsigned char y0,unsigned char x1,unsigned char y1,unsigned char BMP[]);
#endif