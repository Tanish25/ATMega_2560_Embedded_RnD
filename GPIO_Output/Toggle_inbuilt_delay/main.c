#include <avr/io.h>
#define F_CPU 16000000//16MHz
#define MS_DELAY 1000//1 second=1000 ms
#include <util/delay.h>

int main(void)
{
    //pin 37-port C0 
     DDRC = 0xff; 
    PORTC = 0xff;
    
    while(1)
    {
        PORTC = 0x01;
        _delay_ms(1000);//1 second delay
        PORTC = 0x00;
        _delay_ms(1000);//1 second delay
    }
    
    return 0;
}

//name of file is toggle_inbuilt and accordingly changes have been made in makefile
