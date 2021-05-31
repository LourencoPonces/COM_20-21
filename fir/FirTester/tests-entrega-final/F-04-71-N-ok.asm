segment	.text
align	4
f:
	push	ebp
	mov	ebp, esp
	sub	esp, 0
        ;; before body 
	push	dword 5
	push	dword [esp]
	lea	eax, [ebp+8]
	push	eax
	pop	ecx
	pop	eax
	mov	[ecx], eax
	add	esp, 4
	push	dword 1
	lea	eax, [ebp+8]
	push	eax
	pop	eax
	push	dword [eax]
	pop	eax
	add	dword [esp], eax
	push	dword [esp]
	push	dword $f
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
