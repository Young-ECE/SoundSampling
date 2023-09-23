#ifndef __IIC_H
#define __IIC_H
#define I2C_Speed 400000
#define I2C_OWN_ADDRESS I2C_Register_OAR1
#define OLED_ADDRESS 0x78
#include "stm32f4xx.h"
#include "delay.h"

void I2C1_Config(void);
void I2C_WriteByte(uint8_t addr,uint8_t data);
void WriteCmd(unsigned char I2C_Command);
void WriteData(unsigned char I2C_Data);

#endif