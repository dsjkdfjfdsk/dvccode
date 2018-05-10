; AddTwo.asm - adds two 32-bit integers.
; Chapter 3 example

.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

.data
bigEndian BYTE 12h,34h,56h,78h
littleEndian DWORD ?

.code
main proc
	mov ebx, DWORD PTR bigEndian
	mov al, BYTE PTR bigEndian+3 
	mov ah, BYTE PTR bigEndian+2

	mov bl, BYTE PTR bigEndian+1 
	mov bh, BYTE PTR bigEndian

	mov littleEndian, eax

						

	invoke ExitProcess,0
main endp
end main
