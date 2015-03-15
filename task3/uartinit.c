void uart_init(void)
{
	VPBDIV=0x01	;
	PINSEL0|=0x00050000;
 	U1FDR = 0x28;
	U1LCR = 0x83;
	U1DLL = 78;
	U1LCR = 0x03;
}
