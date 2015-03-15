__asm void con_load(struct pcb *task)
{
	
		MOV r4,r0
		/* load next task content in IRQ stack */
		ADD sp,sp,#8
		LDMIA r4!,{r0-r3,r8,r9}
		STMIA r13!,{r0-r3,r8,r9}
		SUB SP,SP,#33
		/* update r4 - r11 context of next task */
		LDMIA r4!,{r5-r11}
		/* enter system mode */
		MSR cpsr_cxsf,#0x1F
		/* load next task stack */
		LDR R13,[R4]
		/* load LR of next task */
		LDMIA r13!,{r14}    
		/* return to IRQ mode */
		MSR cpsr_cxsf,#0x92
		
} 


__asm void task_launch(struct pcb *task)
{
	
		MOV r4,r0
		/* load next task content in IRQ stack */
		ADD sp,sp,#28
		ADD r4,r4,#20
		LDR R13,[R4]   /* load LR of next task */
		SUB SP,SP,#28
	  ADD r4,r4,#32
		/* enter system mode */
		MSR cpsr_cxsf,#0x1F
		/* load next task stack */
		LDR R13,[R4]
		/* return to IRQ mode */
		MSR cpsr_cxsf,#0x92
		
} 