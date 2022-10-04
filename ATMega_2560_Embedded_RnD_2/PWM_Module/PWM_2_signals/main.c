#define F_CPU 16000000//16Mhz
#define MS_DELAY 1000
#include <avr/io.h>
#include <util/delay.h>
int main(void)
{
	DDRB = 0xFF;//Port B set as output
	
	OCR0A= 0xBF;//75 percent of 255=duty cycle
	TCCR0A = 0x83;
	TCCR0B = 0x03;//prescaler = 64 for 1kHz
	//output at OC0A=pin 13

	OCR2A= 0xBF;//duty cycle=  25 percent, value= 0.75*255
	TCCR2A = 0xC3;//inverting PWM
	TCCR2B = 0x04;//prescaler = 64 for 1 kHz
	//output at OC2A=pin 10

	while(1);
	
}