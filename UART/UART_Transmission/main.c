#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

#define BAUDRATE  115200L

int main(void)
{
	while(1)
	{
	//char c='A';
	//UDR0 = (uint8_t)c;
	UDR0= 0x55;
	UBRR0H = 0; //Baud rate registers
    UBRR0L = (uint8_t) (F_CPU / 16/ BAUDRATE)-1;

    /* set UART0 control and status registers (UCSR0x) */
    //UCSR0A is at its default values;
    UCSR0B |= (1 << TXEN0);//Transmitter is being enabled
    UCSR0C |= 0x06;//Transmission size = 8 bit; asynchronous transmission
    //_delay_ms(50);
	}
	return 0;
}