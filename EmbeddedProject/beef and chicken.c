void Chicken()
{
				int weight,time;
				char c[1];
				//print_on_LCD("Chicken weight?");
				weight=weight_input('c');
        sprintf(c,"%d", weight);
				//print_on_LCD(c);
        time=weight*12;
        delay_ms(2000);
        while(1)
        {
            if(//checking_Door())
            {
                //start_cooking_time(time);
                break;
            }
            else
            {
                //print on LCD("Door open");
								delay_ms(100);
            }
    }
}

void Beef()
{
        int weight , time;
				char c[1];
				//print_on_LCD("Beef weight?");
				weight =weight_input('b');
        sprintf(c,"%d", weight);
				//print_on_LCD(c);
        time=weight*30;
        delay_ms(2000);
        while(1)
        {
            if(//checking_Door())
            {
                //start_cooking_time(time);
                break;
            }
            else
            {
                //print_on_LCD("Door open");
								delay_ms(100);
            }
        }
}
