segment	.bss
align	4
f:
	resb	4
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
	push	dword 4
	lea	eax, [ebp+-8]
	push	eax
	pop	ecx
	pop	eax
	mov	[ecx], eax
	lea	eax, [ebp+-8]
	push	eax
	pop	eax
	push	dword [eax]
	push	dword 3
	pop	ecx
	sal	dword [esp], cl
	pop	eax
	sub	esp, eax
	push	esp
	lea	eax, [ebp+-12]
	push	eax
	pop	ecx
	pop	eax
	mov	[ecx], eax
	push	dword 0
	lea	eax, [ebp+-16]
	push	eax
	pop	ecx
	pop	eax
	mov	[ecx], eax
align	4
_L2:
	lea	eax, [ebp+-16]
	push	eax
	pop	eax
	push	dword [eax]
	lea	eax, [ebp+-8]
	push	eax
	pop	eax
	push	dword [eax]
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setl	cl
	mov	[esp], ecx
	pop	eax
	cmp	eax, byte 0
	je	near _L3
	push	dword 2
	fild	dword [esp]
	sub	esp, byte 4
	fstp	qword [esp]
	push	esp
	pop	eax
	push	dword [eax+4]
	push	dword [eax]
	lea	eax, [ebp+-12]
	push	eax
	pop	eax
	push	dword [eax]
	lea	eax, [ebp+-16]
	push	eax
	pop	eax
	push	dword [eax]
	push	dword 3
	pop	ecx
	sal	dword [esp], cl
	pop	eax
	add	dword [esp], eax
	pop	ecx
	pop	eax
	mov	[ecx], eax
	pop	eax
	mov	[ecx+4], eax
	add	esp, 8
	lea	eax, [ebp+-16]
	push	eax
	pop	eax
	push	dword [eax]
	push	dword 1
	pop	eax
	add	dword [esp], eax
	push	dword [esp]
	lea	eax, [ebp+-16]
	push	eax
	pop	ecx
	pop	eax
	mov	[ecx], eax
	add	esp, 4
	jmp	dword _L2
align	4
_L3:
	push	dword 0
	lea	eax, [ebp+-20]
	push	eax
	pop	ecx
	pop	eax
	mov	[ecx], eax
align	4
_L4:
	lea	eax, [ebp+-20]
	push	eax
	pop	eax
	push	dword [eax]
	lea	eax, [ebp+-8]
	push	eax
	pop	eax
	push	dword [eax]
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setl	cl
	mov	[esp], ecx
	pop	eax
	cmp	eax, byte 0
	je	near _L5
	lea	eax, [ebp+-12]
	push	eax
	pop	eax
	push	dword [eax]
	lea	eax, [ebp+-20]
	push	eax
	pop	eax
	push	dword [eax]
	push	dword 3
	pop	ecx
	sal	dword [esp], cl
	pop	eax
	add	dword [esp], eax
	pop	eax
	push	dword [eax+4]
	push	dword [eax]
	lea	eax, [ebp+-12]
	push	eax
	pop	eax
	push	dword [eax]
	lea	eax, [ebp+-20]
	push	eax
	pop	eax
	push	dword [eax]
	push	dword 3
	pop	ecx
	sal	dword [esp], cl
	pop	eax
	add	dword [esp], eax
	pop	eax
	push	dword [eax+4]
	push	dword [eax]
	call	printd
	add	esp, 8
	lea	eax, [ebp+-20]
	push	eax
	pop	eax
	push	dword [eax]
	push	dword 1
	pop	eax
	add	dword [esp], eax
	push	dword [esp]
	lea	eax, [ebp+-20]
	push	eax
	pop	ecx
	pop	eax
	mov	[ecx], eax
	add	esp, 4
	jmp	dword _L4
align	4
_L5:
segment	.rodata
align	4
_L6:
	db	10, 0
align	4
segment	.text
	push	dword $_L6
segment	.rodata
align	4
_L7:
	db	10, 0
