;Lab 6 Part 1
;Ethan Chiu
;4/3/18

INCLUDE Irvine32.inc

.data
int1 BYTE 80 DUP(0)
prompt BYTE "Please enter an integer between -5000 and 5000: ", 0 
negativeString BYTE " is negative", 0
notNegative BYTE " is not negative", 0

.code
Negative:
	mov edx, OFFSET negativeString
	call WriteInt
	call WriteString
	call CRLF
	call WaitMsg

	exit

main PROC
	;Prompts
	mov edx, OFFSET prompt
	call WriteString
	mov edx, OFFSET int1
	call ReadInt

	;See if it's negative by checking signed flag
	js Negative
	mov edx, OFFSET notNegative
	call WriteInt
	call WriteString
	call CRLF
	call WaitMsg
	
	exit

main ENDP
END main
