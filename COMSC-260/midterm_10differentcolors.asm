INCLUDE Irvine32.inc

.data
userstring BYTE 80 DUP(0)
prompt BYTE "Enter string: ", 0

.code
main PROC
; outer loop Counter
mov ecx, 1

;Set Initial Color
;mov eax,yellow + (blue * 16)

L1:
push ecx


mov edx, OFFSET prompt
call WriteString
mov edx, OFFSET userstring
mov ecx, SIZEOF userstring - 1
call ReadString

mov ecx, 10

L2:
;Randomly set color
add eax, 17
call SetTextColor
mov edx, OFFSET userstring

call WriteString
call CRLF
Loop L2

pop ecx
Loop L1
call WaitMsg

exit
main ENDP

END main

