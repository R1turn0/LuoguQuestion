#include <stdio.h>

int demo_asm()
{
    /* asm, part 1 */
    asm volatile(
                "pushq %%rax\n\t"
                "pushq %%rax\n\t"
                "pushq %%rax\n\t"
                "pushq %%rax\n\t"
                "pushq %%rax\n\t"   /* push five times */
                :
                :
                :"rsp");

    return 0;
}

int main()
{
    demo_asm();
    return 0;
}