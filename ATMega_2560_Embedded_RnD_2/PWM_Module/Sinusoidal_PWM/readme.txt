Registers involved:

GPIO:
DDRB: Data Direction Register for Port B= 0xFF for output


PWM Module:
OCR0A: Output Compare Register A=Value here is compared with the Timer value,and when the value matches, the specific pin[pin OC0A(pin 13) in this case] gets toggled

TCCR0A: Timer/Counter 0 Control Register A = 0x83
Bit [7:6]= COM0A-Compare Output Mode A = 10-Non-inverting PWM-Clear OC0A on Compare Match
Bit [1:0]= WGM[1:0]- Waveform Generation Mode=11- for non-inverting fast PWM.

TCCR0B: Timer/Counter 0 Control Register B = 0x03
Bit [2:0] – CS0[2:0]-Clock Select = 011- for prescaler=64 in order to obtain frequency of 1kHz

The PWM runs in a loop with duty-cycle varying(i.e. changing value of OCR0A) such that the mean value follows a sinusoidal pattern. This function maybe helpful in AC generators.

inbuilt delay function used to induce a delay of 0.5 seconds before the duty cycle of the PWM changes

