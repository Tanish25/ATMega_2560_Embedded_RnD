#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

#define BAUDRATE  115200L



int main(void)
{

		uint8_t dummy;

		DDRC = 0xFF;//PORTC for output
		DDRA = 0xFF;//PORTA for output
		DDRL = 0xFF;//PORTL for output
		//char c='A';
		//UDR0 = (uint8_t)c;


		DDRE=0x02; // SET PE1 / TX0 as output
		DDRD=0x00;// SET PD as input (we need PD2 = RX1)

		/* set UART0 control and status registers (UCSR0x) */
		//UCSR0A is at its default values;
		UBRR0H = 0; //Baud rate registers
		//UBRR0L = (uint8_t) (F_CPU / 16/ BAUDRATE)-1;
		UBRR0L = 8;
		UCSR0A = 0x00;
		UCSR0B = (1 << TXEN0);//Transmitter is being enabled
		UCSR0B = (1 << RXEN0);//Reception enabled
		UCSR0C = 0x06;//Transmission size = 8 bit; asynchronous transmission
		UDR0= 0x05;
		dummy=UDR0;


	


/* Setup things here*/

	while(1)
	{
		PORTC=0x00;
		PORTL=0x00;
		//UCSR1A &= 0x8F;//RXC1=0
		/*
		while(UCSR1A && (1<<RXC1))
		{
			PORTC |= 0x01;
						dummy = UDR1;
		}
		*/
		
		
		
		
			UCSR0B = (1 << TXEN0);
			UDR0= dummy;
	    	
	    	

	    	PORTC = 0x01;
	    	//while(RXC1==0);
	    	while(!(UCSR0A && (1<<RXC0))); //wait until character is received
	    	PORTC = 0x02;
			
			dummy = UDR0+1;
			//PORTL=dummy;
		
		PORTA = dummy;
		//UDR0= dummy;
		//PORTL = UCSR0A;
		
		//while(1);

	}
	    
	
	    //_delay_ms(50);
	
    return 0;
}
//PORT A= 22-29; PORT C = 37-30; PORTL= 42-49