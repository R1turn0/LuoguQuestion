.386
.model flat, stdcall
option casemap :none

include C:\masm32\include\msvcrt.inc
include C:\masm32\include\kernel32.inc
include C:\masm32\macros\macros.asm

includelib C:\masm32\lib\msvcrt.lib
includelib C:\masm32\lib\kernel32.lib

.data
prompt db "Enter the value of 'a': ", 0
format db "%d", 0
js_format db "js: %d", 10, 0

.data
    a DWORD ?
    p DWORD 0
    js DWORD 0
    q DWORD 100 DUP(0)

.code
main PROC
    ; Prompt and read the value of 'a'
    invoke crt_printf, ADDR prompt
    invoke crt_scanf, ADDR format, ADDR a

    ; Read values of 'q[y]' and calculate 'p'
    mov ecx, 0
    mov esi, OFFSET q
    mov edx, a
read_loop:
    invoke crt_scanf, ADDR format, [esi+ecx*4]
    add p, [esi+ecx*4]
    inc ecx
    loop read_loop

    ; Calculate average 'p'
    cdq
    idiv a

    ; Subtract 'p' from each element of 'q'
    mov ecx, 0
    mov esi, OFFSET q
    mov edx, a
subtract_loop:
    sub [esi+ecx*4], eax
    inc ecx
    loop subtract_loop

    ; Calculate 'js'
    mov ecx, 0
    mov esi, OFFSET q
    mov edx, a
calc_js_loop:
    mov eax, [esi+ecx*4]
    cmp eax, 0
    je skip_increment
    add [esi+(ecx+1)*4], eax
    inc js
skip_increment:
    inc ecx
    loop calc_js_loop

    ; Print the value of 'js'
    invoke crt_printf, ADDR js_format, js

    invoke crt_getch
    mov eax, 0
    ret
main ENDP


end main