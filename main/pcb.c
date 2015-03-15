

struct pcb
{
int voldata[6];
int stack;
int flag;

};

int cur_task,next_task;
struct pcb task[3];


void pcb_init()
{
task[0].flag=0;
task[1].flag=0;
task[2].flag=0;
task[0].stack=0x40000100;
task[1].stack=0x40000200;
task[2].stack=0x40000300;
task[0].voldata[5]=(int)task1+4;
task[1].voldata[5]=(int)task2+4;
task[2].voldata[5]=(int)task3+4;
}