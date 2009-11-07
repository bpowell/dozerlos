/*
/
/
/ main.c
/
/
*/

#include <system.h>

void main()
{
	init_idt();

	init_isr();
	init_irq();
	init_timer();



	int fail = 1/0;

	asm("sti");
	for(;;);
}

