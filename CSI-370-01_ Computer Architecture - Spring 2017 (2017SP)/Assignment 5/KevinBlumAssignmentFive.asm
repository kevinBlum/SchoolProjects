; Assignment 5 - MASM
; Fibonacci's revenge
; Kevin Blum
; 2/19/17
; CSI-370-01


.386                 ; Program directive stating it is using x86 architecture
.MODEL FLAT, stdcall ; Program directive for setting the memory model to flat, meaning it is sequential. stdcall for the standard calling convention
.STACK 4096          ; Program directive for setting stack memory to size 4096
ExitProcess PROTO, dwExitCode:DWORD ; Establish the exit process

.data                ; Program Segment directive for initialized and uninitialized data
limit DWORD 1000000  ; Variable limit set to one million, as the upper limit of values

.code                ; Program directive for the section where actual functions and instructions are written
main PROC            ; Main function call, also entry point of program

mov eax, 0           ; Represents the initial value, set to zero instead of one so the first value of fibonacci, one, is not skipped
mov ebx, 1           ; Represents the next value, set to one so that the program actually computes the values of fibonacci
mov edx, 0           ; Represents the sum of the initial and next value to produce the actual next fibonacci value
mov ecx, 0           ; Represents the sum of all odd fibonacci values

oddsum:              ; Label for the function which sums all odd fibonacci values
add ecx, edx         ; Instruction to add edx, which is the fibonacci value from the main loop, to the ecx register, which is used as the sum for all odd fibonacci values
cmp ecx, 0           ; cmp instruction to compare sum and 0, because of the implicit subtraction this is used to allow it to pass the first time because exc will be 0 and 0 from 0 is still zero
jnz continueloop     ; Jump instruction that is used to jump back into the rest of the loop for the fibonacci sequence, should jump on all but the initial instance

whileloop:           ; Label for the function of the main loop that computes the fibonacci values
mov  edx, eax        ; Sets eax and edx register to be equal, because eax is the previous value, it sets up the add instruction so that it is previous value plus the next value
add  edx, ebx        ; Adds ebx, which represents the next value of the fibonacci numbers, to edx, which holds the previous value, and stores it in edx which creates the next fibonacci value
cmp edx, limit       ; cmp instruction to test whether the fibonacci value is above the limit, and if it is above the limit the program jumps to the end of program
ja finish            ; Jump instruction that is used to jump to the end of program if the fibonacci number is above the limit value
test edx, 1          ; test instruction used for implicit AND operation that will set the parity flag after doing edx AND 1, which will tell if the value of edx is even or odd
jnp oddsum           ; Jump instruction that will jump to the oddsum function if the parity flag is not set, meaning that the value of edx is odd

continueloop:        ; Label for the function to continue the loop after either jumping to oddsum or just after checking for an odd value and continuing the loop
mov  eax, ebx        ; Set eax, which represents the previous value to the value from ebx, which was the next value from before the addition
mov  ebx, edx        ; Set ebx, which represents the next value to the value from edx, which is the next value in teh fibonacci sequence as it is the sum of the two previous values
cmp edx, limit       ; cmp instruction to compare edx to the limit and jumps back to the top of the main loop while edx is less than the limit
jnae whileloop       ; Jump instruction for comparing edx to the limit, it should always jump because edx should be less than the limit. I just didnt want to use an unconditional jump here even though it may be ineffecient

finish:              ; Label for jump to end of program
INVOKE ExitProcess, 0; Start end routine to end program
main ENDP            ; End of main function
END                  ; End of program