

/*************************************************************

	here we have configure RTC to generate interrupt at every 
	second. 
	we have initialized	time and date.
	in ISR routine we are reading from sysytem registers to 
	user registers 
	RTC task :
				it does copying user registers into time and 
				date arrary as per format

*************************************************************/
			



unsigned char sec=0;
unsigned char dow = 0;			//day
unsigned char min = 0;			//minute
unsigned char hour = 0;			//hour
unsigned char tim[10];
unsigned char dat[10];
unsigned short int year = 0;	//year
unsigned char month = 0;		//month
unsigned char dom = 0;			//date		
unsigned char i = 0;
unsigned char flag=0;

void rtc_init()
{
ILR=0x01;
CCR=0x11;
CIIR=1;
HOUR=10;
MIN=10;
SEC=10;
DOM=5;
MONTH=2;
YEAR=11;
}

void RTC_ISR(void)__irq
{
	sec=SEC;
	min = MIN;
	hour = HOUR;
	dow = DOW;
	year = YEAR;
	month = MONTH;
	dom = DOM;
	flag = 1;
	ILR =0x01;
	VICVectAddr = 0;

}

void rtc_int_init()
{
VICVectAddr1=(unsigned int)RTC_ISR;
VICVectCntl1=0x20| 13;
VICIntEnable|=(1<<13);
}

void rtc_task()
{
   
			
	tim[0]=((hour/10)+48);
	tim[1]=((hour%10)+48);
	tim[2]=(':');
	tim[3]=((min/10)+48);
	tim[4]=((min%10)+48);
	tim[5]=(':');
	tim[6]=((sec/10)+48);
	tim[7]=((sec%10)+48);


	dat[0]=((dom/10)+48);
	dat[1]=((dom%10)+48);
	dat[2]=('/');
	dat[3]=((month/10)+48);
	dat[4]=((month%10)+48);
	dat[5]=('/');
	dat[6]=((year/10)+48);
	dat[7]=((year%10)+48);
	
  	
		
}
