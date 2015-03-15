#include<lpc214x.h>
#include"led.h"
int data=0x55,dummy,temp;

/**********************************************************
	
	on blueboard LED are connected via SPI bus
	for toggeling LED we put data in S0SPDR
	and read dummy data from S0SPSR as per working of SPI

**********************************************************/	  

void task2()
{


	
	while(1)
	{
	
		
	IOCLR0|=0x80;		   

	data=~data;
	
	temp=S0SPSR;
					   	
	S0SPDR=data;
	dummy=S0SPDR;
		
	led_delay();

	IOSET0|=0x80;
	}	   
	
	

}
