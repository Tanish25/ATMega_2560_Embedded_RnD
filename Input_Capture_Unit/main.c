#include <avr/io.h>
#define F_CPU 16000000//16MHz

int main(void)
{
	DDRA=0xFF;//Port A Output
	DDRC=0xFF;//Port C Output
	PORTD=0xFF;//activate pull-up//ICP1 in pin PD4= grey 47
	while(1)
	{
		TCCR1A=0x00;//Normal mode
		//TCCR1B=0x41;//rising edge, no pre-scaler, no noise canceller
		TCCR1B=0x45;//rising edge, pre-scaler is max=1024, no noise canceller
		//while(TIFR1 && (1<<ICF1)==0);//
		//TIFR1=(1<<ICF1);//clear ICF1
		while(TIFR1 && 0x20 == 0x00);//waiting for ICF1 Flag to be set
		//ICF1=0;//why not this command?
		TIFR1=(1<<ICF1);
		PORTA=ICR1L;//check output in pins 22-29(A7=29) 
		PORTC=ICR1H;//check output in pins 37-30(C0=30)	
	}
}
