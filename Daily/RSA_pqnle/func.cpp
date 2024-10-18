#include "func.h"

__declspec(dllexport) int prime_rand()
{
    int flag = 1;
    int num = 0;
    int i = 0;

    //srand(time(NULL));
    //========代码碎片保护========
    num = rand() % 100;
    if (num < 2)
    {
        return prime_rand();
    }
    for (i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            break;
        }
    }
    if (i >= num)
    {
        return num;
    }
    else
    {
        return prime_rand();
    }
}

__declspec(dllexport) int LCM(int p, int q)// 最小公倍数
{
    int L = 0;
    int i = 0;

    //========代码虚拟化保护========
    p -= 1;
    q -= 1;
    for (i = 1; ; i++)
    {
        if (i % p == 0 && i % q == 0)
        {
            break; 
        }
    }
    return i;
}

__declspec(dllexport) int GCD(int L)// 最大公约数
{
    int tmp = 0;
    int E = rand();
    int n, m;
    if (E > L)
    {
        return GCD(L);
    }
    m = E;
    n = L;
    while (n % m)
    {
        tmp = n % m;
        n = m;
        m = tmp;
    }
    tmp = m;
    if (tmp != 1)
    {
        return GCD(L);
    }
    return E;
}