align	4
segment	.text
	push	dword $_L7
	call	prints
	add	esp, 4
	push	dword 0
	lea	eax, [ebp+-24]
	push	eax
	pop	ecx
	pop	eax
	mov	[ecx], eax
align	4
_L8:
	lea	eax, [ebp+-24]
	push	eax
	pop	eax
	push	dword [eax]
	lea	eax, [ebp+-8]
	push	eax
	pop	eax
	push	dword [eax]
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setl	cl
	mov	[esp], ecx
	pop	eax
	cmp	eax, byte 0
	je	near _L9
	push	dword 6
	fild	dword [esp]
	sub	esp, byte 4
	fstp	qword [esp]
	lea	eax, [ebp+-12]
	push	eax
	pop	eax
	push	dword [eax]
	lea	eax, [ebp+-24]
	push	eax
	pop	eax
	push	dword [eax]
	push	dword 3
	pop	ecx
	sal	dword [esp], cl
	pop	eax
	add	dword [esp], eax
	pop	eax
	push	dword [eax+4]
	push	dword [eax]
	fld	qword [esp]
	add	esp, byte 8
	fld	qword [esp]
	fdivrp	st1
	fstp	qword [esp]
	push	esp
	pop	eax
	push	dword [eax+4]
	push	dword [eax]
	lea	eax, [ebp+-12]
	push	eax
	pop	eax
	push	dword [eax]
	lea	eax, [ebp+-24]
	push	eax
	pop	eax
	push	dword [eax]
	push	dword 3
	pop	ecx
	sal	dword [esp], cl
	pop	eax
	add	dword [esp], eax
	pop	ecx
	pop	eax
	mov	[ecx], eax
	pop	eax
	mov	[ecx+4], eax
	add	esp, 8
	lea	eax, [ebp+-24]
	push	eax
	pop	eax
	push	dword [eax]
	push	dword 1
	pop	eax
	add	dword [esp], eax
	push	dword [esp]
	lea	eax, [ebp+-24]
	push	eax
	pop	ecx
	pop	eax
	mov	[ecx], eax
	add	esp, 4
	jmp	dword _L8
align	4
_L9:
	push	dword 0
	lea	eax, [ebp+-28]
	push	eax
	pop	ecx
	pop	eax
	mov	[ecx], eax
align	4
_L10:
	lea	eax, [ebp+-28]
	push	eax
	pop	eax
	push	dword [eax]
	lea	eax, [ebp+-8]
	push	eax
	pop	eax
	push	dword [eax]
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setl	cl
	mov	[esp], ecx
	pop	eax
	cmp	eax, byte 0
	je	near _L11
	lea	eax, [ebp+-12]
	push	eax
	pop	eax
	push	dword [eax]
	lea	eax, [ebp+-28]
	push	eax
	pop	eax
	push	dword [eax]
	push	dword 3
	pop	ecx
	sal	dword [esp], cl
	pop	eax
	add	dword [esp], eax
	pop	eax
	push	dword [eax+4]
	push	dword [eax]
	lea	eax, [ebp+-12]
	push	eax
	pop	eax
	push	dword [eax]
	lea	eax, [ebp+-28]
	push	eax
	pop	eax
	push	dword [eax]
	push	dword 3
	pop	ecx
	sal	dword [esp], cl
	pop	eax
	add	dword [esp], eax
	pop	eax
	push	dword [eax+4]
	push	dword [eax]
	call	printd
	add	esp, 8
	lea	eax, [ebp+-28]
	push	eax
	pop	eax
	push	dword [eax]
	push	dword 1
	pop	eax
	add	dword [esp], eax
	push	dword [esp]
	lea	eax, [ebp+-28]
	push	eax
	pop	ecx
	pop	eax
	mov	[ecx], eax
	add	esp, 4
	jmp	dword _L10
align	4
_L11:
        ;; after body 
_L1:
	leave
	ret
extern	printd
extern	prints
