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
O_BOOT	= start.o mboot.o gdt.o
O_DRIVE	= video.o pit.o keyboard.o update_keys.o
O_INTER	= idt.o interrupts.o init.o handler.o
OBJ		= $(O_BOOT) $(O_DRIVE) $(O_INTER) $(LIBOBJ) main.o

defaults:noclean
noclean: $(OBJ) dozerl-'$(VERSION)'

#/kernel
main.o: kernel/main.c
	$(CC) $(CFLAGS) -c kernel/main.c

#/boot files
start.o:
	$(ASM) $(AFLAGS) boot/start.asm -o start.o

mboot.o: boot/mboot.c
	$(CC) $(CFLAGS) -c boot/mboot.c

gdt.o: boot/gdt.asm
	$(ASM) $(AFLAGS) boot/gdt.asm -o gdt.o

#/driver files
video.o:	drivers/video.c
	$(CC) $(CFLAGS) -c drivers/video.c

pit.o:	drivers/pit.c
	$(CC) $(CFLAGS) -c drivers/pit.c

keyboard.o:	drivers/keyboard.c
	$(CC) $(CFLAGS) -c drivers/keyboard.c

update_keys.o:	drivers/update_keys.asm
	$(ASM) $(AFLAGS) drivers/update_keys.asm -o update_keys.o

#/interrupts files
idt.o: interrupts/idt.c
	$(CC) $(CFLAGS) -c interrupts/idt.c

interrupts.o: interrupts/interrupts.asm
	$(ASM) $(AFLAGS) interrupts/interrupts.asm -o interrupts.o

init.o: interrupts/init.c
	$(CC) $(CFLAGS) -c interrupts/init.c

handler.o: interrupts/handler.c
	$(CC) $(CFLAGS) -c interrupts/handler.c

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
