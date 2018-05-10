;Assignment 6 Part 1
;Ethan Chiu
;4/16/18
; Revised from the encrypt.asm file

INCLUDE Irvine32.inc
BUFMAX = 128     	; maximum buffer size

.data
ePrompt Byte "Enter the encryption key: ",0
sPrompt  BYTE  "Enter the plain text: ",0
sEncrypt BYTE  "Cipher text:          ",0
sDecrypt BYTE  "Decrypted:            ",0

buffer   BYTE   BUFMAX+1 DUP(0)
bufSize  DWORD  ?
KEY BYTE BUFMAX+1 DUP (?) 
keybuf DWORD ?

.code
main PROC
	call	InputTheString		; input the plain text
	call	InputTheKey;
	call	TranslateBuffer	; encrypt the buffer
	mov	edx,OFFSET sEncrypt	; display encrypted message
	call	DisplayMessage
	call	TranslateBuffer  	; decrypt the buffer
	mov	edx,OFFSET sDecrypt	; display decrypted message
	call	DisplayMessage

	exit
main ENDP

InputTheKey PROC
	pushad
	mov	edx,OFFSET ePrompt	; display a prompt
	call	WriteString
	mov	ecx,BUFMAX		; maximum character count
	mov	edx,OFFSET KEY   ; point to the key
	call	ReadString         	; input the string
	mov	keybuf, eax        	; save the key
	call	Crlf
	popad
	ret
InputTheKey ENDP

;-----------------------------------------------------
InputTheString PROC
;
; Prompts user for a plaintext string. Saves the string 
; and its length.
; Receives: nothing
; Returns: nothing
;-----------------------------------------------------
	pushad
	mov	edx,OFFSET sPrompt	; display a prompt
	call	WriteString
	mov	ecx,BUFMAX		; maximum character count
	mov	edx,OFFSET buffer   ; point to the buffer
	call	ReadString         	; input the string
	mov	bufSize,eax        	; save the length
	call	Crlf
	popad
	ret
InputTheString ENDP

;-----------------------------------------------------
DisplayMessage PROC
;
; Displays the encrypted or decrypted message.
; Receives: EDX points to the message
; Returns:  nothing
;-----------------------------------------------------
	pushad
	call	WriteString
	mov	edx,OFFSET buffer	; display the buffer
	call	WriteString
	call	Crlf
	call	Crlf
	popad
	ret
DisplayMessage ENDP

;-----------------------------------------------------
TranslateBuffer PROC
;
; Translates the string by exclusive-ORing each
; byte with the encryption key byte.
; Revised: Now uses key from user input
; Receives: nothing
; Returns: nothing
;-----------------------------------------------------
	pushad
	mov	ecx,bufSize		; loop counter
	mov	esi,0			; index 0 in buffer
	mov edx, 0 ; other counter for keybuf
L1:
	.IF edx >= keybuf
		mov edx, 0 ; reset counter
	.ENDIF

	mov bl, KEY[edx]

	xor	buffer[esi], bl	; translate a byte
	inc	esi				; point to next byte
	add edx, 1 ;increment key counter

	loop	L1

	popad
	ret

	;pseduocode
	;mov ecx, KEY; inner loop counter
	;counter = 1
	;for 0 to bufsize
	;	if counter > keybuf
	;		counter = 1
	;	xor	buffer[esi], KEY[ecx-1]	
	;	counter++


TranslateBuffer ENDP
END main
