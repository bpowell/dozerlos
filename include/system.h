#ifndef _SYSTEM_H_
#define _SYSTEM_H_

typedef int size_t;

//port.c functions
extern void outb(unsigned short _port, unsigned char _data);
extern unsigned char inb (unsigned short _port);

//Video.c functions
extern void cls();
extern void putch(unsigned char c);
extern void change_textcolor(int fore, int back);
extern void printk(const char *format, ...);

//idt.c functions
extern void init_idt();
extern void add_idt(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags);

//init.asm functions
extern void init_isr();
extern void init_irq();

struct regs
{
	unsigned int ds, es, fs, gs;
	unsigned int edi, esi, ebp, esp, ebx, edx, ecx, eax;
	unsigned int num, err_code;
	unsigned int eip, cs, eflags, useresp, ss;
};

//irq.c functions
extern void del_irq(int irq);
extern void add_irq(int irq,  void (*handler)(struct regs *r));

//pit.c
extern void timer_handler(struct regs *r);
extern void timer_wait(float ticks);
extern void init_timer();
extern void uptime();

#endif
