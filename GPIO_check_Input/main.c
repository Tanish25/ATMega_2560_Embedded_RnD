#include <avr/io.h>
#define F_CPU 16000000//16MHz
#include <util/delay.h>

int main(void)
{
	 DDRL &= 0xfe;//port L direction: input; pin 49
	 PORTL |= 0x01;//L01 PU resistor activated
     DDRC |= 0x01;//pin 37: pin C7 //direction: output
     while(1)
     {
     	PORTC = (PINL &= 0x01);
     }
 }