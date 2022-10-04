//ADC

#include <avr/io.h>
#define F_CPU 16000000//16MHz

int main(void)
{
	 DDRL = 0xff;//port L direction: output //pins- 49:42
     DDRC = 0xff;//port C direction: output //pins- 37:30
     DDRA = 0x00;//port A direction: input //pins- 22:29 
     ADCSRA = 0x87;// ADC enabled and prescaler=128
     ADMUX = 0xC0;// input at ADC0// data is right-justified
     while(1)
     {
     	ADCSRA |= (1<<ADSC); //to start conversion
     	while(ADCSRA && (1<<ADIF)==0);// waiting for conversion to finish
     	PORTL = ADCL;
     	PORTC = ADCH;
     }
}