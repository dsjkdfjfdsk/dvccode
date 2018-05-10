;Assignment 7 Part 1
;Ethan Chiu
;4/19/18

INCLUDE Irvine32.inc
.data
key BYTE -5, 3, 2, -3, 0, 5, 2, -4, 7, 9
text BYTE "It is a secret message", 0

bufsize = (LENGTHOF text)
keybuf = (LENGTHOF key)

COUNT = 8

.code
main PROC
	Call TranslateBuffer
	Call DisplayMessage
	Call TranslateBuffer
	Call DisplayMessage
	exit
main ENDP

;-----------------------------------------------------
DisplayMessage PROC
;
; Displays the encrypted or decrypted message.
; Receives: EDX points to the message
; Returns:  nothing
;-----------------------------------------------------
	pushad
	;call	WriteString
	mov	edx,OFFSET text	; display the buffer
	call	WriteString
	call	Crlf
	call	Crlf
	popad
	ret
DisplayMessage ENDP



TranslateBuffer PROC 
	pushad
	mov	ecx,bufSize		; loop counter
	mov	esi,0			; index 0 in buffer
	mov edx, 0 ; other counter for keybuf
	MOV EDX, OFFSET text
L1:
	.IF edx >= keybuf
		mov edx, 0 ; reset counter
	.ENDIF

	;Check to see if positive or negative
	; neg => left, pos => right
	mov bl, KEY[edx]
	cmp bl, 0

	mov bl, KEY[edx]


	MOV AL, [EDX] ; value of the text
	;PUSH ECX
	MOV CL, KEY[edx]; value of the key
	ROL AL, CL    ; rol the text by the key
	MOV [EDX], AL

	inc	esi				; point to next byte
	add edx, 1 ;increment key counter

	loop	L1

	popad
	ret


TranslateBuffer ENDP

End main

