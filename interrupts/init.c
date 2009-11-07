#include <system.h>
#include <interrupts.h>

void init_isr()
{
	add_idt(0, (unsigned) isr00, 0x08, 0x8e);
	add_idt(1, (unsigned) isr01, 0x08, 0x8e);
	add_idt(2, (unsigned) isr02, 0x08, 0x8e);
	add_idt(3, (unsigned) isr03, 0x08, 0x8e);
	add_idt(4, (unsigned) isr04, 0x08, 0x8e);
	add_idt(5, (unsigned) isr05, 0x08, 0x8e);
	add_idt(6, (unsigned) isr06, 0x08, 0x8e);
	add_idt(7, (unsigned) isr07, 0x08, 0x8e);
	add_idt(8, (unsigned) isr08, 0x08, 0x8e);
	add_idt(9, (unsigned) isr09, 0x08, 0x8e);
	add_idt(10, (unsigned) isr10, 0x08, 0x8e);
	
	add_idt(11, (unsigned) isr11, 0x08, 0x8e);
	add_idt(12, (unsigned) isr12, 0x08, 0x8e);
	add_idt(13, (unsigned) isr13, 0x08, 0x8e);
	add_idt(14, (unsigned) isr14, 0x08, 0x8e);
	add_idt(15, (unsigned) isr15, 0x08, 0x8e);
	add_idt(16, (unsigned) isr16, 0x08, 0x8e);
	add_idt(17, (unsigned) isr17, 0x08, 0x8e);
	add_idt(18, (unsigned) isr18, 0x08, 0x8e);
	
	int i;
	for(i=19; i<32; i++){
		add_idt(i, (unsigned) isr19_32, 0x08, 0x8e);
	}
}

void irq_remap()
{
	outb(0x20, 0x11);
	outb(0xA0, 0x11);
	outb(0x21, 0x20);
	outb(0xA1, 0x28);
	outb(0x21, 0x04);
	outb(0xA1, 0x02);
	outb(0x21, 0x01);
	outb(0xA1, 0x01);
	outb(0x21, 0x0);
	outb(0xA1, 0x0);
}

void init_irq()
{
	irq_remap();
	
	add_idt(32, (unsigned)irq00, 0x08, 0x8e);
	add_idt(33, (unsigned)irq01, 0x08, 0x8e);
	add_idt(34, (unsigned)irq02, 0x08, 0x8e);
	add_idt(35, (unsigned)irq03, 0x08, 0x8e);
	add_idt(36, (unsigned)irq04, 0x08, 0x8e);
	add_idt(37, (unsigned)irq05, 0x08, 0x8e);
	add_idt(38, (unsigned)irq06, 0x08, 0x8e);
	add_idt(39, (unsigned)irq07, 0x08, 0x8e);
	add_idt(40, (unsigned)irq08, 0x08, 0x8e);
	add_idt(41, (unsigned)irq09, 0x08, 0x8e);
	add_idt(42, (unsigned)irq10, 0x08, 0x8e);
	add_idt(43, (unsigned)irq11, 0x08, 0x8e);
	add_idt(44, (unsigned)irq12, 0x08, 0x8e);
	add_idt(45, (unsigned)irq13, 0x08, 0x8e);
	add_idt(46, (unsigned)irq14, 0x08, 0x8e);
	add_idt(47, (unsigned)irq15, 0x08, 0x8e);
}
