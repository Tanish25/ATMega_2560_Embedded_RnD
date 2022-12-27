This program is an attempt to induce deadtime between 2 complementary PWM signals using Fast PWM.

#### Registers involved:

##### GPIO:
**DDRB**: Data Direction Register for Port B= 0xFF for output


##### PWM Module:
**OCR0A**: Output Compare Register A=Value here is compared with the Timer value,and when the value matches, the specific pin[pin OC0A(pin 13) in this case] gets toggled

**TCCR0A**: Timer/Counter 0 Control Register A = 0x83
Bit [7:6]= COM0A-Compare Output Mode A = 10-Non-inverting PWM-Clear OC0A on Compare Match
Bit [1:0]= WGM[1:0]- Waveform Generation Mode=11- for non-inverting fast PWM.

**TCCR0B**: Timer/Counter 0 Control Register B = 0x03
Bit [2:0] – CS0[2:0]-Clock Select = 011- for prescaler=64 in order to obtain frequency of 1kHz

**OCR2A**: Output Compare Register A=Value here is compared with the Timer value,and when the value matches, the specific pin[pin OC2A(pin 10) in this case] gets toggled. The value given here is such that the duty cycle is 47 percent, a little less than 50 percent. This change in duty cycle is done in order to induce deadtime in the inverted signal.

**TCCR2A**: Timer/Counter 2 Control Register A = 0xC3
Bit [7:6]= COM0A-Compare Output Mode A = 11-Inverting PWM-Clear OC2A on Compare Match
Bit [1:0]= WGM[1:0]- Waveform Generation Mode=11- for fast PWM.

**TCCR2B**: Timer/Counter 2 Control Register B = 0x04
Bit [2:0] – CS0[2:0]-Clock Select = 100- for prescaler=64 in order to obtain frequency of 1kHz

**The concept of Deadtime**:
One of the main problems in pulse width modulated voltage source inverter (PWM-VSI) drives is the nonlinear voltage
gain caused by non-ideal characteristics of the power inverter.
The most important nonlinearity is caused by the necessary
blanking time between top and bottom switch to avoid inverter
leg shoot-through of the DC bus circuit. The type of the switch
and pre-driver characteristics determine amount of the
necessary blank time.

for a difference of 2 decimal numbers in binary, and frequency of 8kHz, we obtain a deadtime of 1.5 microseconds

**Note**: deadtime cant be induced in both the signals using Fast PWM. This is because we can control only one of the edges using Fast PWM but we need to control both edges in order to induce deadtime in both signals. Thus, phase-correct PWM is preferred.