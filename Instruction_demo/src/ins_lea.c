#include <stdio.h>

int demo_asm()
{
    /* variable definition */
    long result;
    long __memory;

    /* Initiation */
    __memory = 0x20;        // It will be changed.

    /* asm, part 1 */
    asm volatile(
                "leaq %1, %0\n\t"
                :"=r"(result)
                :"m"(__memory)
                :);
    printf("__memory: %#lx\n", result);

    return 0;
}

int main()
{
    demo_asm();
    return 0;
}