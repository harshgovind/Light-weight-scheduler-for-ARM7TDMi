
/****************************************************************

	 on bluebord buzzer conected to  p1.25,IO1DIR is used set 
	 corrosponding pin as o/p.
	 we configure EXTINT as falling edge sensitive
	 in ISR we are clearing P1.25 to start buzzer and set p1.25 
	 to stop buzzer

*****************************************************************/




void EXTINT1isr(void)__irq
{
	int buz;

	EXTINT|=0x04;
	
	buz=IOPIN1;
	IOCLR1|=buz&0x02000000;
	IOSET1|=~buz&0x02000000;

	VICVectAddr=0x00;
	
}


void buz_init(void)
{
	 // interrupt pin configure 
	
	 PINSEL0|=0x80000000; //pin function selection
	 EXTMODE=0x04;   // EXTINT2 edge sensetive
	 EXTPOLAR=0x00;   // polarity

	// buzzer pin config
	
	 IODIR1|=0x02000000;	// i/o direction for buzzer	
	 IOSET1|=0x02000000;  // active low buzzer

}

void isr_init(void)
{
   VICVectAddr0=(unsigned long)EXTINT1isr;
	 VICVectCntl0=0x30;
	 VICIntEnable|=0x10000;
}


