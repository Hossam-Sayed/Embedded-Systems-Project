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
