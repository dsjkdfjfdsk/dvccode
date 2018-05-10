;Chapter 8 Lab Exercise
;Ethan Chiu
;5/3/18

;Implement the ArrayFill procedures in three different ways:
;1.push/pop ebp manually in the statements (ArrayFill1)
;2.Use Enter & Leave instructions (ArrayFill2)
;3.Use the LOCAL directive (ArrayFill3)

INCLUDE Irvine32.inc

COUNT=100
.data
array DWORD COUNT DUP(?)
UPPER DWORD 2000
LOWER DWORD 500

.code
main PROC
	;To reseed random number generator
	call Randomize

	push OFFSET array
	push COUNT

	call ArrayFill1
	;call ArrayFill2
	;call ArrayFill3
	
	exit

main ENDP


ArrayFill1 PROC	
	push ebp
	mov	ebp, esp
	pushad
	mov	esi, [ebp+12]
	mov	ecx, [ebp+8]
	cmp	ecx, 0
	je L2
L1:
	call BetterRandomRange
	mov	[esi], ax
	call WriteInt
	call CRLF
	add	esi, TYPE WORD
	loop L1
L2:	
	popad
	pop	ebp
	ret	8
ArrayFill1 ENDP

ArrayFill2 PROC
	enter 4,0 ;1 local dword
	pushad
	mov	esi, [ebp+12]
	mov	ecx, [ebp+8]
	cmp	ecx, 0
	je L2
L1:
	call BetterRandomRange
	mov	[esi], ax
	call WriteInt
	call CRLF
	add	esi, TYPE WORD
	loop L1
L2:	
	leave
	ret	8

ArrayFill2 ENDP

ArrayFill3 PROC
	LOCAL var:DWORD
	pushad
	mov	esi, [ebp+12]
	mov	ecx, [ebp+8]
	cmp	ecx, 0
	je L2
L1:
	call BetterRandomRange
	mov	[esi], ax
	call WriteInt
	call CRLF
	add	esi, TYPE WORD
	loop L1
L2:	
	ret	8

ArrayFill3 ENDP

BetterRandomRange PROC
	mov	eax, UPPER
	mov ebx, LOWER
	sub eax, ebx ; Subract the higher bound from lower bound to get distance.
	mov edx, eax 

	mov	eax, edx
	call RandomRange
	add eax, LOWER
	ret
BetterRandomRange ENDP


END main

