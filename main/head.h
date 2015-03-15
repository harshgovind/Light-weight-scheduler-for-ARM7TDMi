#include "../task1/task1.c"
#include "../task2/task2.c"
#include "../task3/task3.c"
#include "../isr1/buz_init.h"
#include "init_all.c"
//#include "pcb_init.c"
#include"sched.c"

//void pcb_init();
void init_all(void);
void task1(void);
void task2(void);
void task3(void);
 void sched(int*);
