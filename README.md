## ATMega_2560_Embedded_RnD

- This repository contains the low-level C codes for configuring various in-built modules of the ATmega2560 chip. 
- The various codes have been organised folder-wise depending on the module being used.
- Each code has been associated with a readme file which has info about the pins, registers and modules, along with the concepts involved 
- Each code has been named main.c in order to run according to the configurations in the makefile.
- Makefile has been included, which is used for convenient implementation of the designed codes.
- Few references can be found in the 'resources' folder 
- For all information regarding the requirements, do refer to the file- 'AVR.md' .The AVR.md file contains information regarding how to compile and load the hex code on the Arduino Board

### List of Modules configured:
- **GPIO**: Configuration of GPIO and accessing the required registers.
- **ADC**: Analog-Digital Converter.
- **Timer/Counter**: Generation of PWM Signals whose duty cycle varies sinusoidally. Three different waves are generated in three phases, and deadtime is added in order to avoid shoot-through. 
- **USART**: Universal Serial Asynchronous Receiver Transmitter.  

