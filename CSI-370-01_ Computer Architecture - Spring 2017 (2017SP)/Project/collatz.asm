; Kevin Blum
; Final Project Collatz
; CSI-370-01
; Assembly Code 32-bit MASM

.686
.MODEL flat, C
.STACK 4096

_getDouble PROTO
_getInt PROTO
_printInt PROTO
_printString PROTO
_printDouble PROTO
_clockStart PROTO
_clockEnd PROTO

.DATA
collatzString BYTE "Enter the integer for Collatz: ",0
collatzStrCount BYTE "The input reached one after step ",0
collatzInvalid BYTE "The input was invalid",0
collatz DWORD ?
collatzCounter DWORD 0

.CODE
_asmCollatz PROC
	
	push ebp
	mov ebp, esp

	lea eax, collatzString
	push eax
	call _printString
	add esp, 4

	call _getInt
	mov collatz, eax

	cmp collatz, 0
	jz endInvalid
	call _clockStart
	xor eax, eax
	mov ebx, 2
	xor edx, edx

	begin:
	cmp collatz, 1
	jz endCollatz
	test collatz, 1
	jnp oddCollatz

	evenCollatz:
	inc collatzCounter
	mov eax, collatz
	div ebx
	mov collatz, eax
	jmp begin

	oddCollatz:
	inc collatzCounter
	imul ecx, collatz, 3
	mov collatz, ecx
	inc collatz
	jmp begin

	endInvalid:
	lea eax, collatzInvalid
	push eax
	call _printString
	add esp, 4
	jmp endProgram

	endCollatz:

	lea eax, collatzStrCount
	push eax
	call _printString
	add esp, 4

	mov eax, collatzCounter
	push eax
	call _printInt
	add esp, 4

	mov collatzCounter, 0
	call _clockEnd

	endProgram:
	pop ebp
	ret

_asmCollatz ENDP
END