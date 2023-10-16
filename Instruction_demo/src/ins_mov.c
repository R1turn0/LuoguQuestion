#include <stdio.h>

int demo_asm()
{
    /* variable definition */
    long __register, __register_output;
    long __memory, __memory_output;

    /* Initiation */
    __register = 0xffff;
    __register_output = 0;  // result is 0x60
    __memory = 0x20;        // It will be changed.
    __memory_output = 0x20;

    /* asm, part 1 */
    asm volatile(
                "movq %1, %2\n\t"           /* reg to memory **********************/
                "movq $0xffff, %1\n\t"      /* restore reg ************************/
                "movq %1, %%rsi\n\t"        /* reg to reg(rsi) ********************/
                "movq %2, %%rsi\n\t"        /* mem to reg(rsi) ********************/
                "nop\n\t"                   /* mem to mem, fail! ******************/
                "movq $0x60, %0\n\t"        /* imm to reg *************************/
                :"=r"(__register_output)
                :"D"(__register),"m"(__memory)
                :"rsi");
    printf("__memory: %#lx\n", __memory); // should be 0xffff

    /* asm, part 2 */
    asm volatile(
                "movq $0x1111, %0\n\t"      /* imm to mem *************************/
                :"=m"(__memory_output)
                :
                :
    );
    printf("__memory_output: %#lx\n", __memory_output); // should be 0x1111

    return 0;
}

int main()
{
    demo_asm();
    return 0;
}