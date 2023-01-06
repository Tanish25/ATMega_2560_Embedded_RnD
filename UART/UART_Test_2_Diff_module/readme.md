This program is to test transmission of bits(characters) from one of the available UART modules and receive the same in another UART module.

### Registers involved:

#### GPIO:
**DDRA**: Data Direction Register for Port A= 0xFF for output (Port A- pin 22:29)
**DDRL**: Data Direction Register for Port B= 0xFF for output (Port L- pin 49:42) 
**DDRC**: Data Direction Register for Port C= 0xFF for output (Port C- pin 37:30)
**DDRE**: Data Direction Register for Port C= 0x02 for output (pinE1 = Tx0)
**DDRD**: Data Direction Register for Port C= 0x00 for input (Port D- pin 21:14)

#### UART Module:
**UBBRn[H and L]**: These registers together stores data which determines baudrate. The formula involved is (F_CPU / 16/ BAUDRATE)-1, in regular speed setting. BAUDRATE is rate of transmision desired by the user, in terms of bits/second. F_CPU refers to the frequency of the clock source(oscillator). 16 refers to the sampling rate for each bit.

#### Control and Status Registers:
**UCSRnA** is at its default values; 
In **UCSR0B**, TXEN0 is set to 1, transmitter is enabled.
**UCSRnC** = 0x06:
Bit [2:1] = UCSZn[1:0]= 11= size of transmission is 8-bits

In **UCSR1B**, RXEN1 is set to 1, receiver is enabled.

#### Data Registers:
**UDRn** – USART I/O Data Register n - They store the data received or transmitted via buffer registers. The USART Transmit Data Buffer Register and USART Receive Data Buffer Registers share the same I/O address.