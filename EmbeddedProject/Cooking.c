
_Bool pause() {
	while(1){
		int i;
		for(i = 0; i < 100; i++){
			if(SW2() && checkingDoor()){
				// turn ON LEDs
				return true;
			}
			if (SW1()){
				// turn OFF LEDs
				return false;
			}
			// wait 10ms
		}
		// Toggle the LEDs
	}
}

_Bool cooking(int delay){
	int i;
	// turn ON LEDs
	for(i = 0; i < delay * 100; i++){
		if (SW1() || !checkingDoor()){
			while(SW1());
			if (!pause()){
				// clear LCD
				return false;
			}
		}
		// wait 10ms
	}
	return true;
}

void start_cooking(int cooking_time) {
	if(cooking(cooking_time)){
		FinishedCooking();
	}
	else {
		// clear LCD
	}
}

void finished_cooking(){
	int i;
	// clear LCD
	// print "Finished Cooking" on LCD
	// turn ON Buzzer
	// turn ON LEDs
	for(i = 0; i < 6; i++)
	{
		// toggle LEDs
		// toggle Buzzer
		// wait 1s
	}
	// turn OFF LEDs
	// turn OFF Buzzer
}
