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

	int fail = 1/0;

	for(;;);
}

