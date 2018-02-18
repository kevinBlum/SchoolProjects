; Kevin Blum
; Assignment 11
; MASM 64-bit
; Built with assistance from
; Program 10.8
; Windows API Calls in Microsoft x64 Assembly - (MASM 64-bit)
; Copyright (c) 2017 Hall & Slonka

extrn ExitProcess : proc
extrn MessageBoxA : proc
extrn CreateFileA : proc
extrn ReadFile : proc
extrn WriteFile : proc
extrn CloseHandle : proc

.DATA
num QWORD 13
inputFile BYTE "input.txt",0
outputFile BYTE "output.txt",0
caption BYTE "Message", 0
buffer BYTE 14 DUP (0)
userMessage BYTE "The file has been copied",0

FD QWORD ?
FDW QWORD ?
read QWORD ?
charsRead QWORD 0
charsWritten QWORD 0
button QWORD ?
closed QWORD ?

.CODE
_main PROC

	sub rsp, 10h						; reserve for return and rbp
	sub rsp, 18h						; reserve for parameters
	sub rsp, 20h						; reserve shadow space for regs

	lea rcx, inputFile					; address of file name
	mov rdx, 80000000h					; constant for GENERIC_READ
	xor r8, r8							; 0 share mode
	xor r9, r9							; 0 security
	mov QWORD PTR [rsp+48h-28h], 3		; reverse order, 3 open existing
	mov QWORD PTR [rsp+48h-20h], 80h	; flags FILE_ATTRIBUTE_NORMAL
	mov QWORD PTR [rsp+48h-18h], 0		; 0 template
	call CreateFileA
	mov FD, rax							; save handle
	
	mov rcx, FD							; pass FD
	lea rdx, buffer						; pass address of buffer
	mov r8, num							; pass buffer size
	lea r9, charsRead					; pass address of charsRead
	mov QWORD PTR [rsp+48h-28h], 0		; 0 overlap
	call ReadFile
	mov read, rax						; save characters read
		
	mov rcx, FD							; pass handle
	call CloseHandle
	mov closed, rax						; save status

	
	lea rcx, outputFile					; address of file name
	mov rdx, 70000000h					; constant for GENERIC_WRITE
	xor r8, r8							; 0 share mode
	xor r9, r9							; 0 security
	mov QWORD PTR [rsp+48h-28h], 1		; reverse order, 1 for create with all permissions
	mov QWORD PTR [rsp+48h-20h], 80h	; flags FILE_ATTRIBUTE_NORMAL
	mov QWORD PTR [rsp+48h-18h], 0		; 0 template
	call CreateFileA
 	mov FDW, rax						; save handle

	mov rcx, FDW						; pass FDW, second file descriptor for writing
	lea rdx, buffer						; pass address of buffer
	mov r8, num							; pass buffer size
	lea r9, charsWritten				; pass address of charsWritten
	mov QWORD PTR [rsp+48h-28h], 0		; 0 overlap
	call WriteFile
	
	xor rcx, rcx						; 0 handle owner
	lea rdx, userMessage				; pass text address
	lea r8, caption						; pass caption address
	xor r9, r9							; 0 MB_OK
	call MessageBoxA
	mov button, rax						; save button clicked


	mov rcx, FDW						; pass handle
	call CloseHandle
	mov closed, rax						; save status

	add rsp, 48h						; clean up stack

	mov rcx, 0							; return value
	call ExitProcess					; exit

_main ENDP
END