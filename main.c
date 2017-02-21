/*
**********************************************************
Includes
*/
#include "stm32f10x.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
#include "main.h"
#include "lcd.h"
#include <stdio.h>
#include <string.h>
/*
**********************************************************
*/

/*
**********************************************************
Private Functions
*/
/*
Global Variable
*/
int second = 0;
int minute = 59;
int hour = 0;
/*
Main Function
 */

void main(void)
{
	char time[16];
	SysTick_Config(SystemCoreClock / 1000);
	lcd_Init();
	lcd_clear();
	sprintf(time, "%02d:%02d", hour, minute);
	lcd_prints(time);
	while (1)
	{
		second++;
		if (second == 60)
		{	second = 0;
			minute++;
			lcd_clear();
			sprintf(time, "%02d:%02d", hour, minute);
			lcd_prints(time);
		}

		if (minute == 60)
		{
			hour++;
			minute = 0;
			lcd_clear();
			sprintf(time, "%02d:%02d", hour, minute);
			lcd_prints(time);

		}
		if (hour == 12)
		{
			hour = 0;
			lcd_clear();
			sprintf(time, "%02d:%02d", hour, minute);
			lcd_prints(time);
		}
		Delay(1000);
	}
}
/*
Private Functions
 */
__IO uint32_t TimmingDelay;
void Delay(__IO uint32_t time)
{
	TimmingDelay = time;
	while (TimmingDelay != 0);
}

void SysTick_Handler(void)

{
	if (TimmingDelay != 0)
	{
		TimmingDelay --;
	}
}


void assert_failed(uint8_t* file, uint32_t line)
{

}
