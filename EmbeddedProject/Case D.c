
void clearTime(int t2[])
{
	printLCD("00:00");
 	scan_time(t2);
}

void invalid_time(int t2[]) {
	printLCD("invalid time");
 	delay_ms(1000);
 	clearTime(t2);
}


int scan_time(int t[]) {
    char c[5];
    t[3] = keypad_input() - '0';
    if (t[3] < 0 || t[3]>9) {
        invalid_time(t);
        return 0;
    }
    sprintf(c,"00:0%d", t[3]);
    printLCD(c);
		delay_ms(200);
		
    t[2] = keypad_input() - '0';
    if (t[2] < 0 || t[2]>9) {
        invalid_time(t);
        return 0;
    }
    sprintf(c,"00:%d%d", t[3], t[2]);
    printLCD(c);
		delay_ms(200);
		
    t[1] = keypad_input() - '0';
    if (t[1] < 0 || t[1]>9) {
        invalid_time(t);
        return 0;
    }
    sprintf(c,"0%d:%d%d", t[3], t[2], t[1]);
    printLCD(c);
		delay_ms(200);
		
    t[0] = keypad_input() - '0';
    if ((t[0] < 0 || t[0]>9) ||
        (t[1] >= 6) ||
        (t[3] == 0 && t[2] < 1) ||
        (t[3] == 3 && (t[2] != 0 || t[1] != 0 || t[0] != 0)) ||
        (t[3] > 3)) {
        invalid_time(t);
        return 0;
    }
		sprintf(c,"%d%d:%d%d", t[3], t[2], t[1], t[0]);
    printLCD(c);
    
    return 0;
}

int time_to_seconds(int t[]) {
    return t[3] * 600 + t[2] * 60 + t[1] * 10 + t[0];
}

void custom_Time()
{
    char time[5];
    int input_time[4];
    int time_in_seconds;
    printLCD("Cooking Time?");
    scan_time(input_time);
    time_in_seconds = time_to_seconds(input_time);
		while(1){
			if(SW2() && checkingDoor()){
				start_cooking(time_in_seconds);
				break;
			}
			else if (SW1()){
				clearTime(input_time);
				time_in_seconds = time_to_seconds(input_time);
		
			}
		}
}
