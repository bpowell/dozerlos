#
#Makefile

VERSION 	= 00.01.05

CC 		= gcc
CFLAGS	= -m32 -fno-rtti -ffreestanding -nostdlib -fno-builtin -nostartfiles -fno-exceptions -I"./include" -g3
ASM		= nasm
AFLAGS	= -f elf
LD		= ld
LFLAGS	= -melf_i386 -T link.ld -Ttext 0x00100000

LIBOBJ	= port.o string.o mem.o
O_BOOT	= start.o mboot.o
O_DRIVE	= video.o
O_INTER	= idt.o
OBJ		= $(O_BOOT) $(O_DRIVE) $(O_INTER) $(LIBOBJ)

defaults:noclean
noclean: $(OBJ) dozerl-'$(VERSION)'


#/boot files
start.o:
	$(ASM) $(AFLAGS) boot/start.asm -o start.o

mboot.o: boot/mboot.c
	$(CC) $(CFLAGS) -c boot/mboot.c

#/driver files
video.o:	drivers/video.c
	$(CC) $(CFLAGS) -c drivers/video.c

#/interrupts files
idt.o: interrupts/idt.c
	$(CC) $(CLFAGS) -c innterrupts/idt.c

#/libc
port.o: libc/port.c
	$(CC) $(CFLAGS) -c libc/port.c

string.o: libc/string.c
	$(CC) $(CFLAGS) -c libc/string.c

mem.o: libc/mem.c
	$(CC) $(CFLAGS) -c libc/mem.c

#link
dozerl-'$(VERSION)': $(OBJ)
	$(LD) $(LFLAGS) -o dozerl-$(VERSION) $(OBJ)

#clean
clean:
	rm *.o
