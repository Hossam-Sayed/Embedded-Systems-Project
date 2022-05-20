// for kaypad init
#include "io.h"
#include "stdint.h"
#include "TM4C123GH6PM.h"
void Keypad_init(void)
{
	// use port D for kaypad
	SYSCTL_RCGCGPIO_R |= 0X14 ; // enable clock for port E , C
	while((SYSCTL_PRGPIO_R & 0x14) == 0){} // wait

	GPIO_PORTC_LOCK_R   = 0x4C4F434B;			// unlock the port C
	GPIO_PORTC_CR_R     |= 0xF0 ;				//select PC4-PC7 to use

	GPIO_PORTC_AFSEL_R  &= ~(0XF0) ;				// disable the AF for C
	GPIO_PORTE_AFSEL_R  &= ~(0X0F) ;				// disable the Af for E

	GPIO_PORTC_PCTL_R   &= ~(0XFFFF0000) ;			//General perpose IO
	GPIO_PORTE_PCTL_R   &= ~(0X0000FFFF) ;			//General perpose IO

	GPIO_PORTC_AMSEL_R &= ~(0XF0);				//disable the analog
	GPIO_PORTE_AMSEL_R = ~(0X0F);				//disable the analog

	GPIO_PORTC_DEN_R    |= 0XF0 ;				// digital enable 
	GPIO_PORTE_DEN_R    |= 0x0F ;				// digital enable

	GPIO_PORTC_DIR_R    |= 0XF0 ;				// PC4-PC7 Output 
	GPIO_PORTE_DIR_R    &= ~(0X0F) ; 				// PE0-PE3 for input	

	GPIO_PORTE_PUR_R    |= 0X0F ; 				// enable pull up resistor for input switch
}

unsigned char Keypad_Read(void)
{
	unsigned char PrintedValues [4] [4] =
	{ {'1','2','3','A'} ,
	  {'4','5','6','B'} , 
	  {'7','8','9','C'} , 
	  {'*','0','#','D'} ,
	} ;
	int Row , Col , x;
	unsigned char return_value = 0xFF ;
	for( Row = 0 ; Row < 4 ; Row++ )
	{
		GPIO_PORTC_DATA_R |= 0xF0; // sat all output port PC4-PC7
		if ( Row == 0 ) {GPIO_PORTC_DATA_R &= ~(0X10);}
		
	
		else if ( Row == 1 ) {GPIO_PORTC_DATA_R &= ~(0X20);}


		else if ( Row == 2 ) {GPIO_PORTC_DATA_R &= ~(0X40);}


		else {GPIO_PORTC_DATA_R &= ~(0X80);}

		// Put delay_ms(2) here 
		
		for ( Col = 0 ; Col < 4 ; Col++ )
		{
			if ( Col == 0 ) 
			{
				GPIO_PORTE_DATA_R &= ~(0XFE);
				x = GPIO_PORTE_DATA_R;
				if (x == 0 )
				{
					return_value = PrintedValues[Row][0] ;
					break;
				}
			}
			else if (Col == 1 )
			{
				GPIO_PORTE_DATA_R &= ~(0XFD);
				x = GPIO_PORTE_DATA_R;
				if (x == 0 )
				{
					return_value = PrintedValues[Row][1] ;
					break;
				
				}
			}

			else if (Col == 2 )
			{
				GPIO_PORTE_DATA_R &= ~(0XFB);
				x = GPIO_PORTE_DATA_R;
				if (x == 0 )
				{
					return_value = PrintedValues[Row][2] ;
					break;
				}
			}
			else
			{
				GPIO_PORTE_DATA_R &= ~(0XF7);
				x = GPIO_PORTE_DATA_R;
				if (x == 0 )
				{
					return_value = PrintedValues[Row][3] ;
					break;
				}
			}
		
		if ( return_value != 0XFF )
			break ;
		if (return_value == 0XFF & Row == 3 )
			Row = 0 ;

	}
}
return return_value ;
}
