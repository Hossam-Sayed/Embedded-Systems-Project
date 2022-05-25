
#include "prototypes.h"


void SW_inti(void){ volatile unsigned long delay;
  SYSCTL_RCGC2_R |= 0x00000020;     // 1) activate clock for Port F
  delay = SYSCTL_RCGC2_R;           // allow time for clock to start
  GPIO_PORTF_LOCK_R = 0x4C4F434B;   // 2) unlock GPIO Port F
  GPIO_PORTF_CR_R = 0x1F;           // allow changes to PF4-0
  // only PF0 needs to be unlocked, other bits can't be locked
  GPIO_PORTF_AMSEL_R = 0x00;        // 3) disable analog on PF
  GPIO_PORTF_PCTL_R = 0x00000000;   // 4) PCTL GPIO on PF4-0
  GPIO_PORTF_DIR_R = 0x0E;          // 5) PF4,PF0 in, PF3-1 out
  GPIO_PORTF_AFSEL_R = 0x00;        // 6) disable alt funct on PF7-0
  GPIO_PORTF_PUR_R = 0x11;          // enable pull-up on PF0 and PF4
  GPIO_PORTF_DEN_R = 0x1F;// 7) enable digital I/O on PF4-0
	GPIO_PORTF_DATA_R &= ~0x0E;	
}


void SW3Buz_init(void)
{
	SYSCTL_RCGCGPIO_R |=0X10; // enalbe clock
	while((SYSCTL_PRGPIO_R & 0x10) == 0){} //waiting
	GPIO_PORTE_AFSEL_R  &= ~(0X30);
	GPIO_PORTE_PCTL_R   &= ~(0X00FF0000);
	GPIO_PORTE_AMSEL_R  &= ~(0X30);
	GPIO_PORTE_DEN_R    |= 0x30 ;
	
	GPIO_PORTE_DIR_R		&= 0X10;	//SW3 E4
	GPIO_PORTE_PUR_R		|=	0X10;
	GPIO_PORTE_DIR_R		|=0X20;		//BUZ E5
}

void Systic_int()
{
NVIC_ST_CTRL_R = 0;
NVIC_ST_CTRL_R = 0x05;
}
