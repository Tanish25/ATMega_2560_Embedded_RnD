#include <avr/io.h>
#define F_CPU 1000000
#include <util/delay.h>

int main(void)
{
    //pin 37-port C0 
     DDRC = 0xff; 
    PORTC = 0xff;
    
    while(1)
    {
        PORTC = 0x01;
        _delay_ms(20000);
        PORTC = 0x00;
        _delay_ms(20000);
    }
    
    return 0;
}

//name of file is toggle_inbuilt and accordingly changes have been made in makefile