; Assignment #: Ch 3 Assignment
; Program Description: Int Expression Calculator with data definitions
; Author: Ethan Chiu
; Creation Date:2/15/18

.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword



;For unsigned 32 bit variables
.data
valueA DWORD 1000
valueB DWORD 500
valueC DWORD 450
valueD DWORD 100
sum DWORD 0

;For signed 32 bit variables
svalueA SDWORD -2000
svalueB SDWORD 100
svalueC SDWORD 1000
svalueD SDWORD -500


.code
main proc
	mov eax, valueA
	mov ebx, valueB
	mov ecx, valueC
	mov edx, valueD

	add	eax, ebx
	add ecx, edx
	
	sub eax, ecx
					
	mov sum, eax
	invoke ExitProcess,0
main endp
end main
