#include <cstdio>
#include "func.h"

int main(int argc, char* argv[])
{
    int p = 0, q = 0;
    int N = 0;
    int L = 0;
    int E = 0;

    while (true)
    {
        p = prime_rand();
        q = prime_rand();
        if (p != q)
            break;
    }
    N = p * q;
    L = LCM(p, q);
    E = GCD(L);

    printf("p = %d, q = %d\n", p, q);
    printf("N = %d\n", N);
    printf("L = %d\n", L);
    printf("E = %d\n", E);

    system("pause");
    return 0;

}