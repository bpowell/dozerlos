#include <system.h>
#include <mem.h>

void *irq_used[16] = {
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0
};

void del_irq(int irq)
{
	irq_used[irq] = 0;
}

void add_irq(int irq, void (*handler)(struct regs *r))
{
	irq_used[irq] = handler;
}

void irq_handle(struct regs *r)
{
	void (*handler)(struct regs *r);
	
	handler = irq_used[r->num - 32];
	
	if(handler){
		handler(r);
	}
	
	if(r->num >= 40){
		outb(0xa0, 0x20);
	}
	
	outb(0x20, 0x20);
}

unsigned char *execption_msg[] = {
	"Divison By Zero",
	"Debug",
	"Non Maskable Interrupt",
	"Breakpoint",
	"Into Detected Overflow",
    "Out of Bounds",
    "Invalid Opcode",
    "No Coprocessor",

    "Double Fault",
    "Coprocessor Segment Overrun",
    "Bad TSS",
    "Segment Not Present",
    "Stack Fault",
    "General Protection Fault",
    "Page Fault",
    "Unknown Interrupt",

    "Coprocessor Fault",
    "Alignment Check",
    "Machine Check",
    "Reserved"
};

void fault_handle(struct regs *r)
{
	if(r->num < 19){
		printk("%s Exception has occured.  System Halted!!\n\n", execption_msg[r->num]);
		for(;;);
	}
}

