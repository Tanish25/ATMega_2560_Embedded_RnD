//GPIO- Input Configuration


#include <avr/io.h>
#define F_CPU 16000000//16MHz
#include <util/delay.h>

int main(void)
{
    //pin 37-port C0 ; C7- pin 30
     DDRC = 0xff;//port C direction: output
     DDRA = 0xff;//port A direction: output
     DDRB = 0x00;//pin 10-13: Port B4 to B7 //direction: input
     //PINB = 0x00;//clearing PINB register
     //PORTA = PINB;
     //while(1);

    //enabling pull-up resistors//use=?//default output when pull-up enabled=high
    PORTB = 0xff;
    //PORTC = 0xff;
    //PORTB=0x00;//disabling pull-up resistors?//does it help or not?
    while(1)
    {
        PORTA = PINB;//PortA= pin 22-29
        if(PINB==0xFF)
        {
            PORTC = 0x01;
            _delay_ms(5);
            PORTC = 0x00;
            _delay_ms(5);
        }//f=100Hz
        else if(PINB==0x00)
        {
            PORTC = 0x01;
            _delay_ms(10);
            PORTC = 0x00;
            _delay_ms(10);
        }//f=50Hz
        /*else if(PINB==0x10)
        {
            PORTC = 0x01;
            _delay_ms(7);
            PORTC = 0x00;
            _delay_ms(7);
        }//f=approx 75Hz
         else if(PINB==0x20)
        {
            PORTC = 0x01;
            _delay_ms(20);
            PORTC = 0x00;
            _delay_ms(20);
        }//f=25Hz
        */
    }
    
    
}