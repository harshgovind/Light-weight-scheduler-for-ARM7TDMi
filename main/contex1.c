__asm void con_load(struct pcb)
{
		MOV r4,[r0]
		ADD sp,sp,#4
		LDMIA r13!,{r0-r3,r12,r14}
		MOV r14,r4
		STMDB r13!,{r0-r3,r12,r14}
		SUB SP,SP,#4
}