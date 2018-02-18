; Kevin Blum
; Assignment 6.1
; MASM 32-bit
; Entry point asmMain

.386
.MODEL flat, C
.STACK 4096

ExitProcess PROTO stdcall, dwExitCode:DWORD

; Function prototype for cpp getNum function to ask user for input of two integers
getNum PROTO C arg1:dword, arg2:dword
; Function prototype for cpp outputSum function to output the sum
outputSum PROTO C arg1:dword

.DATA
; Definitions for two dword variables initialized to 0
num1 DWORD 0
num2 DWORD 0

.CODE
asmMain PROC C

   int 3                ; Interrupt 3 to cause breakpoint, allows for debugging

   push num1            ; Push the first number variable to the stack to be passed to the function
   push num2            ; Push the second number variable to the stack to be passed to the function
   call getNum          ; Call the cpp function to get the two numbers from user input
   pop num1             ; Pop the first number variable off the stack 
   pop num2             ; Pop the second number variable off the stack
   mov eax, num1        ; Move the first number variable into the eax register
   mov ebx, num2        ; Move the second number variable into the ebx register
   add eax, ebx         ; Add the values of eax and ebx, which are the variables one and two, storing it in eax which is the return register

   push eax             ; Push the eax register onto the stack to be passed to the output function
   call outputSum       ; Call the cpp function to output the sum to the console
   pop eax              ; Pop the eax register off the stack

   int 3                ; Interrup to cause breakpoint for debugging

INVOKE ExitProcess, 0
asmMain ENDP
END
