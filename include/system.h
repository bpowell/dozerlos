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

#endif
