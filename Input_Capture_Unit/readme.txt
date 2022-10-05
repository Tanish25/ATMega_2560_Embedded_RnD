Registers involved:

GPIO:
DDRA: Data Direction Register for Port A= 0xFF for output
DDRC: Data Direction Register for Port C= 0xFF for output
PORTD: Port D Data Register= set as 0xFF to activate pull up registers

Input Capture Unit(ICU):
TCCR1A: Timer/Counter 1 Control Register A = 0x00 for normal mode of opearation 

TCCR1B: Timer/Counter 1 Control Register B = 0x41
Bit 7= ICNCn = ICU Noise Canceller= 0-Disabled
Bit 6= ICU Capture Edge select bit: when the ICESn bit is written to one, a rising (positive) edge will trigger the capture.
Bit [2:0] = 001 = Prescaler-1(i.e. no clock division)

TIFR1: Timer/Counter1 Interrupt Flag Register
Bit 5= ICF1= Timer/Counter Input Capture Flag 1
This flag is set when a capture event occurs on the ICP1 pin. When the Input Capture Register (ICR1) is set by the
WGM1[3:0] to be used as the TOP value, the ICF1 Flag is set when the counter reaches the TOP value.


ICR1L: Input Capture Register 1 Lower= stores the lower 8 bits of result
ICR1H: Input Capture Register 1 Higher= stores the higher 8 bits of result





