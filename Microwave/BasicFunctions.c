#include "prototypes.h"



void delay_1ms()
{
	Systic_int();
	NVIC_ST_RELOAD_R = 16000 - 1;
	NVIC_ST_CURRENT_R = 0;
	while ((NVIC_ST_CTRL_R & 0x00010000) == 0) {};
}

void delay_ms(unsigned int delay)
{
	int i;
	for (i = 0; i < delay; i++)
	{
		delay_1ms();
	}
}

void delay_1us()
{
	Systic_int();
	NVIC_ST_RELOAD_R = 80 - 1;
	NVIC_ST_CURRENT_R = 0;
	while ((NVIC_ST_CTRL_R & 0x00010000) == 0) {};
}

void delay_us(unsigned int delay)
{
	int i;
	for (i = 0; i < delay; i++)
	{
		delay_1us();
	}
}


unsigned int SW1()
{
	return  !(GPIO_PORTF_DATA_R & 0x10);
}

unsigned int SW2()
{
	return !(GPIO_PORTF_DATA_R & 0x01);
}

bool checkingDoor()
{
	return (GPIO_PORTE_DATA_R & 0x10);
}



bool cooking(int delay)
{
	int i;
	int j;
	GPIO_PORTF_DATA_R |= 0x0E;
	for (j = 0; j < delay; j++) {

		counter(delay - j);
		for (i = 0; i < 100; i++)
		{
			if (SW1() || !checkingDoor())
			{
				while (SW1());
				if (!pause()) {
					LCD_command(1);
					return false;
				}
			}
			delay_ms(10);
		}
	}
	return true;
}



void FinishedCooking() {
	int i;
	LCD_command(1);
	printLCD("Finished Cooking");
	GPIO_PORTE_DATA_R |= 0x20;
	GPIO_PORTF_DATA_R |= 0x0E;
	for (i = 0; i < 6; i++)
	{
		GPIO_PORTF_DATA_R ^= 0x0E;
		GPIO_PORTE_DATA_R ^= 0x20; //buzzer toggling
		delay_ms(1000);
	}
	GPIO_PORTF_DATA_R &= ~0x0E;
	GPIO_PORTE_DATA_R &= ~0x20;
}


void start_cooking(int cooking_time) {
	if (cooking(cooking_time)) {
		FinishedCooking();
	}
	else {
		LCD_command(1);
	}
}

bool pause() {
	while (1) {
		int i;
		for (i = 0; i < 100; i++)
		{
			if (SW2() && checkingDoor()) {
				{
					GPIO_PORTF_DATA_R |= 0x0E;
					return true;
				}
			}
			if (SW1()) {
				GPIO_PORTF_DATA_R &= ~0x0E;
				return false;
			}
			delay_ms(10);
		}

		GPIO_PORTF_DATA_R ^= 0x0E;
	}
}



void counter(int seconds) {
	int sec;
	int minute;
	char c[5];
	LCD_command(1);
	minute = (int)(seconds / 60);
	sec = seconds - 60 * minute;
	sprintf(c, "%02d:%02d", minute, sec);
	printLCD(c);
}


void LCD_Data_String(char c[])
{

	int i;
	for (i = 0; i < strlen(c); i++)
		lcd_data(c[i]);
}


void printLCD(char s[]) {
	LCD_command(1);
	LCD_Data_String(s);
}

char keypad_input(void)
{
	char value;
	do
	{
		value = keypad_getkey();
	} while (value == 0);
	while (keypad_getkey() != 0) {}
	return value;
}
