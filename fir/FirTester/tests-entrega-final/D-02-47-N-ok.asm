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
	push	dword 0
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
	jmp	dword _L5
align	4
_L2:
	push	dword 0
	pop	eax
	cmp	eax, byte 0
	je	near _L6
segment	.rodata
align	4
_L7:
	db	"elif1", 0
align	4
segment	.text
	push	dword $_L7
segment	.rodata
align	4
_L8:
	db	"elif1", 0
align	4
segment	.text
	push	dword $_L8
	call	prints
	add	esp, 4
	call	println
	jmp	dword _L9
align	4
_L6:
	push	dword 0
	pop	eax
	cmp	eax, byte 0
	je	near _L10
segment	.rodata
align	4
_L11:
	db	"elif2", 0
align	4
segment	.text
	push	dword $_L11
segment	.rodata
align	4
_L12:
	db	"elif2", 0
align	4
segment	.text
	push	dword $_L12
	call	prints
	add	esp, 4
	call	println
	jmp	dword _L13
align	4
_L10:
	push	dword 0
	pop	eax
	cmp	eax, byte 0
	je	near _L14
segment	.rodata
align	4
_L15:
	db	"elif3", 0
align	4
segment	.text
	push	dword $_L15
segment	.rodata
align	4
_L16:
	db	"elif3", 0
align	4
segment	.text
	push	dword $_L16
	call	prints
	add	esp, 4
	call	println
	jmp	dword _L17
align	4
_L14:
	push	dword 1
	pop	eax
	cmp	eax, byte 0
	je	near _L18
segment	.rodata
align	4
_L19:
	db	"elif4", 0
align	4
segment	.text
	push	dword $_L19
segment	.rodata
align	4
_L20:
	db	"elif4", 0
align	4
segment	.text
	push	dword $_L20
	call	prints
	add	esp, 4
	call	println
	jmp	dword _L21
align	4
_L18:
segment	.rodata
align	4
_L22:
	db	"OK", 0
align	4
segment	.text
	push	dword $_L22
segment	.rodata
align	4
_L23:
	db	"OK", 0
align	4
segment	.text
	push	dword $_L23
	call	prints
	add	esp, 4
	call	println
align	4
_L21:
align	4
_L17:
align	4
_L13:
align	4
_L9:
align	4
_L5:
        ;; after body 
_L1:
	leave
	ret
extern	println
extern	prints
