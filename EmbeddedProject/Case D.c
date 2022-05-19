
void clearTime(int t2[])
{
    printf("00:00");
    scan_time(t2);
}

void invalid_time(int t2[]) {
    printf("invalid time");
    delay_ms(1000);
    clearTime(t2);
}

int scan_time(int t[]) {
    char c[5];
    t[3] = getch() - '0';
    if (t[3] < 0 || t[3]>9) {
        invalid_time(t);
        return 0;
    }
    sprintf(c,"00:0%d\n", t[3]);
    printLCD(c);

    t[2] = getch() - '0';
    if (t[2] < 0 || t[2]>9) {
        invalid_time(t);
        return 0;
    }
    sprintf(c,"00:%d%d\n", t[3], t[2]);
    printLCD(c);
		
    t[1] = getch() - '0';
    if (t[1] < 0 || t[1]>9) {
        invalid_time(t);
        return 0;
    }
    sprintf(c,"0%d:%d%d\n", t[3], t[2], t[1]);
    printLCD(c);
		
    t[0] = getch() - '0';
    if ((t[0] < 0 || t[0]>9) ||
        (t[1] >= 6) ||
        (t[3] == 0 && t[2] < 1) ||
        (t[3] == 3 && (t[2] != 0 || t[1] != 0 || t[0] != 0)) ||
        (t[3] > 3)) {
        invalid_time(t);
        return 0;
    }
    return 0;
}

int time_to_seconds(int t[]) {
    return t[3] * 600 + t[2] * 60 + t[1] * 10 + t[0];
}

void custom_Time(_Bool cleared)
{
    int i;
    char time[5];
    int input_time[4];
    int time_in_seconds;
    if (cleared) {
        clearTime(input_time);       //get time again with no error
    }
    else {
        printf("Cooking Time?\n");
        scan_time(input_time);
    }
    sprintf(time,"%d%d:%d%d", input_time[3], input_time[2], input_time[1], input_time[0]);
    printLCD(time);
    time_in_seconds = time_to_seconds(input_time);
		while(1){
			if(SW2() && checkingDoor()){
				//cook for time_in_seconds;
				break;
			}
			else if (SW1()){
				custom_Time(1);
				break;
			}
		}
}
