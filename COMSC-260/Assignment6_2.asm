;Assignment 6 Part 2
;Ethan Chiu
;4/16/18

INCLUDE Irvine32.inc
.data
table BYTE '1'
	DWORD Process_1
	EntrySize = ($ - table)
	BYTE '2'
	DWORD Process_2
	BYTE '3'
	DWORD Process_3
	BYTE '4'
	DWORD Process_4
	BYTE '5'
	DWORD Process_5
CountEntries = ($ - table)/EntrySize

s1 BYTE "1. x AND y", 0
s2 BYTE "2. x OR y", 0
s3 BYTE "3. NOT x", 0
s4 BYTE "4. x XOR y", 0
s5 BYTE "5. Exit program", 0

choice BYTE "Enter your choice: ", 0

sA BYTE "AND operation", 0
sO BYTE "OR operation", 0
sN BYTE "NOT operation", 0
sX BYTE "XOR operation", 0

o1 BYTE "Input the first 32-bit hexadecimal operand: ", 0
o2 BYTE "Input the second 32-bit hexadecimal operand: ", 0
output BYTE "The 32-bit hexadecimal result is: ", 0

.code
main PROC
	Call DisplayMenu
	Call Calculation
	exit
main ENDP


DisplayMenu PROC 
	mov edx, OFFSET s1
	call WriteString
	call CRLF
	mov edx, OFFSET s2
	call WriteString
	call CRLF
	mov edx, OFFSET s3
	call WriteString
	call CRLF
	mov edx, OFFSET s4
	call WriteString
	call CRLF
	mov edx, OFFSET s5
	call WriteString
	call CRLF
	mov edx, OFFSET choice
	call WriteString
	call ReadChar

	mov bl, al;store char in right location

	mov esi , OFFSET table
	mov ecx, CountEntries

	call DisplayOpr
	call CRLF
	ret
DisplayMenu ENDP

DisplayOpr PROC
L1: 
	cmp al, [esi]
	jne L2
	call NEAR PTR [esi+1]
	call CRLF
	call WriteString
	call CRLF
	jmp L3
	L2:
		add esi, CountEntries
		loop L1
	L3:
		ret
DisplayOpr ENDP

Process_1 PROC 
	mov edx, OFFSET sA
	ret
Process_1 ENDP 

Process_2 PROC 
	mov edx, OFFSET sO
	ret
Process_2 ENDP 

Process_3 PROC 
	mov edx, OFFSET sN
	ret
Process_3 ENDP 

Process_4 PROC 
	mov edx, OFFSET sX
	ret
Process_4 ENDP 

Process_5 PROC 
	exit
Process_5 ENDP 

Calculation PROC
	mov edx, OFFSET o1
	Call WriteString
	Call ReadHex
	mov ecx, eax

	.IF bl != '3'
		mov edx, OFFSET o2
		Call WriteString
		Call ReadHex
	.ENDIF

	.IF bl == '1'
		and ecx, eax
	.ELSEIF bl == '2'
		or ecx,eax
	.ELSEIF bl == '3'
		not ecx
	.ELSEIF bl == '4'
		xor ecx, eax
	.ENDIF
	
	mov edx, OFFSET output
	Call WriteString
	mov eax, ecx
	Call WriteHex
	Call CRLF
	ret
Calculation ENDP


End main
