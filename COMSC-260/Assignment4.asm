; Assignment #: 4
; Program Description:
; Author: Ethan Chiu
; Creation Date: 3/5/18

.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

.data
;Part 1
bigEndian BYTE 12h,34h,56h,78h
littleEndian DWORD ?
;Part 2
arrayA DWORD 10d,20d,30d,40d,50d,60d,70d,80d,90d

.code
main proc
	;Part 1
	mov ah, BYTE PTR bigEndian
	mov al, BYTE PTR [bigEndian+1]
	mov WORD PTR [littleEndian+2], ax
	mov ah, BYTE PTR [bigEndian+2]
	mov al, BYTE PTR [bigEndian+3]
	mov WORD PTR [littleEndian], ax

	;Part 2
	mov esi, OFFSET arrayA 
	mov edi, SIZEOF arrayA
	add edi, OFFSET arrayA
	sub edi, TYPE arrayA 

	mov ecx, LENGTHOF arrayA / 2

	L1: 
		mov eax, [esi] 
	mov ebx, [edi]
	mov [edi],EAX
	mov [esi],EBX
	add esi, TYPE arrayA
	sub edi, TYPE arrayA
	LOOP L1


	invoke ExitProcess,0
main endp
end main

