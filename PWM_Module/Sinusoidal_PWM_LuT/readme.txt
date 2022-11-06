Registers involved:

GPIO:
DDRB: Data Direction Register for Port B= 0xFF for output

PWM Module:
OCRnX[H and L]: Output Compare Register X=Value here is compared with the Timer value,and when the value matches, the specific pin[pin OCnX] gets toggled

pins involved:
output of pwm is at pin 13(OC0A)

TCCR0A: Timer/Counter 0 Control Register A = 0x83
Bit [7:6]= COM1A-Compare Output Mode A = 10-Non-inverting PWM-Clear OC0A on Compare Match
Bit [1:0]= WGM[1:0]- Waveform Generation Mode=11- for 8-bit non-inverting fast PWM.

TCCR0B: Timer/Counter 0 Control Register B = 0x03
Bit [2:0] – CS0[2:0]-Clock Select = 011- for prescaler=64 in order to obtain frequency of 1kHz
Bit [3] – WGM[2]- Waveform Generation Mode=0- for 8-bit non-inverting fast PWM.

Usage of testArray(LookupTable):
The values in this array, resembles the samples of a sine wave. We obtain these look-up-table values from a regular sine-wave, after shifting by 1, and then scaling the amplitude to a size of 8 bits(i.e.max value-256). The output compare register stores these values one by one at a time, and thus the corresponsding duty cycle of the PWM signal is set. The number of values in the look-up-table is 360, which correspond to the 360 samples(1 sample/degree) of 1 period of a sine wave. The index position in the look-up-table from where the values start to get loaded in OCRnX, will indicate the phase of the signal(wrt to a reference). This is how a signal of a any phase can be generated  
