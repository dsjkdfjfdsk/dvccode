;Assignment 5 Part 2
;Ethan Chiu
;3/20/18

INCLUDE Irvine32.inc

.data

.code
main PROC

	;20 random strings
	mov  ecx, 20 ; outer loop counter

L1:	push ecx
	call CreateRandomString	; display random string
	pop ecx
	Loop L1
	call Crlf
	call WaitMsg

	exit
main ENDP

CreateRandomString PROC
	mov eax, 100
	call RandomRange ; from 0 to 100 for L
	mov ecx, eax ;set inner loop counter

L2:	mov eax,26
	call RandomRange	; EAX = 0 to 25
	add eax,65

; We need to display this character:
	call WriteChar
	Loop L2
	call CRLF

	ret
CreateRandomString ENDP

END main
