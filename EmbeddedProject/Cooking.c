
_Bool pause() {
	while(1){
		int i;
		for(i = 0; i < 100; i++){
			if(SW2() && checkingDoor()){
				GPIO_PORTF_DATA_R |= 0x0E; // turn ON LEDs
				return true;
			}
			if (SW1()){
				GPIO_PORTF_DATA_R &= ~0x0E; // turn OFF LEDs
				return false;
			}
			delay_ms(10); // wait 10ms
		}
		GPIO_PORTF_DATA_R ^= 0x0E; // Toggle the LEDs
	}
}

_Bool cooking(int delay){
	int i;
	int j;
	GPIO_PORTF_DATA_R |= 0x0E; // turn ON LEDs
	for(j = 0; j < delay; j++){
		counter(delay - j);
		for(i = 0; i < 100; i++){
			if (SW1() || !checkingDoor()){
				while(SW1());
				if (!pause()){
					LCD_command(1); // clear LCD
					return false;
				}
			}
			delay_ms(10); // wait 10ms
		}
	}
	return true;
}

void start_cooking(int cooking_time) {
	if(cooking(cooking_time)){
		FinishedCooking();
	}
	else {
		LCD_command(1); // clear LCD
	}
}

void finished_cooking(){
	int i;
	LCD_command(1); // clear LCD
	printLCD("Finished Cooking"); // print "Finished Cooking" on LCD
	GPIO_PORTE_DATA_R |= 0x20; // turn ON Buzzer
	GPIO_PORTF_DATA_R |= 0x0E; // turn ON LEDs
	for(i = 0; i < 6; i++)
	{
		GPIO_PORTF_DATA_R ^= 0x0E; // toggle LEDs
		GPIO_PORTE_DATA_R ^= 0x20; // toggle Buzzer
		delay_ms(1000); // wait 1s
	}
	GPIO_PORTF_DATA_R &= ~0x0E; // turn OFF LEDs
	GPIO_PORTE_DATA_R &= ~0x20; // turn OFF Buzzer
}

void counter(int seconds){
	int sec;
	int minute;
	char c[5];  
	LCD_command(1); // clear LCD
	minute =(int)(seconds/60) ;
	sec = seconds - 60 * minute ;
	sprintf(c,"%02d:%02d",minute, sec);
	printLCD(c); // print current time on LCD
}
