This program is to check working of input and output to a port as a whole

### Registers involved:

#### GPIO:
**DDRA**: Data Direction Register for Port A= 0xFF for output (Port A- pin 22:29)
**DDRB**: Data Direction Register for Port B= 0x00 for input (Port B- pin 53:50[B0:B3] & pin 10:13[B4:B7] ) 
**DDRC**: Data Direction Register for Port C= 0xFF for output (Port C- pin 37:30)

**PORTB**: Port B Data Register, enabling/disabling pull-up resistors

**PINB**: Port B Input Pins Address, data is read from this register

**About pull-up resistors**:
A Pull-up resistor is used to make the default state of the digital pin as High or to the logic level 1. We cannot connect the digital logic pins directly to the Logic level voltage or with the ground as a direct connection would eventually increase current flow and could damage the sensitive logic circuit which is not advisable. Hence, to control the current flow, we need to use these pull-up resistors.
 

