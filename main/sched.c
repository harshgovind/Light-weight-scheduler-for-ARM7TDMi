
struct pcb
{
int voldata[6];
int r4_r11[7];
int stack;
int launch;
int flag;

};

#include"save.c"
#include"load.c"


int cur_task,next_task;
struct pcb task[3];

void sched(int *taskid)
{
	if(*taskid==-1)
	{

		++*taskid;
		next_task=*taskid;
		//fun[*taskid]();
		task_launch(&task[next_task]);
	}			 
	else
	{
		cur_task=*taskid;
		++*taskid;
 		if(*taskid==3)
		*taskid=0;
		next_task=*taskid;
		con_save(&task[cur_task]);
		if(task[cur_task].launch){
				task_launch(&task[cur_task]);
				task[cur_task].launch = 0;
		}
		else
				con_load(&task[next_task]);
	}
}


