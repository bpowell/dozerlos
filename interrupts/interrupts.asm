;
;
; isr.asm
;
;

[BITS 32]



[global isr00]
[global isr01]
[global isr02]
[global isr03]
[global isr04]
[global isr05]
[global isr06]
[global isr07]
[global isr08]
[global isr09]
[global isr10]
[global isr11]
[global isr12]
[global isr13]
[global isr14]
[global isr15]
[global isr16]
[global isr17]
[global isr18]
[global isr19_32]

;divide by zero
isr00:
	cli
	push byte 0
	push byte 0
	jmp isr_push_regs

;debug
isr01:
	cli
	push byte 0
	push byte 1
	jmp isr_push_regs

;non maskable interrupt	
isr02:
	cli
	push byte 0
	push byte 2
	jmp isr_push_regs
	
;breakpoint
isr03:
	cli
	push byte 0
	push byte 3
	jmp isr_push_regs
	
;into detectd overflow
isr04:
	cli
	push byte 0
	push byte 4
	jmp isr_push_regs
	
;out of bounds
isr05:
	cli
	push byte 0
	push byte 5
	jmp isr_push_regs
	
;invalid opcode
isr06:
	cli
	push byte 0
	push byte 6
	jmp isr_push_regs
	
;no coprocessor
isr07:
	cli
	push byte 0
	push byte 7
	jmp isr_push_regs
	
;double fault
isr08:
	cli
	push byte 8
	jmp isr_push_regs
	
;coprocessor segment overrun
isr09:
	cli
	push byte 0
	push byte 9
	jmp isr_push_regs
	
;bad tss
isr10:
	cli
	push byte 10
	jmp isr_push_regs
	
;segment not present
isr11:
	cli
	push byte 11
	jmp isr_push_regs
	
;stack fault
isr12:
	cli
	push byte 12
	jmp isr_push_regs
	
;general protection fault
isr13:
	cli
	push byte 13
	jmp isr_push_regs
	
;page fault
isr14:
	cli
	push byte 14
	jmp isr_push_regs
	
;unknown
isr15:
	cli
	push byte 0
	push byte 15
	jmp isr_push_regs
	
;coprocessor fault
isr16:
	cli
	push byte 0
	push byte 16
	jmp isr_push_regs
	
;alignment check
isr17:
	cli
	push byte 0
	push byte 17
	jmp isr_push_regs
	
;machine check
isr18:
	cli
	push byte 0
	push byte 18
	jmp isr_push_regs
	
;reserved
isr19_32:
	cli
	push byte 0
	push byte 19
	jmp isr_push_regs

[extern fault_handle]

isr_push_regs:
	pusha
	push ds
	push es
	push fs
	push gs
	mov ax, 0x10
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	mov eax, esp
	push eax
	mov eax, fault_handle
	call eax
	pop eax
	pop gs
	pop fs
	pop es
	pop ds
	popa
	add esp, 8
	iret

;end isr

[global irq00]
[global irq01]
[global irq02]
[global irq03]
[global irq04]
[global irq05]
[global irq06]
[global irq07]
[global irq08]
[global irq09]
[global irq10]
[global irq11]
[global irq12]
[global irq13]
[global irq14]
[global irq15]

irq00:
	cli
	push byte 0
	push byte 32
	jmp irq_push_regs
	
irq01:
	cli
	push byte 0
	push byte 33
	jmp irq_push_regs
	
irq02:
	cli
	push byte 0
	push byte 34
	jmp irq_push_regs
	
irq03:
	cli
	push byte 0
	push byte 35
	jmp irq_push_regs
	
irq04:
	cli
	push byte 0
	push byte 36
	jmp irq_push_regs
	
irq05:
	cli
	push byte 0
	push byte 37
	jmp irq_push_regs
	
irq06:
	cli
	push byte 0
	push byte 38
	jmp irq_push_regs
	
irq07:
	cli
	push byte 0
	push byte 39
	jmp irq_push_regs
	
irq08:
	cli
	push byte 0
	push byte 40
	jmp irq_push_regs
	
irq09:
	cli
	push byte 0
	push byte 41
	jmp irq_push_regs
	
irq10:
	cli
	push byte 0
	push byte 42
	jmp irq_push_regs
	
irq11:
	cli
	push byte 0
	push byte 43
	jmp irq_push_regs
	
irq12:
	cli
	push byte 0
	push byte 44
	jmp irq_push_regs
	
irq13:
	cli
	push byte 0
	push byte 45
	jmp irq_push_regs
	
irq14:
	cli
	push byte 0
	push byte 46
	jmp irq_push_regs
	
irq15:
	cli
	push byte 0
	push byte 47
	jmp irq_push_regs


[extern irq_handle]

irq_push_regs:
pusha
    push ds
    push es
    push fs
    push gs

    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov eax, esp

    push eax
    mov eax, irq_handle
    call eax
    pop eax

    pop gs
    pop fs
    pop es
    pop ds
    popa
    add esp, 8
    iret
