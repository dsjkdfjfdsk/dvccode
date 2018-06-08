;Ethan Chiu
INCLUDE Irvine32.inc

Str_remove PROTO loc:PTR BYTE, n:PTR BYTE

.data
target BYTE "abcxxxxdefghijklmnop",0

.code
main PROC
invoke Str_remove, ADDR [target+3], 4
mov edx, OFFSET target
call WriteString
call Crlf
call WaitMsg
exit
main ENDP

Str_remove PROC USES esi edi ecx ebx,
loc:PTR BYTE,
n:PTR BYTE

mov edi, loc
add edi, n
mov esi, loc
mov ecx, SIZEOF target
sub ecx, n
L1:
mov ebx, [edi]
mov [esi], ebx
inc edi
inc esi
Loop L1
ret
Str_remove ENDP

END main

