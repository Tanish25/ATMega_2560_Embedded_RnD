This program generates 6 PWM signals(3 different phases and their complementary signals). This program also includes an attempt to induce deadtime.

### Registers involved:

#### GPIO:
**DDRB**: Data Direction Register for Port B= 0xFF for output
**DDRE**: Data Direction Register for Port E= 0xFF for output


#### PWM Module:
**OCRnX[H and L]**: Output Compare Register X=Value here is compared with the Timer value,and when the value matches, the specific pin[pin OCnX] gets toggled

#### Pins involved:
##### Non-inverting pins:
output of pwm is at pin 13(OC1C)
output of pwm is at pin 12(OC1B)
output of pwm is at pin 11(OC1A)
		
##### Inverting pins:	 	
output of pwm is at pin 3(OC3C)
output of pwm is at pin 2(OC3B)
output of pwm is at pin 5(OC3A)

**TCCR1A**: Timer/Counter 1 Control Register A = 0xAB
Bit [7:6]= COM1A-Compare Output Mode A = 10-Non-inverting PWM-Clear OC1A on Compare Match
Bit [5:4]= COM1B-Compare Output Mode A = 10-Non-inverting PWM-Clear OC1B on Compare Match
Bit [3:2]= COM1C-Compare Output Mode A = 10-Non-inverting PWM-Clear OC1C on Compare Match
Bit [1:0]= WGM[1:0]- Waveform Generation Mode=11- for 10-bit non-inverting fast PWM.

**TCCR1B**: Timer/Counter 1 Control Register B = 0x0A
Bit [2:0] – CS0[2:0]-Clock Select = 010- for prescaler=8 in order to obtain frequency of 1kHz
Bit [4:3] – WGM[3:2]- Waveform Generation Mode=10- for 10-bit non-inverting fast PWM.

**TCCR3A**: Timer/Counter 2 Control Register A = 0xFF
Bit [7:6]= COM1A-Compare Output Mode A = 11-Inverting PWM-Clear OC3A on Compare Match
Bit [5:4]= COM1B-Compare Output Mode A = 11-Inverting PWM-Clear OC3B on Compare Match
Bit [3:2]= COM1C-Compare Output Mode A = 11-Inverting PWM-Clear OC3C on Compare Match
Bit [1:0]= WGM[1:0]- Waveform Generation Mode=11- for 10-bit Inverting fast PWM.

**TCCR3B**: Timer/Counter 2 Control Register B = 0x0A
Bit [2:0] – CS0[2:0]-Clock Select = 010- for prescaler=8 in order to obtain frequency of 1kHz
Bit [4:3] – WGM[3:2]- Waveform Generation Mode=10- for 10-bit Inverting fast PWM.

**The concept of Deadtime**:
One of the main problems in pulse width modulated voltage source inverter (PWM-VSI) drives is the nonlinear voltage
gain caused by non-ideal characteristics of the power inverter.
The most important nonlinearity is caused by the necessary
blanking time between top and bottom switch to avoid inverter
leg shoot-through of the DC bus circuit. The type of the switch
and pre-driver characteristics determine amount of the
necessary blank time.

**Usage of testArray(LookupTable)**:
The values in this array, resembles the samples of a sine wave. We obtain these look-up-table values from a regular sine-wave, after shifting by 1, and then scaling the amplitude to a size of 10 bits(i.e.max value-1024). The output compare register stores these values one by one at a time, and thus the corresponsding duty cycle of the PWM signal is set. The number of values in the look-up-table is 360, which correspond to the 360 samples(1 sample/degree) of 1 period of a sine wave. The index position in the look-up-table from where the values start to get loaded in OCRnX, will indicate the phase of the signal(wrt to a reference). This is how a signal of a any phase can be generated  

**Problem of using Fast PWM**:
Deadtime will be induced in only one of the edge of a signal when we use Fast PWM. We need deadtime to be induced in one of the edges for both signals, which still can be done in FAST PWM, but we cant control the position of the deadtime within a cycle, due to which, deadtime can be induced only between half of the times when rising edge of one signal and falling edge of another signal coincide. This is because of the fact that, in Fast PWM, the OCRnX and Timer registers are compared only once within a cycle of the PWM signal being generated. The problem can be solved using Phase-correct PWM mode, which is described in its corresponding program.   


for a difference of 2 decimal numbers in binary, and frequency of 1kHz, we obtain a deadtime of approx 15 microseconds
