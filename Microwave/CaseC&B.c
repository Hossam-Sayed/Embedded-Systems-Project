
#include "prototypes.h"

void Chicken()
{
				int weight,time;
				char c[1];
				printLCD("Chicken weight?");
				weight=weight_input('c');
        sprintf(c,"%d", weight);
				printLCD(c);
        time=weight*12;
        delay_ms(2000);
        while(1)
        {
            if(checkingDoor())
            {
                start_cooking(time);
                break;
            }
            else
            {
                printLCD("Door open");
								delay_ms(100);
            }
    }
}

void Beef()
{
        int weight , time;
				char c[1];
				printLCD("Beef weight?");
				weight = weight_input('b');
        sprintf(c,"%d", weight);
				printLCD(c);
        time=weight*30;
        delay_ms(2000);
        while(1)
        {
            if(checkingDoor())
            {
                start_cooking(time);
                break;
            }
            else
            {
                printLCD("Door open");
								delay_ms(100);
            }
        }
}



int weight_input(char s)
{
    int weight;
    while(1)
    {
			weight = keypad_input() - '0';
			if(weight < 1 || weight > 9)
			{
				printLCD("Err");
				delay_ms(2000);
				if(s=='c')
					printLCD("Chicken Weight?");
				else
					printLCD("Beef Weight?");
			}
			else
			{
				return weight;
			}
	
    }
}
