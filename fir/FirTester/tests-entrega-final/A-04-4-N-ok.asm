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
_L2:
	db	"xYz", 0
align	4
segment	.text
	push	dword $_L2
segment	.rodata
align	4
_L3:
	db	"xYz", 0
align	4
segment	.text
	push	dword $_L3
	call	prints
	add	esp, 4
	call	println
        ;; after body 
_L1:
	leave
	ret
extern	println
extern	prints
