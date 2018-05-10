;Chapter 9 Lab Exercise (Part 1)
;Ethan Chiu
;5/9/18

INCLUDE Irvine32.inc

.data

Sourcew WORD 10, 20, 30
Targetw WORD 10, 20, 35
WordArray WORD 10h, 20h, 100h, 30h

count1 = ($ - Targetw)/TYPE WORD
count2 = ($ - WordArray)/TYPE WORD
same BYTE "Source Array and Target Array are the same.", 0
notSame BYTE "Source Array and Target Array are not the same.", 0
message BYTE "The matched word is located at: ", 0
notFound BYTE "Could not find 0100h", 0

.code
main PROC
	;compare two arrays of 16-bit variables using cmpsw and outputs if equal
	mov ecx, count1
	mov esi, OFFSET Targetw
	mov edi, OFFSET Sourcew
	cld
	repe cmpsw
	jne notEqual
	mov edx, OFFSET same
	jmp done

	notEqual:
		mov edx, OFFSET notSame
	
	done:
		call WriteString
		call CRLF

	; "Use SCASW to scan for the 16-bit value 0100h in an array named wordArray, and copy the offset of the matching member into the EAX register."
	mov ecx, count2
	mov edi, OFFSET WordArray
	mov ax, 0100h
	cld
	repne scasw
	jnz nFound
	dec edi
	mov eax, edi
	jmp finish

	nFound:
		mov edx, OFFSET notFound
		call WriteString
		call CRLF
	
	;Output results
	finish:
		mov edx, OFFSET message
		call WriteString
		call WriteHex
		call CRLF
		call WaitMsg

main ENDP

END main

