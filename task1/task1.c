#include<lpc214x.h>
#include<stdio.h>
#include"lcd.h"
#include"adc.h"

/******************************************************************
	
   this task monitors last bit of AD0DR3 for new data availability
   On blueboard we have 10 bit ADC, converted 10 bit data available
   in last 10 bit of AD0DR3
   that data converted into string and send to LCD display

*******************************************************************/


void task1()
{
    
   	unsigned int data=0;
	unsigned char t[3];
	
		while(1)
		{    
	    	while((AD0DR3 & 0x80000000) == 0);
			data = AD0DR3;
			data = (data>>6);
			data = data & 0x000003ff;
			lcd_goto(3);
			lcd_str("data");
			sprintf(t,"%d",data);
			lcd_str(t);
			data =0;
			adc_delay();
		}
	 
}
