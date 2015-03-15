#include<lpc214x.h>
void buz_init(void);
void isr_init(void);



void EXTINT1isr(void)__irq
{
	int buz;

	EXTINT|=0x04;
	
	buz=IOPIN1;
	IOCLR1=buz&0x02000000;
	IOSET1=~buz&0x02000000;

	VICVectAddr=0x00;
	//VICIntEnClr=0x10000;
	//isr();
}


void buz_init(void)
{
	PINSEL0=0x80000000;
	 EXTMODE=0x04;
	 EXTPOLAR=0x00;

	 IODIR1=0x02000000;		/* make p1.25 as output port */
	 IOSET1=0x02000000;

}

void isr_init(void)
{
    VICVectAddr0=(unsigned long)EXTINT1isr;
	VICVectCntl0=0x30;
	VICIntEnable=0x10000;
}


