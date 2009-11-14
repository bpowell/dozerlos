#include <system.h>

void stack_trace(unsigned int MaxFrames)
{
	/*
	 *
	 * eip stores the memory address from what function called 
	 *	stack_trace. 
	 *
	 * right now I'm not sure what address ebp is pointing
	 *	to.  When jmping to it, GPF occurs.
	 *
	 * frame is the current stack frame that we are going to
	 * 	look at.  We can pull off all of the arguments
	 * 	passed to the function.
	 *
	 * args are the arguments passed to the current stack
	 *	frame.  The first argument starts at ebp[2].
	 *
	 * we just have the adress of the function calling, with
	 * 	no way to tell the actual function(s) that called 
	 *	stack_trace.  This part is a work in progress.  Idea
	 *	now is to grab a system.map of functions, similar to 
	 *	the Linux kernel.  Then check eip against the system.map
	 *	to get the function's name that called stack_trace. 
	 *
	 *
	 */

	unsigned int * ebp = &MaxFrames - 2;
	unsigned int frame;

	for(frame = 0; frame < MaxFrames; ++frame){
		unsigned int eip = ebp[1];

		if(eip==0)break;

		ebp = (unsigned int *) ebp[0];

		printk("frame = %i\teip = %x\tebp = %x\n", frame, eip, ebp);

		unsigned int arg, i;
		for(i=2; ebp[i]!=0; i++){
			printk("\tArgument %x: %x\n", i-1, ebp[i]);
		}
	}
}

