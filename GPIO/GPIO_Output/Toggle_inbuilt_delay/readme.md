This program is to toggle the output using an inbuilt-delay function

**F_CPU**= 16000000= To set clock frequency as 16MHz
**MS_DELAY**= 1000= To set value 1000 as equivalent to 1 second

#### Registers Involved:
**DDRC**: Data Direction Register for Port C= 0xFF for output
**PORTC**: Port C Data Register= Data written here is observed in the corresponding output pins(Port C= pin 37:30)

in-built function used: **_delay_ms()**
This function takes in "compiler-time" constants as a parameter,which defines the delay in milliseconds 
