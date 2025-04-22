%include "io.inc"

section .text
global CMAIN
CMAIN:
    mov eax, [numX]
    cmp eax, 2
    jl nao_primo
    
    cmp eax,2
    je primo
    
    mov ebx, 2

.loop:
    mov eax, [numX]      
    xor edx, edx      
    div ebx
    cmp edx, 0
    je nao_primo

    inc ebx
    cmp ebx, [numX]
    jl .loop

primo:
    PRINT_CHAR 'S'
    PRINT_CHAR 'I'
    PRINT_CHAR 'M'
    ret

nao_primo:
    PRINT_CHAR 'N'
    PRINT_CHAR 'A'
    PRINT_CHAR 'O'
    ret

section .data
numX DD 17