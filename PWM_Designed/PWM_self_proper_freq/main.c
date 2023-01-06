// self-designed PWM with inbuilt_delay for proper measure of frequency


#define F_CPU 16000000//16Mhz
#define MS_DELAY 1000
#include <avr/io.h>
#include <util/delay.h>

int i,j,k,l;
int p,q,duty_cycle,frequency;
int time;
float x,y;

  
int main (void) {
    DDRC = 0xff; 
    PORTC = 0xff;
    //Enter duty cycle in percentage(preferably integer)
    int duty_cycle=50;
    //Enter frequency in Hz(preferably integer)
    int frequency=1;
    //computing time-period in seconds
    time=1000/frequency;
    x=duty_cycle*time*0.01;
    y=(100-duty_cycle)*time*0.01;
    p=(int)x;
    q=(int)y;
    


//while(1);


    PORTC = 0x00;
//PORTC pins= pins 30-37
    while(1)
    {
        
        PORTC = 0xff;
       _delay_ms(1); //_delay_ms(p);

        PORTC = 0x00;
        _delay_ms(1); //_delay_ms(q);
    
    }


}

//given that we need a compile-time constant for delay_ms, user-defined input can't be used in this program