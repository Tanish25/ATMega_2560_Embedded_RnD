#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <string.h>

#define BAUDRATE  115200L

		


void uart_init(void)
{
		

		
		/* set UART0 control and status registers (UCSR0x) */
		//UCSR0A is at its default values;
		UBRR0H = 0; //Baud rate registers
		//UBRR0L = (uint8_t) (F_CPU / 16/ BAUDRATE)-1;
		UBRR0L = 8;
		UCSR0A = 0x00;
		UCSR0B = (1 << TXEN0);//Transmitter is being enabled
		UCSR0C = 0x06;//Transmission size = 8 bit; asynchronous transmission

		/* set UART1 control and status registers (UCSR1x) */
		//UCSR0A is at its default values;
		UBRR1H = 0; //Baud rate registers
		//UBRR1L = (uint8_t) (F_CPU / 16/ BAUDRATE)-1;
		UBRR1L = 8; 
		//UBRR0L = (uint8_t) (F_CPU / 16/ BAUDRATE)-1;
		UCSR1A = 0x00;
		UCSR1B = (1 << RXEN0);//Receiver is being enabled
		UCSR1C = 0x06;//Transmission size = 8 bit; asynchronous transmission
}

void uart_send(unsigned char ch)
{
	
	{
		//uint8_t dummy;
		//PORTC=0x00;
		//PORTL=0x00;
		//UCSR1A &= 0x7F;//RXC1=0
		/*
		while(UCSR1A && (1<<RXC1))
		{
			PORTC |= 0x01;
						dummy = UDR1;
		}
		*/
		
		
		
		//UCSR0B = (1 << TXEN0);
	    //UDR0 = dummy+1;
			
	    	//UDR0= 0x55;
	    	

	    	
	    	//while(RXC1==0);
	    	//while(!(UCSR1A && (1<<RXC1))); //wait until character is received
	    	
			
			//dummy = UDR1;
			//PORTL=dummy;
		
		//PORTA = dummy+2;
		//UCSR0B = (1 << TXEN0);
	    //UDR0 = dummy+1;
	    UDR0 = ch;
	    while(!UCSR0A & (1<<TXC0));

	    
		//PORTL = UCSR0A;
		
		//while(1);

	}

}
int main(void)
{
	
	uint8_t recv_data;
		//DDRC = 0xFF;//PORTC for output
		//DDRA = 0xFF;//PORTA for output
		//DDRL = 0xFF;//PORTL for output

		DDRE=0x02; // SET PE1 / TX0 as output
		DDRD=0x00;// SET PD as input (we need PD2 = RX1)

	uart_init();
	UCSR1A &= 0x7F;

	// while(1)
	// 	{
	// 		uart_send(0x12);

	// 	}
	

	while(1)
	{
		//uart_send('U');
		//_delay_us(1000);

		//Wait for char on RX1
		while(!(UCSR1A & (1<<RXC1))); //wait until character is received
		recv_data = UDR1;
		uart_send(recv_data+1);
		_delay_us(250);
		//uart_send('U');


	}

	// unsigned char str[]="AT";
	// uint8_t len=strlen(str);
	// uint8_t i=0;
	// while(1)
	// {
	// 	uart_send(str[i++]);
	// 	PORTC = 0x01;
	// 	if(i>=len)
	// 	{
	// 		//_delay_us(50);
	// 		i=0;
	// 		PORTC = 0x02;
	// 	}

	// }

		//char c='A';
		//UDR0 = (uint8_t)c;


/* Setup things here*/

	
	    
	
	    //_delay_ms(50);
	
    return 0;
}
//PORT A= 22-29; PORT C = 37-30; PORTL= 42-49
//TX0: 1
//RX1: 19



/*
//Sending strings:
unsigned char str[30]="AT";
uint8_t len=30;
uint8_t i=0;
while(1)
{
	uart_send(str[i++]);
	if(i>=len)
		i=0;

}
*/