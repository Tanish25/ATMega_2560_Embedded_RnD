This program describes the implementation of a self-designed PWM with inbuilt_delay for proper measure of frequency

**F_CPU**= 16000000= To set clock frequency as 16MHz
**MS_DELAY**= 1000= To set value 1000 as equivalent to 1 second

#### Registers Involved:
**DDRC**: Data Direction Register for Port C= 0xFF for output
**PORTC**: Port C Data Register= Data written here is observed in the corresponding output pins(Port C= pin 37:30)

**Variables Involved**:
int i,j,k,l= counting variables if loops are to be used
int duty_cycle= duty cycle in percentage
int frequency= frequency in integer
int time= stores reciprocal of frequency
x,y= to store parameters to be used in delay functions
p,q= to store values of x and y in integer format


**Note of caution**:
This board generally cant handle floating point values, best to avoid them. Type-casting also may or may not work, generally good to avoid.

**Note**: This program gives an idea about how to process user-defined delay. But this value cant be used in the pre-defined delay function as it takes in only compile-time constants. This user-defined delay can be used as a parameter in functions which arent pre-defined, but in those which are mostly self-designed


in-built function used:** _delay_ms()**
This function takes in "compiler-time" constants as a parameter,which defines the delay in milliseconds 
