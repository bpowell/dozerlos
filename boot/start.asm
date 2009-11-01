;
;
;start.asm
;
;This is where we setup the information for GRUB
;the aout kludge and so forth.
;GRUB enables A20 and flips the protected mode bit 
;so we are all set with that.

[BITS 32]

jmp start

align 4
mboot:
	;Multiboot Macros for GRUB
	;these are straight from the GRUB web site
	MULTIBOOT_PAGE_ALIGN		equ 1<<0
	MULTIBOOT_MEMORY_INFO		equ 1<<1
	MULTIBOOT_AOUT_KLUDGE		equ 1<<16
	MULTIBOOT_HEADER_MAGIC		equ 0x1badb002
	MULTIBOOT_HEADER_FLAGS		equ MULTIBOOT_PAGE_ALIGN | MULTIBOOT_MEMORY_INFO | MULTIBOOT_AOUT_KLUDGE
	MULTIBOOT_CHECKSUM			equ -(MULTIBOOT_HEADER_MAGIC + MULTIBOOT_HEADER_FLAGS)
	EXTERN code, bss, end
	
	dd MULTIBOOT_HEADER_MAGIC
	dd MULTIBOOT_HEADER_FLAGS
	dd MULTIBOOT_CHECKSUM
	
	;AOUT KLUDGE
	dd mboot
	dd code
	dd bss
	dd end
	dd start

[global start]
start:
	;the multiboot information is stored in ebx and
	; eax.  push it onto the stack so our next function 
	; can grab everything that we need.
	push ebx
	push eax
	[extern mbinfo]
	call mbinfo
	
	jmp $	;hang for all time
