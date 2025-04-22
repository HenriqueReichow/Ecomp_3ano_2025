%include "io.inc"

section .text
global CMAIN
CMAIN:
    mov ecx, [numX]
    mov eax, 1
    loop:
        imul eax,ecx
        sub ecx, 1
        jnz loop
    PRINT_UDEC 4,eax
    ret
    
section .data
numX DD 4