; Chapter 9 Lab Exercise 2
; Ethan Chiu
; 5/15/18

INCLUDE Irvine32.inc

Get_frequencies PROTO,
pString:PTR BYTE,        ; points to string
pTable:PTR DWORD  ; points to frequency table

.data
freqTable DWORD 256 DUP(0)
aString BYTE 80 DUP(0),0

colonChar BYTE ": ",0

str1 BYTE "*** Constructing a Frequency Table *** (DEMO)", 0dh,0ah,0dh,0ah, "Enter between 1 and 80 characters: ",0

.code
main PROC
	mov edx, OFFSET str1
	call WriteString

	mov ecx, SIZEOF aString - 1
	mov edx, OFFSET aString
	call ReadString

	invoke Get_frequencies, ADDR aString, ADDR freqTable
	call ShowTable

main ENDP

Get_frequencies PROC, pString:PTR BYTE, pTable:PTR DWORD

	mov esi, pString
	mov edi, pTable

	cld
	L1:
		mov eax, 0
		lodsb
		cmp al, 0
		je LeaveProc
		shl eax, 2
		inc DWORD PTR[edi+eax]
		jmp L1
	LeaveProc:
		ret
Get_frequencies ENDP

ShowTable PROC
	call CRLF
	mov ecx, LENGTHOF freqTable
	mov esi, OFFSET freqTable
	mov ebx, 0

	L1:
		mov eax, [esi]
		cmp eax, 0
		jna L2
		
		mov eax, ebx
		call WriteChar
		mov edx, OFFSET colonChar
		call WriteString
		mov eax, [esi]
		call WriteDec
		call CRLF
	L2:
		add esi, TYPE freqTable
		inc ebx
		loop L1
		call CRLF
		ret
ShowTable ENDP

END main
