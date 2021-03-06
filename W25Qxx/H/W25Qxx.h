#ifndef _W25Qxx_H
#define _W25Qxx_H
#include "main.h"
#include "Print.h"
/*
需要：
1.GPIO
    推挽浮空输出，最高等级
2.硬件SPI
    全双工主机
    (默认设置)
    片选信号由软件触发
    数据长8bit
    先发高位MSB
    时钟分频后<80MHz
    上升沿时钟
    单周期触发
*/
#define W25Q64

extern SPI_HandleTypeDef hspi1;
#define W25Qxx_SPI_Handle hspi1
#define W25Qxx_CS_GPIOx GPIOA
#define W25Qxx_CS_PIN GPIO_PIN_4

uint16_t W25Qxx_Read_ID(void);
void W25Qxx_Sector_Erase(uint32_t Address);
void W25Qxx_Read_Data(uint32_t Address, uint8_t *Buf, uint32_t Len);
void W25Qxx_Write_Page(uint32_t Address, uint8_t *Buf, uint32_t Len);
void W25Qxx_Wait_Free(void);
void W25Qxx_CS_Hight(void);
void W25Qxx_Write_Sector(uint32_t Address, uint8_t *Buf, uint32_t Len);
void W25Qxx_Write(uint32_t Address, uint8_t *Buf, uint32_t Len);
void W25Qxx_Print_Sector(uint32_t Address);
#endif
