;Assignment 7 Part 1
;Ethan Chiu
;4/19/18

INCLUDE Irvine32.inc
.data
array DWORD 4BC94530h,2CBA9429h,4FB54386h,69FC0544h,5F5BE7ACh

COUNT = 8

.code
main PROC
	mov bl, COUNT
	Call ShiftDoublewordsRight

	;Display to Debugger
	mov esi, OFFSET array
	mov ecx, LENGTHOF array
	mov ebx, TYPE array
	call DumpMem

	exit
main ENDP


ShiftDoublewordsRight PROC 
	mov esi, OFFSET array
	mov ecx, (LENGTHOF array) - 1
L1:
	push ecx
	mov eax, [esi + TYPE DWORD]
	mov cl, bl
	shld [esi], eax, cl
	add esi, TYPE DWORD
	pop ecx
	loop L1

	shl DWORD PTR [esi], COUNT

	ret
ShiftDoublewordsRight ENDP

End main
