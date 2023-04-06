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

// https://blog.csdn.net/qq_30115697/article/details/88906534?spm=1001.2101.3001.6661.1&utm_medium=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-1-88906534-blog-81105031.235%5Ev27%5Epc_relevant_recovery_v2&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-1-88906534-blog-81105031.235%5Ev27%5Epc_relevant_recovery_v2&utm_relevant_index=1