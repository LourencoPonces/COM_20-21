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
	push	dword [eax]
	lea	eax, [ebp+8]
	push	eax
	pop	eax
	push	dword [eax]
	call	prints
	add	esp, 4
	push	dword 10
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
segment	.rodata
align	4
_L3:
	db	"ola", 0
align	4
segment	.text
	push	dword $_L3
	call	f
	add	esp, 4
        ;; after body 
_L2:
	leave
	ret
extern	g
extern	prints
