#include<lpc214x.h>
#include<stdio.h>
#include"uart_init.h"
#include "rtc.h"

/**************************************************************

	this task block for request from user.
	upon request it check for whether choice is date or time
	accordingly it prints time or date from RTC registers

	The U1LSR is a read-only register that provides status 
	information on the UART1 TX and	RX blocks.
	we monitor 1st bit for
			0=U1RBR is empty.
			1=U1RBR contains valid data.
	we monitor 2nd bit for
			0=U1THR contains valid data
			1=U1THR is empty.
	U1RBR hold serial data.

**************************************************************/


void task3()
{
	extern int taskid;
	extern unsigned char tim[10],dat[10];
	char data;
	
			
	while(1)
	{
		
		while(!(U1LSR & 0x01)&& taskid==2);
			
		data=U1RBR;
		rtc_task();
		
		switch(data)
		{
			case 't':
			case 'T':
						i=0;
						while(tim[i])
						{

							while(!(U1LSR & 0x20));				
							U1THR=tim[i];
							i++;
						} 
						break;

			case 'd':
			case 'D':
						i=0;
						while(dat[i])
		 				{				
							while(!(U1LSR & 0x20));
							U1THR=dat[i];
							i++;
						} 
						break; 

		 }
     }
}
