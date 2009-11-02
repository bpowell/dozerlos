/*
/
/ idt.c
/
/
*/

#include <system.h>
#include <mem.h>

struct idt_entry{
	unsigned short base_lo;
	unsigned short sel;
	unsigned char  always0;
	unsigned char	flags;
	unsigned short	base_hi;
} __attribute__((packed));

struct idt_ptr{
	unsigned short limit;
	unsigned int base;
} __attribute__((packed));

struct idt_entry	idt[256];
struct idt_ptr		idtp;

void add_idt(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags)
{
	idt[num].base_lo = (base & 0xffff);
	idt[num].base_hi = (base >> 16) & 0xffff;
	
	idt[num].sel		= sel;
	idt[num].always0 	= 0;
	idt[num].flags		= flags;
}

void init_idt()
{
	idtp.limit = (sizeof(struct idt_entry) * 256) -1;
	idtp.base =  &idt;

	memset(&idt, 0, sizeof(struct idt_entry) * 256);

	__asm__ __volatile__  ("lidt %0 ":: "m"  (idtp) );

}

