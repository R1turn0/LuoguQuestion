#include<iostream>

long long gcd(long long,long long);

int main()
{
    long long maxn, minn;   //分别为斜边以及最短边
    long long a, b, c;      //由于数据出了int范围，所以用long long
    std::cin >> a >> b >> c;

    minn = a;               //假设a为最小数
    if (b < minn)
        minn = b;           //一旦小于最小数，就替换
    if (c < minn)
        minn = c;           //同上

    maxn = a;               //道理同上，只是改为了最大数判断
    if (b > maxn)
        maxn = b;
    if (c > maxn)
        maxn = c;

    std::cout << gcd(minn, maxn) << "/" << gcd(maxn, minn);
    return 0;
}

long long gcd(long long a,long long b)
{
    long long aa = a, bb = b;
    while (aa != bb)
    {
        if (aa > bb)
        {
            aa = aa - bb;
        }
        else
        {
            bb = bb - aa;
        }
    }
    return a/aa;
}