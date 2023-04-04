#include <cstdio>

int n, f[30];
int main()
{
    //递推实现卡特兰数
    scanf("%d", &n);
    f[0] = 1, f[1] = 1;
    for(int i=2; i<=n; i++)
        for(int j=0; j<i; j++)
            f[i] += f[j] * f[i-j-1];     //递推公式
    printf("%d", f[n]);
    return 0;
}