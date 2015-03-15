void buz_init(void)
{
	PINSEL0=0x80000000;
	 EXTMODE=0x04;
	 EXTPOLAR=0x00;

	 IODIR1=0x02000000;		/* make p1.25 as output port */
	 IOSET1=0x02000000;

}

