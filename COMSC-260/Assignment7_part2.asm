;Assignment 7 Part 2
;Ethan Chiu
;4/30/18

INCLUDE Irvine32.inc

.data
packed_1a WORD 4536h
packed_1b WORD 7207h
sum_1 DWORD 0
packed_2a DWORD 67345620h
packed_2b DWORD 54496342h
sum_2 DWORD 2 DUP(0)
packed_3a QWORD 6734562000346521h
packed_3b QWORD 5449634205738261h
sum_3 DWORD 3 DUP(0)

.code
main PROC
	mov esi, OFFSET packed_1a
	mov edi, OFFSET packed_1b
	mov edx, OFFSET sum_1
	mov ecx, SIZEOF packed_1a 

	call AddPacked

	add edx, SIZEOF sum_1-1
	mov ecx, SIZEOF sum_1
	call PHex

	mov ecx, SIZEOF packed_2a 
	mov esi, OFFSET packed_2a
	mov edi, OFFSET packed_2b
	mov edx, OFFSET sum_2
	call AddPacked

	add edx, SIZEOF sum_2-1
	mov ecx, SIZEOF sum_2
	call PHex

	mov ecx, SIZEOF packed_3a 
	mov esi, OFFSET packed_3a
	mov edi, OFFSET packed_3b
	mov edx, OFFSET sum_3
	call AddPacked

	add edx, SIZEOF sum_3-1
	mov ecx, SIZEOF sum_3
	call PHex

	call WaitMsg
	exit
main ENDP

;-------------------------
AddPacked PROC
;adds any two dec. integers of arbitrary size
;Given:
;ESI - pointer to the first number
;EDI - pointer to the second number
;EDX - pointer to the sum
;ECX - number of bytes to add 
;-------------------------
	pushad
	mov al, 0
	L1:
		add al, BYTE PTR [esi]
		add al, BYTE PTR [edi]
		daa
		mov BYTE PTR [edx], al
		inc esi
		inc edi
		inc edx
		mov  al, 0
		adc al, 0
		loop L1
	mov BYTE PTR [edx], al
	popad
	ret
AddPacked ENDP

;-------------------------
PHex PROC
;Print w/o zeros
;-------------------------
	pushad
	L2:
		cmp BYTE PTR [edx], 0
		jne L3
		dec edx
		loop L2
	L3:
		mov eax, 0
		mov al, [edx]
		mov ebx, TYPE BYTE 
		call WriteHexB
		dec edx
		loop L3
	call Crlf
	popad
	ret
PHex ENDP

END main
