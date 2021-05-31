segment	.data
align	4
x:
segment	.rodata
align	4
_L1:
	db	"ola", 0
align	4
segment	.data
	dd	_L1
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
	push	dword $x
	pop	eax
	push	dword [eax]
	push	dword $x
	pop	eax
	push	dword [eax]
	call	prints
	add	esp, 4
	call	println
        ;; after body 
_L2:
	leave
	ret
extern	println
extern	prints
