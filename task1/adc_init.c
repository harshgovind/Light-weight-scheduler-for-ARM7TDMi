void adc_init()
{
	PINSEL1|= (1<<28);
	VPBDIV = 0x01;
	AD0CR = 0x00210f08;
	AD0CR |= (1<<24);
}

void adc_delay()			/* define delay function */
{
 unsigned int i;
 for(i=0;i<100000;i++);			/* loop for delay */
}
