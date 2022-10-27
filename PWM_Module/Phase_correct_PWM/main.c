#define F_CPU 16000000//16Mhz
#define MS_DELAY 1000
#include <avr/io.h>
#include <util/delay.h>
int main(void)
{

static uint16_t testArray[360]={512,521,530,539,548,557,566,574,
583,592,601,610,618,627,636,645,
653,662,670,679,687,695,704,712,
720,728,736,744,752,760,768,776,
783,791,798,806,813,820,827,834,
841,848,855,861,868,874,880,886,
892,898,904,910,915,921,926,931,
936,941,946,951,955,960,964,968,
972,976,980,983,987,990,993,996,
999,1002,1004,1007,1009,1011,1013,1015,
1016,1018,1019,1020,1021,1022,1023,1023,
1024,1024,1024,1024,1024,1023,1023,1022,
1021,1020,1019,1018,1016,1015,1013,1011,
1009,1007,1004,1002,999,996,993,990,
987,983,980,976,972,968,964,960,
955,951,946,941,936,931,926,921,
915,910,904,898,892,886,880,874,
868,861,855,848,841,834,827,820,
813,806,798,791,783,776,768,760,
752,744,736,728,720,712,704,695,
687,679,670,662,653,645,636,627,
618,610,601,592,583,574,566,557,
548,539,530,521,512,503,494,485,
476,467,458,450,441,432,423,414,
406,397,388,379,371,362,354,345,
337,329,320,312,304,296,288,280,
272,264,256,248,241,233,226,218,
211,204,197,190,183,176,169,163,
156,150,144,138,132,126,120,114,
109,103,98,93,88,83,78,73,
69,64,60,56,52,48,44,41,
37,34,31,28,25,22,20,17,
15,13,11,9,8,6,5,4,
3,2,1,1,0,0,0,0,
0,1,1,2,3,4,5,6,
8,9,11,13,15,17,20,22,
25,28,31,34,37,41,44,48,
52,56,60,64,69,73,78,83,
88,93,98,103,109,114,120,126,
132,138,144,150,156,163,169,176,
183,190,197,204,211,218,226,233,
241,248,256,264,272,280,288,296,
304,312,320,329,337,345,354,362,
371,379,388,397,406,414,423,432,
441,450,458,467,476,485,494,503};
	DDRB = 0xFF;//Port B set as output
	DDRE = 0xFF;//Port E set as output for complementary PWM pins
	 	
	
	TCCR1A = 0xFF;//inverting pwm; mode-3: 10-bit phase-correct(dual-slope) PWM
	TCCR1B = 0x02;//prescaler = 8 for frequency to be approx 1kHz

	TCCR3A = 0xAB;//non-inverting pwm; mode-3: 10-bit phase-correct(dual-slope) PWM
	TCCR3B = 0x02;//prescaler = 8 for frequency to be approx 1kHz

	//output of pwm is at pin 13(OC1C)//inverting
	//output of pwm is at pin 12(OC1B)//inverting
	//output of pwm is at pin 11(OC1A)//inverting
		

		//Output of complementary pins:	 	
	//output of pwm is at pin 3(OC3C)//non-inverting
	//output of pwm is at pin 2(OC3B)//non-inverting
	//output of pwm is at pin 5(OC3A)//non-inverting


	//-n is to induce deadtime

	while(1)
	{
		for(int i=0;i<360;i++)
		{
			OCR1AL= testArray[i];
			OCR1AH=testArray[i]>>8;
			if((i+120)>359)
			{
			OCR1CL =  testArray[i+120-360];
     		OCR1CH =  testArray[i+120-360]>>8;
			}
			else
			{
			OCR1CL =  testArray[i+120];
     		OCR1CH =  testArray[i+120]>>8;
			}
			if((i+240)>359)
			{
			OCR1BL =  testArray[i+240-360];
     		OCR1BH =  testArray[i+240-360]>>8;
			}
			else
			{
			OCR1BL =  testArray[i+240];
     		OCR1BH =  testArray[i+240]>>8;
			}


			if(testArray[i]>7)
			{
			OCR3AL= testArray[i]-8;
			OCR3AH=(testArray[i]-8)>>8;
			}
			else
			{
			OCR3AL= testArray[i];
			OCR3AH=testArray[i]>>8;
			}
			if((i+120)>359)
			{
				if(testArray[i+120-360]>7)
				{
				OCR3CL =  testArray[i+120-360]-8;
	     		OCR3CH =  (testArray[i+120-360]-8)>>8;
	     		}
	     		else
	     		{
				OCR3CL =  testArray[i+120-360];
	     		OCR3CH =  testArray[i+120-360]>>8;
	     		}
			}
			else
			{
				if(testArray[i+120]>7)
				{
				OCR3CL =  testArray[i+120]-8;
	     		OCR3CH =  (testArray[i+120]-8)>>8;
	     		}
	     		else
	     		{
				OCR3CL =  testArray[i+120];
	     		OCR3CH =  testArray[i+120]>>8;
	     		}
			}
			if((i+240)>359)
			{
				if(testArray[i+240-360]>7)
				{
				OCR3BL =  testArray[i+240-360]-8;
	     		OCR3BH =  (testArray[i+240-360]-8)>>8;
	     		}
	     		else
	     		{
				OCR3BL =  testArray[i+240-360];
	     		OCR3BH =  testArray[i+240-360]>>8;
	     		}
			}
			else
			{
				if(testArray[i+240]>7)
				{
				OCR3BL =  testArray[i+240]-8;
	     		OCR3BH =  (testArray[i+240]-8)>>8;
	     		}
	     		else
	     		{
				OCR3BL =  testArray[i+240];
	     		OCR3BH =  testArray[i+240]>>8;
	     		}
			}
			//_delay_ms(10);
			_delay_us(50);

	
		}
	}
}
