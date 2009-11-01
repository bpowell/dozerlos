[BITS 32]

[global load_gdt]
load_gdt:
	lgdt[GDTR]				;loads the gdt
	mov ax, DATASEL
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	mov ss, ax
	mov sp, 0xffff
	
	jmp CODESEL:switch
	
switch:
	[extern main]
	;call main
	hlt
	
;GDT section
GDTR:
	GDTsize		dw GDT_END - GDT - 1
	GDTbase		dd GDT

GDT:
	NULL_SEL	equ $-GDT
		dd 0x0
		dd 0x0
	
	CODESEL		equ $-GDT
		dw 0xffff
		dw 0x0
		db 0x0
		db 0x9a
		db 0xcf
		db 0x0
		
	DATASEL		equ $-GDT
		dw 0xffff
		dw 0x0
		db 0x0
		db 0x92
		db 0xcf
		db 0x0
		
GDT_END:
