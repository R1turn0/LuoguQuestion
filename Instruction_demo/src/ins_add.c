#include <stdio.h>

int demo_asm()
{
    long var;

    /* asm, part 1 */
    asm volatile(
                "movq %%rsp, %0"
                :"=r"(var)
                :
                :);
    printf("stack: %#lx\n", var);

    /* asm, part 2 */
    asm volatile(
                "addq $0x10, %%rsp\n\t"
                "movq %%rsp, %0\n\t"
                :"=r"(var)
                :
                :"rsp");
    printf("stack: %#lx\n", var);

    return 0;
}

int main()
{
    printf("Instruction ADD\n");
    demo_asm();
    return 0;
}