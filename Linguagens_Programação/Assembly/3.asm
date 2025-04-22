%include "io.inc"
section .text
global CMAIN

END:
    PRINT_CHAR "F"
    PRINT_CHAR "I"
    PRINT_CHAR "M"
    ret
    
CMAIN:
    mov ebx, [numN]
    cmp ebx,1
    jb END
    
    mov ecx, [numN]
    mov eax, 1
    
.loop:
    cmp eax, ecx
    ja END
    
    PRINT_UDEC 4,eax
    PRINT_CHAR " "
    
    add eax, 2
    jmp .loop

section .data
numN DD 3
