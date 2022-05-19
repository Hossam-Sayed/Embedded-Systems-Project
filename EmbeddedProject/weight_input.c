int weight_input()
{
    int weight;
    while(1)
    {
        //print_on_LCD("chicken weight?");
        weight=/*keypad_input()*/-'0';
        if(weight>=1 |weight<=9)
            {
                return weight;
            }
        else
        {
            //print_on_LCD("Err");
            delay_ms(2000);
        }

    }
}
