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
