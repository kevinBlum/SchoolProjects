; Kevin Blum
; Assignment 9.2
; MASM 32-bit

.686
.MODEL FLAT, stdcall
.STACK 4096

ExitProcess PROTO, dwExitCode:DWORD

floatMacro MACRO dest, source1, source2							; First Macro to use FPU subtraction
	fld source2
	fld source1
	fsub ST(0), ST(1)
	fstp dest
ENDM

floatMacroMul MACRO dest, source1, source2						; Second Macro to use FPU multiplication
	fld source2
	fld source1
	fmul ST(0), ST(1)
	fstp dest
ENDM

floatMacroSphereVolume MACRO dest, source1, source2, source3	; Third Macro to calculate the volume of a sphere: 4/3(pi)r^2
	fld source1
	fmul ST(0), ST(0)
	fld source2
	fld source3
	fdiv ST(0), ST(1)
	fmul ST(0), ST(2)
	fldpi
	fmul ST(0), ST(1)
	fstp dest
ENDM

.DATA															; Programmer defined data, first two floats for first two macros, radius and other floats for sphere macro, result for destination in macros
floatOne REAL8 24.98
floatTwo REAL8 12.11
floatRadius REAL8 42.42
floatFour REAL8 4.0
floatThree REAL8 3.0
resultFloat REAL8 ?

.CODE
_main PROC

	int 3
	finit														; Initialize FPU in main because all macros use floating point operations, then call all three macros with proper arguments
	floatMacro resultFloat, floatOne, floatTwo
	floatMacroMul resultFloat, floatOne, floatTwo
	floatMacroSphereVolume resultFloat, floatRadius, floatThree, floatFour

INVOKE ExitProcess, 0
_main ENDP
END