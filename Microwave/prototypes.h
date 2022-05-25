#include "stdint.h"
#include <stdbool.h>
#include "string.h"
#include "stdio.h"
#include "io.h"
#include "lcd.h"

void popcorn(void);
void Chicken(void);
void Beef(void);
void custom_Time(void);
void SW_inti (void);
void Systic_int(void);
unsigned int SW1(void);
unsigned int SW2(void);
bool checkingDoor(void);
bool cooking(int delay);
void FinishedCooking(void);
void start_cooking(int cooking_time);
bool pause(void);

void printLCD(char s[]);
void counter(int seconds);
int weight_input(char s);
void clearTime(int t2[]);
void invalid_time(int t2[]);
int scan_time(int t[]);
int time_to_seconds(int t[]);


void LCD_command(unsigned char command);
void lcd_data(unsigned char data);
void LCD_init(void);
void keypad_init(void);
unsigned char keypad_getkey(void);
void store(uint32_t b);
void calculate_operand(uint8_t arr[],uint32_t c);
void error(void);
void intTochar(uint32_t y);
uint32_t charToint(uint8_t k);

void LCD_init(void);
void LCD_command(unsigned char cmnd);
void lcd_data(unsigned char data);
void LCD_Data_String(char c[]);

void delay_1ms(void);
void delay_ms(unsigned int delay);
void delay_1us(void);
void delay_us(unsigned int delay);
char keypad_input(void);
void SW3Buz_init(void);
