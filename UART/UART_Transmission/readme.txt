This program is to test transmission of bits(characters) from one of the available UART Blocks

Registers involved:

UART Module:
UBBRn[H and L]: These registers together stores data which determines baudrate. The formula involved is (F_CPU / 16/ BAUDRATE)-1, in regular speed setting. BAUDRATE is rate of transmision desired by the user, in terms of bits/second. F_CPU refers to the frequency of the clock source(oscillator). 16 refers to the sampling rate for each bit.

Control and Status Registers:
UCSRnA is at its default values; 
In UCSR0B, TXEN0 is set to 1, transmitter is enabled.
UCSRnC = 0x06:
Bit [2:1] = UCSZn[1:0]= 11= size of transmission is 8-bits

Data Registers:
UDRn – USART I/O Data Register n - They store the data received or transmitted via buffer registers. The USART Transmit Data Buffer Register and USART Receive Data Buffer Registers share the same I/O address.