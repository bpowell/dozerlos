[BITS 32]

[global update_caps]
[global update_scroll]
[global update_num]

update_caps:
	xor byte [kbd_status], 4
	call update_leds
	ret

update_scroll:
	xor byte [kbd_status], 1
	call update_leds
	ret

update_num:
	xor byte [kbd_status], 2
	call update_leds
	ret

update_leds:
	push ax	

	call kbd_wait
	mov al, 0xED
	out 0x60, al
	call kbd_wait
	mov al, [kbd_status]
	out 0x60, al
	call kbd_wait

	pop ax
	ret

kbd_wait:
	  ;jmp	  $+2
	  in	  al, 0x64
	  test	  al, 1
	  jz	  .ok
	  ;jmp	  $+2
	  in	  al, 0x60
	  jmp	  kbd_wait
     .ok:
	  test	  al, 2
	  jnz	  kbd_wait
	  ret

kbd_status db 0
