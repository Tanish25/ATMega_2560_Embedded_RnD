//UART_Test of code from book:

#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

#define BAUDRATE  115200L

int main(void)
{
		unsigned char ch;
	
		DDRC = 0xFF;//PORTC for output
		//char c='A';
		//UDR0 = (uint8_t)c;
		UDR0= 0xFF;
		UBRR0H = 0; //Baud rate registers
	    UBRR0L = (uint8_t) (F_CPU / 16/ BAUDRATE)-1;

	    /* set UART0 control and status registers (UCSR0x) */
	    //UCSR0A is at its default values;
	    UCSR0B |= (1 << TXEN0) | (1 << RXEN0);//Transmitter and receiver is being enabled
	    UCSR0C |= 0x06;//Transmission size = 8 bit; asynchronous transmission

/*
	    while(1)
	    {
	    	while(!(UCSR0A && (1<<RXC0)));//wait until character is received
	    	ch = UDR0;
	    	while(!(UCSR0A && (1<<UDRE0)));
	    	UDR0 = ch;

	    }
	*/    
	
	    //_delay_ms(50);
	
    return 0;
}
//PORT A= 22-29; PORT C = 37-30
