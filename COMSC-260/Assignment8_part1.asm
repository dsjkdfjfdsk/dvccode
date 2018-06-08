;Assignment 8 (Part 1)
;Ethan Chiu
;5/12/18

INCLUDE Irvine32.inc
GCD PROTO, int1:DWORD, int2:DWORD

.data
array SDWORD 35, 15, 72, 18, 31, 17, 128, 640, 121, 88
str1 BYTE "Greatest common divisor of ", 0
str2 BYTE " and ", 0
str3 BYTE " is: ", 0

.code
main PROC
	mov  ecx,LENGTHOF array / 2
	mov  esi,OFFSET array

L1:	
	mov  edx,OFFSET str1
	call WriteString
	mov eax, [esi]
	call WriteDec
	mov  edx,OFFSET str2
	call WriteString
	mov eax, [esi+4]
	call WriteDec
	mov  edx,OFFSET str3
	call WriteString

	INVOKE GCD,[esi],[esi+4]
	call WriteDec
	call Crlf
	add  esi,TYPE array * 2
	loop L1

	exit
main ENDP

GCD PROC,
	int1:DWORD, int2:DWORD

	mov eax,int1
	mov ebx,int2
	cmp ebx, 0 ; divide by zero?
	je divZ
	mov edx, 0
	div ebx
	cmp edx, 0
	je L2
	INVOKE GCD,ebx,edx

	L2:	mov	eax,ebx
		ret
		
	divZ:
		ret

GCD ENDP

END main
