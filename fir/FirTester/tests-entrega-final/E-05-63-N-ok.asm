segment	.text
align	4
pi:
	push	ebp
	mov	ebp, esp
	sub	esp, 0
        ;; before body 
	push	dword 314
	push	dword [esp]
	push	dword $pi
	pop	ecx
	pop	eax
	mov	[ecx], eax
	add	esp, 4
        ;; after body 
_L1:
	leave
	ret
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
        ;; after body 
_L2:
	leave
	ret
