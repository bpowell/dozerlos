#
#Makefile

VERSION 	= 00.01.05

CC 		= gcc
CFLAGS	=
ASM		= nasm
AFLAGS	= -f elf
LD		= ld
LFLAGS	= -melf_i386 -T link.ld -Ttext 0x00100000

O_BOOT	= start.o
OBJ		= $(O_BOOT)

defaults:noclean
noclean: $(OBJ) dozerl-'$(VERSION)'


#/boot files
start.o:
	$(ASM) $(AFLAGS) boot/start.asm -o start.o



#link
dozerl-'$(VERSION)': $(OBJ)
	$(LD) $(LFLAGS) -o dozerl-$(VERSION) $(OBJ)

#clean
clean:
	rm *.o
