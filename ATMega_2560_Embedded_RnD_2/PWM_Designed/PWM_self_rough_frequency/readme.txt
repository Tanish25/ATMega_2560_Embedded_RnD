F_CPU= 16000000= To set clock frequency as 16MHz
MS_DELAY= 1000= To set value 1000 as equivalent to 1 second

Registers Involved:
DDRC: Data Direction Register for Port C= 0xFF for output
PORTC: Port C Data Register= Data written here is observed in the corresponding output pins(Port C= pin 37:30)

Variables Involved:
int i,j,k,l= counting variables if loops are to be used
int duty_cycle= duty cycle in percentage
int frequency= frequency in integer
int time= stores reciprocal of frequency
float x,y= to store parameters to be used in delay functions
int p,q= to store values of x and y in integer format


Note of caution:
This board generally cant handle floating point values, best to avoid them. Type-casting also may or may not work, generally good to avoid.

function designed: delay()
Delay is implemented by running nested for-loops. We are using the fact that [x] blank instructions induces approximately a delay of 1.2*10^(-6) seconds