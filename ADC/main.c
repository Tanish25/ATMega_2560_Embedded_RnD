//ADC

#include <avr/io.h>
#define F_CPU 16000000//16MHz

int main(void)
{
	 DDRL = 0xff;//port L direction: output //pins- 49:42
     DDRC = 0xff;//port C direction: output //pins- 37:30
     //DDRA = 0x00;//port A direction: input //pins- 22:29 
     ADCSRA = 0x87;// ADC enabled and prescaler=128
     ADMUX = 0x61;// Ref= Vcc// data is left-justified //ADC0 is source pin
     while(1)
     {
        //ADIF=0 ifu wanna reset, otherwise you keep it as 1 so that conversion doesnt start again
     	//ADCSRA |= (1<<ADSC); //to start conversion, we set ADSC bit to 1
        ADCSRA |= 0x40; //ADSC=1
     	//while(ADCSRA && (1<<ADIF)==0);// waiting for conversion to finish
        while(ADIF==0);
     	PORTL = ADCL;
     	PORTC = ADCH;
     }
}