CountNearMatches proto, ptr1:PTR SDWORD,ptr2:PTR SDWORD, arraySize:DWORD, diff:DWORD

.data

array1 sdword 10,5,4,-6,2

array2 sdword 12,3,5,-6,1           

array3 sdword 13,2,-4,-8,20         

count = LENGTHOF array1

.code

invoke CountNearMatches,ADDR array1, ADDR array2, count, 2       

invoke CountNearMatches,ADDR array1, ADDR array3, count, 2   	 
Your Answer:
;Ethan Chiu
INCLUDE Irvine32.inc

CountNearMatches proto, ptr1:PTR SDWORD,ptr2:PTR SDWORD, arraySize:DWORD, diff:DWORD

.data

array1 sdword 10,5,4,-6,2

array2 sdword 12,3,5,-6,1

array3 sdword 13,2,-4,-8,20

count = LENGTHOF array1

.code
main PROC
invoke CountNearMatches,ADDR array1, ADDR array2, count, 2
invoke CountNearMatches,ADDR array1, ADDR array3, count, 2

exit
main ENDP

CountNearMatches PROC USES esi edi eax edx,
ptr1: PTR SDWORD,
ptr2: PTR SDWORD,
arraySize:DWORD,
diff:DWORD

push edi
push esi
push ecx
push edx

mov eax, 0
mov esi, ptr1
mov edi, ptr2
mov ecx, arraySize

L1: mov edx, [esi]
sub edx, [edi]
jns L2
neg edx

L2:
cmp edx,diff
ja L3
inc eax

L3: add esi, 4
add edi, 4
loop L1

pop edx
pop ecx
pop edi
pop esi


call WriteInt
call CRLF
ret

CountNearMatches ENDP

END main

