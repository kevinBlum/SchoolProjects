; Assignment 4
; Kevin Blum


.386 ; Program directive stating it is using x86 architecture
.MODEL FLAT, stdcall ; Program directive for setting the memory model to flat, meaning it is sequential
.STACK 4096 ; Program directive for setting stack memory
ExitProcess PROTO, dwExitCode:DWORD

.data ; Program Segment directive for initialized data
initArray WORD 5, 10, 15, 20 ; Initialize WORD array 
dwordArray DWORD ? ; Uninitialize DWORD array

.code ; Program directive for the section where actual functions and instructions are written
main PROC ; Main function call, also entry point of program

lea eax, initArray ; Load effective address of first array for debugging
lea ecx, dwordArray ; Load effective address of second array for debugging

mov eax, 0 ; Clear eax for precaution, making sure no garbage characters left over
mov ax, initArray ; Store First Index of array in ax register
cwd ; Change value in ax from Word to DWord
mov ebx, 8 ; Move multiplier, 8, into ebx register
mul ebx ; Multiply eax register with ebx register
mov dwordArray, eax ; Move new multiplied value from eax into first index of DWord Array

mov eax, 0 ; Clear eax for safety
mov ax, [initArray + 2] ; Store Second Index of array in ax register
cwd ; Change value in ax from word to DWord
mul ebx ; Multiply eax by ebx because 8 is still stored in ebx register
mov [dwordArray + 2], eax ; Move new multiplied value from eax into second index of DWord Array

mov eax, 0 ; Clear eax for safety
mov ax, [initArray + 4] ; Store Third Index of array in ax register
cwd ; Change value in ax from word to DWord
mul ebx ; Multiply eax by ebx because 8 is still stored in the ebx register
mov [dwordArray + 4], eax ; Move new multiplied value from eax into third index of DWord Array

mov eax, 0 ; Clear eax for safety
mov ax, [initArray + 6] ; Store Fourth Index of array in ax register
cwd ; Change value in ax from word to DWord
mul ebx ; Multiply eax by ebx because 8 is still stored in the ebx register
mov [dwordArray + 6], eax ; Move new multiplied value from eax into fourth index of DWord Array


INVOKE ExitProcess, 0 ; Start end routine to end program
main ENDP ; End of main function
END