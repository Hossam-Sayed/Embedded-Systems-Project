#include "prototype&header.h"
#include "io.h"

#include "TM4C123GH6PM.h"
#include <stdint.h>

#define RS 0x20 /* PORTA BIT5 mask */
#define RW 0x40 /* PORTA BIT6 mask */
#define EN 0x80 /* PORTA BIT7 mask */
void LCD_command(unsigned char cmnd);


void LCD_init(void)
{
SYSCTL->RCGCGPIO |= 0x01; /* enable clock to GPIOA */
while((SYSCTL->RCGCGPIO & 0x01) == 0){}	
SYSCTL->RCGCGPIO |= 0x02; /* enable clock to GPIOB */
while((SYSCTL->RCGCGPIO & 0x02) == 0){}
GPIOA->DIR |= 0xE0; /* set PORTA pin 7-5 as output for control */
GPIOA->DEN |= 0xE0; /* set PORTA pin 7-5 as digital pins */
GPIOB->DIR = 0xFF; /* set all PORTB pins as output for data */
GPIOB->DEN = 0xFF; /* set all PORTB pins as digital pins */
delay_ms(20); /* initialization sequence */
LCD_command(0x30);
delay_ms(5);
LCD_command(0x30);
delay_us(100);
LCD_command(0x30);
LCD_command(0x38); /* set 8-bit data, 2-line, 5x7 font */
LCD_command(0x06); /* move cursor right */
LCD_command(0x01); /* clear screen, move cursor to home */
LCD_command(0x0F); /* turn on display, cursor blinking */
}
void LCD_command(unsigned char cmnd)
{
GPIOA->DATA = 0; /* RS = 0, R/W = 0 */
GPIOB->DATA = cmnd;
GPIOA->DATA = EN; /* pulse E */
delay_us(0);
GPIOA->DATA = 0;
if (cmnd < 4)
delay_ms(2); /* command 1 and 2 needs up to 1.64ms */
else
delay_us(40); /* all others 40 us */
}
void lcd_data(unsigned char data)
{
GPIOA->DATA = RS; /* RS = 1, R/W = 0 */
GPIOB->DATA = data;
GPIOA->DATA = EN | RS; /* pulse E */
delay_us(0);
GPIOA->DATA = 0;
delay_us(40);
}

