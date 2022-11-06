This program takes input of duty cycle via ADC. The ADC can be given a sine signal as input


Registers involved:

GPIO:
DDRB: Data Direction Register for Port B= 0xFF for output

ADC Module:
ADCSRA: ADC Control and Status Register A = 0x87
Bit 7= 1= ADC Enabled
Bit 6= ADSC: ADC Start Conversion Bit- In Single Conversion mode, write this bit to one to start each conversion.
Bit 4= ADIF: ADC Interrupt Flag- This bit is set when an ADC conversion completes and the Data Registers are updated
Bit [2:0] = 111 = Prescaler-128

ADMUX: ADC Multiplexer = 0x61
Bit [7:6] = 01 = Vref= AVcc = 5V
Bit 5 = 1 = Result(10-bits-wide) is left-justified
Bit [4:0] = 00001 = Input at ADC0

ADCL: ADC Data Register Lower= stores the lower 8 bits of result of conversion
ADCH: ADC Data Register Higher= stores the higher 8 bits of result of conversion

PWM Module:
OCRnX[H and L]: Output Compare Register X=Value here is compared with the Timer value,and when the value matches, the specific pin[pin OCnX] gets toggled

pins involved:
output of pwm is at pin 11(OC1A)

TCCR1A: Timer/Counter 1 Control Register A = 0x83
Bit [7:6]= COM1A-Compare Output Mode A = 10-Non-inverting PWM-Clear OC1A on Compare Match
Bit [1:0]= WGM[1:0]- Waveform Generation Mode=11- for 10-bit non-inverting fast PWM.

TCCR1B: Timer/Counter 1 Control Register B = 0x0A
Bit [2:0] – CS0[2:0]-Clock Select = 010- for prescaler=8 in order to obtain frequency of 1kHz
Bit [4:3] – WGM[3:2]- Waveform Generation Mode=10- for 10-bit non-inverting fast PWM.