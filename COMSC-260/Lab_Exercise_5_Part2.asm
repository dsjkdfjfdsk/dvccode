; Ethan Chiu
;3/13/18
;Lab Exercise 5 Part 2

INCLUDE Irvine32.inc

.data
int1 BYTE 80 DUP(0)
int2 BYTE 80 DUP(0)
prompt BYTE "Enter first integer: ", 0 
prompt2 BYTE "Enter second integer: ", 0
sum BYTE "The sum of the integers is: ", 0

.code
main PROC
	; Set Counter
	mov ecx,3

	;Set Initial Color
	mov	eax,yellow + (blue * 16)

	;Loop to sum two integers from user
	L1:
		;Randomly set color
		add eax, 17
		call SetTextColor

		mov dl, 20 
		mov dh, 10 
		call Clrscr
		call Gotoxy
		mov edx, OFFSET prompt
		call WriteString
		mov edx, OFFSET int1
		call ReadInt
		mov ebx, eax

		mov dl, 20
		mov dh, 12
		call Gotoxy
		mov edx, OFFSET prompt2
		call WriteString
		mov edx, OFFSET int2
		call ReadInt
		add eax, ebx

		mov dl, 20
		mov dh, 14
		call Gotoxy
		mov edx, OFFSET sum
		call WriteString
		call WriteInt

		mov dl, 0
		mov dh, 16
		call Gotoxy
		call WaitMsg

		Loop L1

	exit
main ENDP

END main
