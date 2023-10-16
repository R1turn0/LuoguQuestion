#include <stdio.h>

int demo_asm()
{
    /* asm, part 1 */
    asm volatile(
                "subq $0x50, %%rsp\n\t"
                "popq %%rax\n\t"
                "popq %%rax\n\t"
                "popq %%rax\n\t"
                "popq %%rax\n\t"
                "popq %%rax\n\t"   /* pop five times */
                :
                :
                :"rsp", "rax");

    return 0;
}

int main()
{
    demo_asm();
    return 0;
}