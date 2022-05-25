#include "prototypes.h"


void popcorn()
{
	printLCD("Popcorn");
	while(1){
		if(SW2() && checkingDoor())
		{
			printLCD("test1");
			start_cooking(60);
			break;
		}
		else if(SW1()){
			LCD_command(1);
			break;
		}
	}
}


