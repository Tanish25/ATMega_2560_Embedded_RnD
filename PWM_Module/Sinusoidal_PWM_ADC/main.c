//sinusoidal PWM using ADC(16-bit PWM to be used)



#define F_CPU 16000000//16Mhz
#define MS_DELAY 1000
#include <avr/io.h>
#include <util/delay.h>
int main(void)
{
	 DDRB = 0xFF;//Port B set as output
	 //DDRL = 0xff;//port L direction: output //pins- 49:42
     //DDRC = 0xff;//port C direction: output //pins- 37:30
     ADCSRA = 0x87;// ADC enabled and prescaler=128
     ADMUX = 0x40;// Ref= Vcc// data is right-justified //ADC0 is source pin
     while(1)
     {
        //ADIF=0 ifu wanna reset, otherwise you keep it as 1 so that conversion doesnt start again
     	//ADCSRA |= (1<<ADSC); //to start conversion, we set ADSC bit to 1
        ADCSRA |= 0x40; //ADSC=1
     	//while(ADCSRA && (1<<ADIF)==0);// waiting for conversion to finish
        while(ADIF==0);
     	OCR1AL = ADCL;
     	OCR1AH = ADCH;
     	TCCR1A = 0x83;//non-inverting pwm; mode-7: 10-bit Fast PWM
		TCCR1B = 0x10;//prescaler = 8 for frequency to be approx 2kHz
		//output of pwm is at pin 13(OC0)
		_delay_ms(50);
	 }
	
}