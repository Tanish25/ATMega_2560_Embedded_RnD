// self-designed PWM with rough estimate of frequency


#define F_CPU 16000000//16Mhz
#define MS_DELAY 1000
#include <avr/io.h>
#include <util/delay.h>

volatile int i,j,k,l;
volatile int p,q,duty_cycle,frequency;
float x,y;
//assuming 1 delay function covers 0.01 seconds
/*void delay(void)
{
        for (i = 0; i < 1; i++)
        {
            for (j = 0; j < 100; j++)
            {
                for (k = 0; k < 100; k++);
            }
        }

}
*/    
//assuming 1 delay function covers 0.0001 seconds
void delay(void)
{
        for (i = 0; i < 1; i++)
        {
            for (j = 0; j < 10; j++)
            {
                for (k = 0; k < 10; k++);
            }
        }

}


int main (void) {
    DDRC = 0xff; 
    PORTC = 0xff;
    //Enter duty cycle in percentage(preferably integer)
    int duty_cycle=10;
    //Enter frequency in Hz(preferably integer)
    int frequency=1;
    x=duty_cycle*(1/frequency);//*(1/6);//1/6 is an adjusting factor
    y=(10-duty_cycle)*(1/frequency);//*(1/6);
    p=(int)x;
    q=(int)y;


//while(1);


    PORTC = 0x00;
//PORTC pins= pins 30-37
    while(1)
    {
        //for(int i=1;i<11;i++)
        //{
        PORTC = 0xff;
        for(l=0;l<p;l++)
        {
            delay();
        }

        PORTC = 0x00;
        for(l=0;l<q;l++)
        {
            delay();
        }//}
    
    }


}
