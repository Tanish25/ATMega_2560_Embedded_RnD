#define F_CPU 16000000
#define MS_DELAY 1000
#include <avr/io.h>
#include <util/delay.h>

volatile int i,j,k;
      
int main (void) {
   

	//DDRB &= 0x7F;
	//PORTB &= 0x7F;
    DDRC = 0xff; 
    PORTC = 0xff;

//while(1);


    PORTC = 0x00;
//PORTC pins= pins 30-37
    while(1)
    {
        PORTC = 0xff;
//        PORTC ^= 0xff;


        for (i = 0; i < 500; i++)
        {
            for (j = 0; j < 10; j++)
            {
                for (k = 0; k < 10; k++);
            }
        }

        PORTC = 0x00;
        //PORTB &= 0x00;
        for (i = 0; i < 500; i++)
        {
            for (j = 0; j < 10; j++)
            {
                for (k = 0; k < 10; k++);
            }
        }

        //PORTB &= 0x00;
        //PORTB |= 0x80;



    }



    	//DDRB |= ~_BV(DDB7);

      /*  while(1){ 
        //PORTB |= 0x20; 
            PORTB |= (0<<PB7) ;
        _delay_ms(1000); 
       // PORTB &= ~0x20; 
        PORTB &= ~(0<<PB7) ;
        _delay_ms(1000); 
    } */

   /*while(1) {
       //Set to one the fifth bit of PORTB to one
       // Set to HIGH the pin 13 
        PORTB |= _BV(PORTB7);

        //Wait 3000 ms 
        _delay_ms(MS_DELAY);

        //Set to zero the fifth bit of PORTB
        //Set to LOW the pin 13 
        PORTB &= _BV(PORTB7);

        //Wait 3000 ms 
        _delay_ms(MS_DELAY);
    }*/

}


/*
#include <avr/io.h>
#define F_CPU 1000000
#include <util/delay.h>

int main(void)
{
    DDRA = 0x01;
    
    while(1)
    {
        PORTA = 0x01;
        _delay_ms(1000);
        PORTA = 0x00;
        _delay_ms(1000);
    }
    
    return 0;
}

   */ 
