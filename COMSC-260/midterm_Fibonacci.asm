INCLUDE Irvine32.inc

.data
int1 BYTE 80 DUP(0)
prompt BYTE "Enter # of Fib numbers you want: ", 0 

.code
;For only the top two cases
One:
 mov eax, 0
 call WriteInt
 call CrLf
 call WaitMsg
 exit
Two:
 mov eax, 0
 call WriteInt
 call CrLf
 mov eax, 1
 call WriteInt
 call CrLf
 call WaitMsg
 exit

main PROC
 ;Prompts
 mov edx, OFFSET prompt
 call WriteString
 mov edx, OFFSET int1
 call ReadInt

 ;See if it's just the first 2 values
 cmp eax, 1
 je One
 cmp eax, 2
 je Two

 ;If > 2, subtract 2 to set up counter for other loop.
 sub eax, 2
 mov ecx, eax ; set counter to user input

 ;set up and display initial values
 mov eax, 0
 call WriteInt ; display eax
 call CRLF
 mov eax,1
 mov ebx,0 ; set up with initial values
 call WriteInt ; display eax
 call CRLF
 mov edx,1
L1:
 mov eax,ebx ; eax=ebx + edx
 add eax,edx
 call WriteInt ; display eax
 call CRLF
 mov ebx,edx ;start with new values to increment
 mov edx,eax
 Loop L1
 call WaitMsg
 exit
main ENDP
END main

