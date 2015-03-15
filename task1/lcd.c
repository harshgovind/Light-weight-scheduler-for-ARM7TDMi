//#include"lcd.h"

		   
void delay1(void)
{
	int i;
	for(i=0;i<100000;i++);
}

void write(unsigned char c)
{
	char ch,cl;

	ch = c & 0xf0;

	IOSET0 |= (ch<<6);
	IOCLR0 |= ~(ch<<6);

	IOSET1 |= (1<<22);
	delay1();
	IOCLR1 |= (1<<22);

	cl = c & 0x0f;

	IOSET0 |= (cl<<10);
	IOCLR0 |= ~(cl<<10);

	IOSET1 |= (1<<22);
	delay1();
	IOCLR1 |= (1<<22);
}

void init_lcd(void)
{
	PINSEL0|= 0x00;
	PINSEL1|= 0x00;
	IODIR0 |= (1<<10)|(1<<11)|(1<<12)|(1<<13);
	IODIR1 |= (1<<21)|(1<<22)|(1<<23)|(1<<24);
	IOCLR1|= (1<<23);
	IOSET1|= (1<<21);
	IOCLR1 |= (1<<22);

	IOCLR1 |= (1<<24);

	write(0x38);
	write(0x32);
	write(0x28);
	write(0x01);
	write(0x06);
	write(0x0c);
}

void lcd_ch(unsigned char c)
{
	IOSET1 |= (1<<24);
	write(c);
}

void lcd_str(unsigned char *str)
{
	while(*str!='\0')
		lcd_ch(*str++);
}		

void lcd_goto(unsigned char ps)
{
	 IOCLR1 |= (1<<24);
	 write(0x80+ps);
}
void lcd_clr(void)
{
	 IOCLR1 |= (1<<24);
	 write(0x01);
}	
	

