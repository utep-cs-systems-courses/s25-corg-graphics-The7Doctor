.arch msp430g2553
	.global delay
	.extern delayCycles
delay:
	mov #0, r15		;i = 0
	mov r12, r14	;milliseconds

top:
	cmp r14, r15
	jc out
	call #delayCycles
	add #1, r15
	jmp top
out:	
	ret
	
	
