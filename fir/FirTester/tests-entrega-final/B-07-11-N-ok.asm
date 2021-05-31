segment	.text
align	4
global	_main:function
_main:
	push	ebp
	mov	ebp, esp
	sub	esp, 4
	push	dword 0
	lea	eax, [ebp+-4]
	push	eax
	pop	ecx
	pop	eax
	mov	[ecx], eax
        ;; before body 
	push	dword 150
	push	dword 100
	pop	ecx
	pop	eax
	cdq
	idiv	ecx
	push	edx
	push	dword 150
	push	dword 100
	pop	ecx
	pop	eax
	cdq
	idiv	ecx
	push	edx
	call	printi
	add	esp, 4
	call	println
        ;; after body 
_L1:
	leave
	ret
extern	printi
extern	println
