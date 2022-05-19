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

_Bool checkingDoor()
{
	return (GPIO_PORTE_DATA_R & 0x10);
}
