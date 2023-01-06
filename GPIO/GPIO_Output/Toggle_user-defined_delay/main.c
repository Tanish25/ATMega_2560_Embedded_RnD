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


        for (i = 0; i < 5; i++)
        {
            for (j = 0; j < 100; j++)
            {
                for (k = 0; k < 100; k++);
            }
        }

        PORTC = 0x00;
    
        for (i = 0; i < 5; i++)
        {
            for (j = 0; j < 100; j++)
            {
                for (k = 0; k < 100; k++);
            }
        }


    }




}
