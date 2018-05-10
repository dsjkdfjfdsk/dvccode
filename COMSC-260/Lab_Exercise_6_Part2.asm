;Lab 6 Part 2
;Ethan Chiu
;4/10/18

INCLUDE Irvine32.inc

.data
grade BYTE ?, 0
gradeA BYTE "A", 0
gradeB BYTE "B", 0
gradeC BYTE "C", 0
gradeD BYTE "D", 0
gradeF BYTE "F", 0
outputString BYTE ": The letter grade is ", 0
	
.code
main PROC
	;To reseed random number generator
	call Randomize

	;Counter for L1 loop
	mov ecx, 10

;Randomly generate a number between 50 and 100
L1: 
	;Because RandomRange generates between 0 to n-1
	mov eax, 51
	call RandomRange
	;Add 50 to make it from 0 to 50 to 50 to 100
	add eax, 50

	call WriteInt
	mov edx, OFFSET outputString
	call WriteString

	;Now that eax has a random value, we call GradeCalc
	call GradeCalc

	mov edx, 0
	;Output value
	mov grade, al
	call WriteChar
	call Crlf
	loop L1
    exit

main ENDP

;Uses Runtime expressions to associate random number to grade letter
;Store grade in al
GradeCalc PROC
	.IF (eax <= 100) && (eax > 89)
		mov al, gradeA
	.ELSEIF (eax < 90) && (eax > 79)
		mov al, gradeB
	.ELSEIF (eax < 80) && (eax > 69)
		mov al, gradeC
	.ELSEIF (eax < 70) && (eax > 59)
		mov al, gradeD
	.ELSE
		mov al, gradeF
	.ENDIF 

	ret

GradeCalc ENDP
END main
