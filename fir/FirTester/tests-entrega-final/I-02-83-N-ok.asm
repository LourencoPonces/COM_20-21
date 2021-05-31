segment	.text
align	4
f:
	push	ebp
	mov	ebp, esp
	sub	esp, 0
        ;; before body 
	lea	eax, [ebp+8]
	push	eax
	pop	eax
	push	dword [eax+4]
	push	dword [eax]
	push	esp
	pop	eax
	push	dword [eax+4]
	push	dword [eax]
	push	dword $f
	pop	ecx
	pop	eax
	mov	[ecx], eax
	pop	eax
	mov	[ecx+4], eax
	add	esp, 8
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
