int main(void)
{
	char z;
	SW_inti();
	SW3Buz_init();
	keypad_init();
	Systic_int();
	LCD_init();
	LCD_command(1);
	LCD_Data_String("Besm Allah");
	while(1){
		printLCD("Enter Key:");
		z=keypad_input();
	switch (z)
	{
	case 'A':
		popcorn();
		break;

	case 'B':
		Beef();
	  break;

	case 'C':
    Chicken(); 
	  break;

	case 'D':
		custom_Time();
	  break;
	}
	}

}
