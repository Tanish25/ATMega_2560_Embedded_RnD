#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

#define BAUDRATE  115200L

int main(void)
{
	while(1)
	{
		DDRC = 0xFF;//PORTC for output
		//char c='A';
		//UDR0 = (uint8_t)c;
		UDR0= 0x00;
		UBRR0H = 0; //Baud rate registers
	    UBRR0L = (uint8_t) (F_CPU / 16/ BAUDRATE)-1;

	    /* set UART0 control and status registers (UCSR0x) */
	    //UCSR0A is at its default values;
	    UCSR0B |= (1 << TXEN0);//Transmitter is being enabled
	    UCSR0C |= 0x06;//Transmission size = 8 bit; asynchronous transmission

	    UBRR1H = 0; //Baud rate registers
	    UBRR1L = (uint8_t) (F_CPU / 16/ BAUDRATE)-1;

	    /* set UART0 control and status registers (UCSR0x) */
	    //UCSR1A is at its default values;
	    UCSR1B |= (1 << RXEN1);//Receiver is being enabled
	    UCSR1C |= 0x06;//Transmission size = 8 bit; asynchronous transmission
	    //while(1)
	    {
	    	while(!(UCSR1A && (1<<RXC1)));//wait until character is received
	    	//while(RXC1 bit is not 0)
	    	PORTC = UDR1;
	    }

	    /*
	      //UCSR0A is at its default values;
	    UCSR0B |= (1 << RXEN0);//Receiver is being enabled
	    UCSR0C |= 0x06;//Transmission size = 8 bit; asynchronous transmission
	    //while(1)
	    {
	    	while(!(UCSR0A && (1<<RXC0)));//wait until character is received
	    	PORTC = UDR0;

	    }
	    */
	
	    //_delay_ms(50);
	}
    return 0;
}
//PORT A= 22-29; PORT C = 37-30