; Kevin Blum
; Final Project Sieve
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

clearReg MACRO
	xor eax, eax
	xor ecx, ecx
	xor ebx, ebx
ENDM


arraySize EQU 10001								; Constant for array size and prime candidate is arraySize - 1
.DATA
	primeArray DWORD arraySize DUP(?)			; Initialize prime with arraySize amount of uninitialized DWORDS
	sieveString BYTE "Primes below 1000: ",0

.CODE
_asmSieve PROC

	push ebp
	mov ebp, esp

	lea eax, sieveString
	push eax
	call _printString
	add esp, 4

	call _clockStart

	clearReg
	populateArray:					
		mov eax, ecx
		add eax, 2
		mov [primeArray+4*ecx], eax	
		inc ecx
		cmp eax, arraySize
		jnz populateArray
	   	
	finishArray:
	clearReg
	partOne:
		mov ebx, ecx
		inc ebx
		cmp [primeArray+4*ecx], 0
		jne partTwo
		resumeOne:
		inc ecx
		cmp ecx, arraySize
		jb partOne
		jmp outputPrime

	partTwo:							
		cmp [primeArray+4*ebx], 0
		jne partThree
		resumeTwo:
		inc ebx
		cmp ebx, arraySize
		jb partTwo
		jmp resumeOne
		
	partThree:
		xor edx, edx
		xor eax, eax
		mov eax, [primeArray+4*ebx]
		div [primeArray+4*ecx]
		cmp edx, 0
		je removeValue
		jmp resumeTwo
		
				
	removeValue:
		mov [primeArray+4*ebx], 0
		jmp resumeTwo
 	
	outputPrime:
	call _clockEnd
	clearReg
	printArray:					
		cmp [primeArray+4*ecx], 0
		jne printArrayElement
   		resumePrintArray:
   		inc ecx
   		cmp ecx, arraySize
   		jb printArray
		jmp endProgram

	printArrayElement:
		push ecx
		mov eax, [primeArray+4*ecx]
		push eax
   		call _printInt
		add esp, 4
   		inc ebx
   		pop ecx
   		jmp resumePrintArray
	
	endProgram:
	pop ebp
	ret

_asmSieve ENDP
END