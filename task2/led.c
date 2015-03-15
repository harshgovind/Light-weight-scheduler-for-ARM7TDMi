void init_spi(void)
{
	PINSEL0|=0x1500;
	IODIR0|=0x80;
	S0SPCCR|=0x78;
	S0SPCR|=0x20;
}


void led_delay(void)
{
	int i;
	for(i=0;i<10000;i++);
}

