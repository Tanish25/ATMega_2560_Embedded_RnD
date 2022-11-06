#define F_CPU 16000000//16Mhz
#define MS_DELAY 1000
#include <avr/io.h>
#include <util/delay.h>
int main(void)
{
	DDRB = 0xFF;//Port B set as output
	
	OCR0A= 0x7F;//50 percent of 255=duty cycle//decimal=127
	TCCR0A = 0x83;
	//TCCR0B = 0x03;//prescaler = 64 for 1kHz
	TCCR0B = 0x02;//prescaler = 8 for 8kHz
	//output at OC0A=pin 13

	//OCR2A= 0x87;//duty cycle=  47 percent, value= 0.53*255=135
	OCR2A= 0x83;//duty cycle=  48 percent, value= 0.52*255=131
	TCCR2A = 0xC3;//inverting PWM
	//TCCR2B = 0x04;//prescaler = 64 for 1 kHz
	TCCR2B = 0x02;//prescaler = 8 for 8kHz
	//output at OC2A=pin 10

	while(1);
	
}