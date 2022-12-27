This program also generates the 6 signals required to drive the 6-phase inverter but the amplitude of average voltage and frequency is halved in order to get the reduced speed of rotation of motor.

#### Registers involved:

##### GPIO:
**DDRB**: Data Direction Register for Port B= 0xFF for output
**DDRE**: Data Direction Register for Port E= 0xFF for output


##### PWM Module:
**OCRnX[H and L]**: Output Compare Register X=Value here is compared with the Timer value,and when the value matches, the specific pin[pin OCnX] gets toggled

##### Pins involved:
**Inverting pins**:
output of pwm is at pin 13(OC1C)
output of pwm is at pin 12(OC1B)
output of pwm is at pin 11(OC1A)
		
**Non-inverting pins**:	 	
output of pwm is at pin 3(OC3C)
output of pwm is at pin 2(OC3B)
output of pwm is at pin 5(OC3A)

**TCCR3A**: Timer/Counter 3 Control Register A = 0xAB
Bit [7:6]= COM1A-Compare Output Mode A = 10-Non-inverting PWM-Clear OC1A on Compare Match
Bit [5:4]= COM1B-Compare Output Mode A = 10-Non-inverting PWM-Clear OC1B on Compare Match
Bit [3:2]= COM1C-Compare Output Mode A = 10-Non-inverting PWM-Clear OC1C on Compare Match
Bit [1:0]= WGM[1:0]- Waveform Generation Mode=11- for 10-bit non-inverting Phase-correct PWM.

**TCCR3B**: Timer/Counter 3 Control Register B = 0x02
Bit [2:0] – CS0[2:0]-Clock Select = 010- for prescaler=8 in order to obtain frequency of 1kHz
Bit [4:3] – WGM[3:2]- Waveform Generation Mode=00- for 10-bit non-inverting Phase-correct PWM.

**TCCR1A**: Timer/Counter 1 Control Register A = 0xFF
Bit [7:6]= COM1A-Compare Output Mode A = 11-Inverting PWM-Clear OC1A on Compare Match
Bit [5:4]= COM1B-Compare Output Mode A = 11-Inverting PWM-Clear OC1B on Compare Match
Bit [3:2]= COM1C-Compare Output Mode A = 11-Inverting PWM-Clear OC1C on Compare Match
Bit [1:0]= WGM[1:0]- Waveform Generation Mode=11- for 10-bit non-inverting Phase-correct PWM.

**TCCR1B**: Timer/Counter 1 Control Register B = 0x02
Bit [2:0] – CS0[2:0]-Clock Select = 010- for prescaler=8 in order to obtain frequency of 1kHz
Bit [4:3] – WGM[3:2]- Waveform Generation Mode=10- for 10-bit Inverting Phase-correct PWM.

**The concept of Deadtime**:
One of the main problems in pulse width modulated voltage source inverter (PWM-VSI) drives is the nonlinear voltage
gain caused by non-ideal characteristics of the power inverter.
The most important nonlinearity is caused by the necessary
blanking time between top and bottom switch to avoid inverter
leg shoot-through of the DC bus circuit. The type of the switch
and pre-driver characteristics determine amount of the
necessary blank time.

**Usage of testArray(LookupTable)**:
The values in this array, resembles the samples of a sine wave. We obtain these look-up-table values from a regular sine-wave, after shifting by 1, and then scaling the amplitude to a size of 10 bits(i.e.max value-1024). The output compare register stores these values one by one at a time, and thus the corresponsding duty cycle of the PWM signal is set. The number of values in the look-up-table is 360, which correspond to the 360 samples(1 sample/degree) of 1 period of a sine wave. The index position in the look-up-table from where the values start to get loaded in OCRnX, will indicate the phase of the signal(wrt to a reference). This is how a signal of any phase can be generated.
It is interesting to note that the lookup table doesnt go below a certain minimum value. This is because we want to avoid a few corner cases, where the configuration will be such that the minimum amount of deadtime cant be induced. That particular cycle will not be of significance and thus we avoid problem of shoot-through.  

**Phase-correct PWM**:
Deadtime can be induced in both the edges of a signal when we use Phase-correct PWM. In Phase-correct PWM, the OCRnX and Timer registers are compared twice within a cycle of the PWM signal being generated. The problem of fast PWM can be solved using Phase-correct PWM mode.As the register values are compared twice, delay is induced in both edges of the signal,thus making sure there is delay whenever rising edge of one signal and falling edge of another signal coincide.   

Note: for a difference of 8 decimal numbers in binary, and frequency of 1kHz, we obtain a deadtime of approx 3-4 microseconds.

**About V/f control implementation**:
The speed of rotation of the motor is directly dependent on the frequency of the rough sinusoidal signal obtained. This frequency is halved by roughly doubling the delay(from 50us to 100us) involved in between each change of duty-cycle. At the same time, we ensure voltage is also halved so that we can maintain a constant motor magnetic flux. This is necessary in order to prevent the magnetic saturation phenomenon. This is ensured by reducing the duty cycle by half, so that the overall average voltage is also halved. The result we obtain is the speed of rotation decreasing by half.  