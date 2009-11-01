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
O_BOOT	= start.o
O_DRIVE	= video.o
OBJ		= $(O_BOOT) $(O_DRIVE) $(LIBOBJ)

defaults:noclean
noclean: $(OBJ) dozerl-'$(VERSION)'


#/boot files
start.o:
	$(ASM) $(AFLAGS) boot/start.asm -o start.o

#/driver files
video.o:	drivers/video.c
	$(CC) $(CFLAGS) -c drivers/video.c

#/libc
port.o: libc/port.c
	$(CC) $(CFLAGS) -c libc/port.c

string.o: libc/string.c
	$(CC) $(CFLAGS) -c libc/string.c

mem.o: libc/mem.c
	$(CC) $(CFLAGS) -c libc/mem.c

libc.a: $(LIBOBJ)
	ar rvu libc.a $(LIBOBJ)
	ranlib libc.a

#link
dozerl-'$(VERSION)': $(OBJ)
	$(LD) $(LFLAGS) -o dozerl-$(VERSION) $(OBJ)

#clean
clean:
	rm *.o
