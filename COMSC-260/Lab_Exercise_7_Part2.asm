;Lab Exercise 7 Part 2
;Ethan Chiu
;4/26/18

INCLUDE Irvine32.inc
.data

op1 QWORD 0A2B2A40674981234h

op2 QWORD 08010870090234502h

result QWORD 1 DUP(0) 

message BYTE "The difference equals: ", 0

DoubleWords = SIZEOF op1 /TYPE Dword

.code
main PROC
	;Write out message first
	mov edx, OFFSET message
	call WriteString

	mov esi, OFFSET op1
	mov edi, OFFSET op2
	mov ebx, OFFSET result

	Call Extended_Sub
	mov esi, OFFSET result
	add esi, DoubleWords * 4
	mov ecx, DoubleWords
	call Display_Result

	exit
main ENDP

Extended_Sub PROC
	;How many DWORDS there are
	mov ecx, 2
	pushad
	clc
	L1:
		mov eax, [esi]
		sbb eax, [edi]
		pushfd
		mov [ebx], eax
		add esi, 4
		add edi, 4
		add ebx, 4
		popfd
	loop L1
	mov DWORD PTR[ebx], 0
	sbb DWORD PTR[ebx], 0
	popad
	ret
Extended_Sub ENDP

Display_Result PROC

	pushad
	sub esi, TYPE DWORD
	mov ebx, TYPE DWORD
	L1:
		mov eax, [esi]
		call WriteHex
		sub esi, TYPE DWORD
	loop L1
	popad

	call Crlf 
	ret
Display_Result ENDP

END main

