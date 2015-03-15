#include<lpc214x.h>
#include<stdio.h>
#include"head.h"

#define MAX_TASK 3


void timer_init(void);
void pcb_init();
void Timer0_isr(void)__irq;
int taskid=-1;
char id;
void (*fun[MAX_TASK])()={task1,task2,task3};


int main()
{

	timer_init();
	init_all();
	pcb_init();
	T0TCR=0x01;	 	//start timer

	while(1)
	{
	//control hand over to scheduler and scheduler takes care that control never return here 
	}

}


void timer_init(void)
{
	VPBDIV =0x01; 		     //TO HAVE SAME AS PROCESSOR CLOCK
	T0TC=0x00;			     //INITIAL COUNTER SET TO 00
	T0PR=0x00;		         //INITIAL STARTING OF CYCLE
	T0MR0=0x1D4C0;		 //60 HZ UPPER LIMIT AS 2ms SEC DELAY is   REQUIRED
	T0MCR=0X03;			     //AN INTERRUPT IS GENERATED WHE MATCHES THE VALUE IN THE TC
	VICVectAddr2=(unsigned long)Timer0_isr;
	VICVectCntl2=0x20|4;
	VICIntEnable|=0x00000010;
} 

void Timer0_isr(void)__irq
{
		
	 T0IR=1;			 //clear timer count
	 sched(&taskid);   	//call Scheduler
	 VICVectAddr=0x00000000;
	 
	 	
}

void pcb_init()
{
int i;
	
for(i=0; i<MAX_TASK; i++){
	task[i].launch=1;
	task[i].flag=0;
}
task[0].stack=0x40000100;
task[1].stack=0x40000200;
task[2].stack=0x40000300;
task[0].voldata[5]=(int)task1+4;
task[1].voldata[5]=(int)task2+4;
task[2].voldata[5]=(int)task3+4;
}



