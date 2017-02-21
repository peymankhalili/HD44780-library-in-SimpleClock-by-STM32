#include "main.h"
#include "string.h"
#include "stdio.h"
#include "lcd.h"
#include "c2b.h"

/**
 * @brief Initilize LCD
 * @details [
 * 1.Enable LCD Port CLK
 * 2.Set LCD PORT Configuration
 * 3.Send 4 bit mode command
 * ..]
 */
void lcd_Init(void) {

	GPIO_InitTypeDef GPIO_InitStruct;
	RCC_APB2PeriphClockCmd(LCD_PORT_CLK, ENABLE);
	/**
	 * Configure GPIOA
	 */
	GPIO_InitStruct.GPIO_Pin = LCD_RS_PIN | LCD_RW_PIN | LCD_EN_PIN | LCD_D4_PIN | LCD_D5_PIN | LCD_D6_PIN | LCD_D7_PIN;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(LCD_GPIO_PORT, &GPIO_InitStruct);
	GPIO_Write(LCD_GPIO_PORT, 0x0);
	Delay(50);
	/*
	Fuction Set *** Set to 4-bit but just by 4 bits send,others is 8 bit
	 */
	GPIO_WriteBit(LCD_GPIO_PORT, LCD_EN_PIN, Bit_SET);
	Delay(50);
	GPIO_WriteBit(LCD_GPIO_PORT, LCD_D5_PIN, Bit_SET);
	Delay(50);
	GPIO_WriteBit(LCD_GPIO_PORT, LCD_EN_PIN, Bit_RESET);
	Delay(50);
	GPIO_Write(LCD_GPIO_PORT, 0x0);
	/*
	Function Set***Interface is 4bits
	 */
	SendCmd(0b00101100);
	/*
	Display on/off
	 */
	SendCmd(0b00001100);
	/*
	Return Home
	*/
	lcd_goto(0);
	/*
	Entry Mode Set
	*/
	SendCmd(0b00000110);

}
/**
 * @brief [Move cursor to Dest.] *
 * @param xd [Destinatio x]
 */
void lcd_goto(int xd)
{
	if (xd == 0)
	{
		SendCmd(0b00000010);
		return;

	}
	if (xd > x)
	{
		for (int i = 0; i < xd - x - 2 ; i++ )
		{
			SendCmd(0b00010100);
		}
		x = xd;
		return;
	}
	if (xd < x)
	{
		for (int i = 0; i < x - xd - 1 ; i++ )
		{
			SendCmd(0b00010000);
		}
		x = xd;
		return;
	}
}
void lcd_clear(void)
{
	SendCmd(0b00000001);
}
void lcd_print(char c)
{
	SendData(c2b(c));
}

void lcd_prints(char *string)
{
	for (int i = 0; i < strlen(string) ; i++)
	{
		lcd_print(string[i]);
	}
}


void DWrite(uint8_t Dword)
{
	DWriteH(Dword);
	DWriteL(Dword);
}

void DWriteH(uint8_t Dword)
{
	Digitize(Dword >> 4);
}

void DWriteL(uint8_t Dword)
{
	Digitize(Dword & 0xF);
}

void Digitize(uint8_t Input)
{
	Delay(10);
	GPIO_WriteBit(LCD_GPIO_PORT, LCD_EN_PIN, Bit_SET);
	if (0x1 & Input)
		GPIO_WriteBit(LCD_GPIO_PORT, LCD_D4_PIN, Bit_SET);
	if (0x1 & (Input >> 1))
		GPIO_WriteBit(LCD_GPIO_PORT, LCD_D5_PIN, Bit_SET);
	if (0x1 & (Input >> 2))
		GPIO_WriteBit(LCD_GPIO_PORT, LCD_D6_PIN, Bit_SET);
	if (0x1 & (Input >> 3))
		GPIO_WriteBit(LCD_GPIO_PORT, LCD_D7_PIN, Bit_SET);
	Delay(50);
	GPIO_WriteBit(LCD_GPIO_PORT, LCD_EN_PIN, Bit_RESET);
	Delay(10);
	GPIO_WriteBit(LCD_GPIO_PORT, LCD_DATA_PINS, Bit_RESET);
}
void SendCmd(uint8_t cmd)
{
	GPIO_WriteBit(LCD_GPIO_PORT, LCD_RS_PIN, Bit_RESET);
	GPIO_WriteBit(LCD_GPIO_PORT, LCD_RW_PIN, Bit_RESET);
	DWrite(cmd);
}
void SendData(uint8_t Data)
{
	GPIO_WriteBit(LCD_GPIO_PORT, LCD_RS_PIN, Bit_SET);
	GPIO_WriteBit(LCD_GPIO_PORT, LCD_RW_PIN, Bit_RESET);
	DWrite(Data);
}
