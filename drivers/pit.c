#include <system.h>

int timer_ticks = 0;
int secs;

void timer_handler(struct regs *r)
{
	timer_ticks++;
 
	if(timer_ticks % 18 == 0)
	{
		//printk("One second has passed\n");
		secs++;
	}
}

void timer_wait(float ticks)
{
	unsigned long eticks;

	eticks = timer_ticks + ticks;
	while(timer_ticks < eticks);
}

void init_timer()
{
	add_irq(0, timer_handler);
}

void uptime()
{
	printk("Uptime: %d seconds\n", secs);
}

