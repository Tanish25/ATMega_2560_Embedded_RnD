Registers involved:

GPIO:
DDRL: Data Direction Register for Port L= 0xFF for output
DDRC: Data Direction Register for Port C= 0xFF for output   

ADC:
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
