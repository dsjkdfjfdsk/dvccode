; Assignment #: Ch. 4 Lab Exercise
; Program Description:movzx/movsx practice & array 
; Author: Ethan Chiu
; Creation Date: 2/20/18

.386
.model flat,stdcall
.stack 4096
ExitProcess PROTO, dwExitCode:DWORD
.data
;part 1
a WORD 100
b SWORD -100
;part 2
arrayD WORD 1,2,3,4
.code
main PROC
	;part 1
	movzx eax, a
	movsx ebx, b

	;part 2
	mov ax, arrayD
	xchg ax, [arrayD+6]
	mov arrayD, ax
	mov ax, arrayD+2
	xchg ax, [arrayD+4]
	mov arrayD+2, ax
	

	invoke ExitProcess,0
main ENDP
; (insert additional procedures here)
END main

