void isr_init(void)
{
    VICVectAddr0=(unsigned long)EXTINT1isr;
	VICVectCntl0=0x30;
	VICIntEnable=0x10000;
}
