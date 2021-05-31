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
	push	dword 1
	push	dword 2
	push	dword 3
	pop	eax
	imul	dword eax, [esp]
	mov	[esp], eax
	pop	eax
	add	dword [esp], eax
	push	dword 1
	push	dword 2
	push	dword 3
	pop	eax
	imul	dword eax, [esp]
	mov	[esp], eax
	pop	eax
	add	dword [esp], eax
	call	printi
	add	esp, 4
	call	println
        ;; after body 
_L1:
	leave
	ret
extern	printi
extern	println
