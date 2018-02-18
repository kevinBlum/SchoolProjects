; Kevin Blum
; 3/29/17
; Assignment 8.1
; CSI-370-01
; Assembly Code 32-bit MASM

.686
.MODEL flat, C
.STACK 4096

_getDouble PROTO
_printString PROTO
_printDouble PROTO

.DATA
heightString BYTE "Enter the height: ",0
radiusString BYTE "Enter the radius: ",0
volumeString BYTE "The volume is: ",0

height REAL8 ?
radius REAL8 ?
volume REAL8 ?

.CODE
_asmMain PROC

	push ebp
	mov ebp, esp

	finit					; Initialize the FPU
	fldpi					; Load pi into ST(0)

	lea eax, heightString	; Load address of string and then push it to stack and call print function
	push eax
	call _printString
	add esp, 4

	call _getDouble			; Get user input for height and store it in ST(0) and push pi to ST(1)
	fst height				; Store ST(0), height, in variable for height

	lea eax, radiusString	; Load address of string and push to stack and call print function
	push eax
	call _printString
	add esp, 4

	call _getDouble			; Get user input for radius and store it in ST(0), pushes height and pi to ST(1), ST(2) respectively
	fst radius				; Store ST(0), radius, in variable for radius

	fmul ST(0), ST(0)		; Multiply radius by itself to get radius squared
	fmul ST(0), ST(1)		; Multiply radius squared times height
	fmul ST(0), ST(2)		; Multiply r^2*h by pi to get the volume of cylinder

	lea eax, volumeString	; Load address of string and push it to stack and call print function
	push eax
	call _printString
	add esp, 4


	fstp volume				; Store volume from ST(0) as single precision to volume variable
	push DWORD PTR [volume + 4]
	push DWORD PTR [volume]	; Push the components of volume address to stack
	call _printDouble		; Call print double function to print the volume
	add esp, 8
	int 3
	pop ebp
	ret

_asmMain ENDP
END