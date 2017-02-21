/*
**********************************************************
Includes
*/
#include "stm32f10x.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
/*
**********************************************************
Defines
*/
#define LCD_RS_PIN		GPIO_Pin_6
#define LCD_RW_PIN		GPIO_Pin_5
#define LCD_EN_PIN		GPIO_Pin_4
#define LCD_D4_PIN		GPIO_Pin_3
#define LCD_D5_PIN		GPIO_Pin_2
#define LCD_D6_PIN		GPIO_Pin_1
#define LCD_D7_PIN		GPIO_Pin_0
#define LCD_GPIO_PORT	GPIOA
#define LCD_PORT_CLK	RCC_APB2Periph_GPIOA
#define LCD_ALL_PINS	GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_7
#define LCD_DATA_PINS   LCD_D4_PIN | LCD_D5_PIN | LCD_D6_PIN | LCD_D7_PIN
/*
**********************************************************
Private Function
*/

void lcd_Init(void);
void lcd_goto(int xd);
void lcd_clear(void);
void lcd_print(char c);
void lcd_prints(char *string);
void DWrite(uint8_t Dword);
void SendCmd(uint8_t cmd);
void SendData(uint8_t Data);
uint8_t DRead();
uint8_t ReadCmd();
uint8_t ReadData();
void DWriteH(uint8_t Dword);
void DWriteL(uint8_t Dword);
void Digitize(uint8_t Input);