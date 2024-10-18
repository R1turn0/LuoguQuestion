#include<cstdio>

int ans, a[42], x;

int main() {
    for (int i = 1; i <= 10; i++)//循环（十个数）十次
    {
        scanf("%d", &x);//输入
        a[x % 42] = 1;//记录进桶
    }
    for (int i: a)
        //枚举，记住0也要枚举，0或42的倍数%42都等于0
        if (i) ans++; //计数器+1
    printf("%d", ans);//愉快输出
    return 0;
}
