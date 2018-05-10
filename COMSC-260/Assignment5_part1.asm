;Assignment 5 Part 1
;Ethan Chiu
;3/20/18

INCLUDE Irvine32.inc

.data

int1 BYTE 80 DUP(0)
int2 BYTE 80 DUP(0)
prompt BYTE "Enter lower bound: ", 0 
prompt2 BYTE "Enter upper bound: ", 0
message BYTE "Random Number: ", 0

.code
main PROC
	;Outer Loop (called 3 times)
	mov ecx, 3
	L1:
		push ecx

		call Clrscr
		mov edx, OFFSET prompt
		call WriteString
		mov edx, OFFSET int1
		call ReadInt
		mov ebx, eax

		mov edx, OFFSET prompt2
		call WriteString
		mov edx, OFFSET int2
		call ReadInt
		sub eax, ebx ; Subract the higher bound from lower bound to get distance.
		mov edx, eax ; save original difference value
		
		mov ecx, 30 ;call BetterRandomRange 30 times

	BetterRandomRange:
		mov eax, edx ; restore eax to original value and sets ceiling value
		call RandomRange ; Find random int from the range which overwrites eax
		add eax, ebx ; Add the lower bound to the random range to make it fit within restraints.

		loop BetterRandomRange
		mov edx, OFFSET message
		call WriteString
		call WriteInt
		call CRLF
		call WaitMsg

		pop ecx
		loop L1



		

	
	exit
main ENDP

END main
