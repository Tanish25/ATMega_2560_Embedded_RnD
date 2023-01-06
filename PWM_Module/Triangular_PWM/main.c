//triangular PWM



#define F_CPU 16000000//16Mhz
#define MS_DELAY 1000
#include <avr/io.h>
#include <util/delay.h>
int main(void)
{
	DDRB = 0xFF;//Port B set as output
	//DDRB |= (1 <<3);//Port B(0:3) set as output
	while(1)
	{
		for(int i=0;i<10;i++)
		{
			OCR0A= 0x00 + i*25;//75 percent of 255=duty cycle
			TCCR0A = 0x83;//non-inverting pwm
			TCCR0B = 0x03;//prescaler = 64
			//output of pwm is at pin 13(OC0)
			_delay_ms(500);
		}
	}
	
	
}

//Problem with this code: The duty cycle here varies in triangular manner and isnt sinusoidal 