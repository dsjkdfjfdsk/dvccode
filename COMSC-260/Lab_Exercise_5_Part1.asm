;Lab Exercise 5 Part 1
;Ethan Chiu
;3/6/18

INCLUDE Irvine32.inc

.data
;aName byte "Abraham Lincoln", 0
;nameSize = ($ - aName) - 1

buffer BYTE 51 DUP(0)
byteCount DWORD ?

.code
main PROC
	
	;CALL DUMPRegs
	;call WriteHex
	;call Crlf
	mov edx, OFFSET buffer
	mov ecx, SIZEOF buffer
	call ReadString
	mov byteCount, eax


	mov ecx, byteCount
	mov esi, 0
	L1:
		movzx eax, buffer[esi]
		push eax
		inc esi
	loop L1

	mov ecx, byteCount
	mov esi, 0

	L2:
		pop eax
		mov buffer[esi], al
		inc esi
	loop L2
	
	exit
main ENDP

END main
