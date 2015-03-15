
void init_all()
{
buz_init();
isr_init();
init_lcd();
adc_init();
rtc_init();
rtc_int_init();
uart_init();
init_spi();
//pcb_init();
}
