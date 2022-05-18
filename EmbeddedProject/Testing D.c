#include <stdio.h>
#include <stdlib.h>
void time_again(int t2[], _Bool error){
    if (error){
        printf("invalid time\n");
        //delay 1 second
    }
    printf("00:00\n");
    scan_time(t2);
}


int scan_time(int t[]){
    t[3]=getch()-'0';
    if(t[3]<0 || t[3]>9){
        time_again(t,1);
        return 0;
    }
    printf("00:0%d\n",t[3]);

    t[2]=getch()-'0';
        if(t[2]<0 || t[2]>9){
        time_again(t,1);
        return 0;
        }
    printf("00:%d%d\n",t[3],t[2]);


    t[1]=getch()-'0';
    if(t[1]<0 || t[1]>9){
        time_again(t,1);
        return 0;
    }
    printf("0%d:%d%d\n",t[3],t[2],t[1]);

    t[0]=getch()-'0';
    if((t[0]<0 || t[0]>9)||
       (t[1]>=6)||
       (t[3]==0 && t[2] < 1 )||
       (t[3]==3 && (t[2]!=0 || t[1]!=0 || t[0] !=0))||
       (t[3]>3)){
        time_again(t,1);
       return 0;
       }
    return 0;
}

int time_to_seconds(int t[]){
    return t[3]*600 + t[2]*60 + t[1]*10 + t[0];
}

int D(_Bool cleared)
{
    int i;
    int input_time[4];
    int time_in_seconds;
    if(cleared){
        time_again(input_time,0);       //get time again with no error
    }
    else {
        printf("Cooking Time?\n");
        scan_time(input_time);
    }
    printf("%d%d:%d%d\n",input_time[3],input_time[2],input_time[1],input_time[0]);

    time_in_seconds = time_to_seconds;

    /*if(sw2)
    cooking(time_in_seconds);
    return;
    if (sw1)
    D(1);
    return;*/
}

int main(){
    D(0);
}
