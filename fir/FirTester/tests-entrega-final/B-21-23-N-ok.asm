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
	push	dword 2
	pop	eax
	cmp	eax, byte 0
	je	near _L2
segment	.rodata
align	4
_L3:
	db	"KO", 0
align	4
segment	.text
	push	dword $_L3
segment	.rodata
align	4
_L4:
	db	"KO", 0
align	4
segment	.text
	push	dword $_L4
	call	prints
	add	esp, 4
	call	println
align	4
_L2:
segment	.rodata
align	4
_L5:
	db	"OK", 0
align	4
segment	.text
	push	dword $_L5
segment	.rodata
align	4
_L6:
	db	"OK", 0
align	4
segment	.text
	push	dword $_L6
	call	prints
	add	esp, 4
	call	println
        ;; after body 
_L1:
	leave
	ret
extern	println
extern	prints
