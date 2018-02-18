; Assembly Assignment 3.2 for NASM
; Kevin Blum

SECTION .data ; Program Segment directive for initialized data
message: DB "You already know what the next",0Ah,"variable will be, don't you?",0 ; String of literal characters for text
length: DB ($ - message) ; Creates an integer by current address in memory, $, and subtracting message memory address
length5: EQU (length + 5) ; Symbol length5 is equivalent to variable length + 5, but the memory address not literal value(?)


SECTION .text ; Program Segment directive for instructions / code
global _main ; Makes the label _main avaialbe to linker for the entry point
_main: ; Label for the entry point of program

   mov eax, [length5] ; Moves value of length5 into eax register, but value is 0
   inc eax ; Increments the eax register by one, to one
   mov [length5], eax ; Move value of eax register into literal value of length5, which is 1

   inc BYTE [length5] ; Increment literal value of length5, from 1 to 2, what I think is the point of the assigment
		      ; but I can't seem to assign literal value of length5 to length, only memory address

   ; Attempts at incrementing length5
   ;mov length5, eax - Does not compile
   ;mov [length5], eax - Segmentation fault during execution when length is EQU
   ;inc BYTE length5 - Does not compile
   ;inc BYTE [length5] - Segmentation fault during execution when length is EQU

   mov ebx, length5 ; Move address of length5 to ebx register, for reference, should be memory address
   mov ecx, [length5] ; Move literal value of length5 to ecx register, for reference, should be literal value

; NASM exit routine
mov eax, 1 ; Move 1 to eax register, setting up exit routine
mov ebx, 0 ; Move 0 to ebx register, setting up exit routine
int 80h ; Interrupt to kernel, exit program
