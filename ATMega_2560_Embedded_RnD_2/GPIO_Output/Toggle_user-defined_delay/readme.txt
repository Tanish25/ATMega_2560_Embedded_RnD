F_CPU= 16000000= To set clock frequency as 16MHz
MS_DELAY= 1000= To set value 1000 as equivalent to 1 second

Registers Involved:
DDRC: Data Direction Register for Port C= 0xFF for output
PORTC: Port C Data Register= Data written here is observed in the corresponding output pins(Port C= pin 37:30)

delay designed: 
Delay is implemented by running nested for-loops. We are using the fact that [5*100*100 = 50000] blank instructions induces approximately a delay of 0.06 seconds