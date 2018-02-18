; Assignment 3.3
; Syntax Translation - GAS, Clang/LLVM (32-bit)
; Copyright (c) 2017 Hall & Slonka
; Kevin Blum

.386
.MODEL FLAT, stdcall
.STACK 4096

ExitProcess PROTO, dwExitCode:DWORD

.DATA

letter BYTE ?
r DWORD ?
s DWORD ?
t DWORD ?
x WORD ?
y WORD ?
z WORD ?


.CODE
_main PROC
	mov letter, 077h
	mov r, 05h
	mov s, 02h
	mov x, 0Ah
	mov y, 04h

	mov ax, x
	add ax, y
	mov z, ax

	mov ax, x
	sub ax, y
	mov z, ax

	mov edx, 00h
	mov eax, r
	mov ecx, s
	div ecx
	mov t, eax

	mov edx, 00h
	mov eax, r
	mov ecx, s
	div ecx
	mov t, edx

	INVOKE ExitProcess, 0

_main ENDP
END