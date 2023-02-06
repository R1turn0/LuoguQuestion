#include<iostream>

int fib(int n)
{
    if (n <= 2)
        return 1;
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    int a, n, m, x; //车人数a，车站数n，终点站下车人数m，所求的站点编号x
    int an, b, bn;

//    for (int i = 1; i <= 10; i++)
//	    printf("%d ", fib(i));
//    std::cout << std::endl;

    std::cin >> a >> n >> m >> x;
    an = fib((n - 1) - 2) + 1;
    bn = fib((n - 1) - 1) - 1;
    b = (m - an * a) / bn;

    x = (fib(x - 2) + 1) * a + (fib(x - 1) - 1) * b;
    std::cout << x;

	return 0;
}

/*
 * 1: a
 * 2: a         +b          -b          =a
 * 3: a         +(a+b)      -b          =a
 * 4: 2a        +(a+2b)     -(a+b)      =2a+b
 * 5: 2a+b      +(2a+3b)    -(a+2b)     =3a+2b
 * 6: 3a+2b     +(3a+5b)    -(2a+3b)    =4a+4b
 * 7: 4a+4b     +(5a+8b)    -(3a+5b)    =6a+7b
 * 8: 6a+7b     +(8a+13b)   -(5a+8b)    =9a+12b
 * 9: 9a+12b    +(13a+21b)  -(8a+13b)   =14a+20b
 * ...
 * n:
 */


//#include<cstdio>
//
//using namespace std;
//int sum1[25], sum2[25];//a和b的系数
//int main() {
//    int a, n, m, x;
//    scanf("%d%d%d%d", &a, &n, &m, &x);
//    sum1[2] = 1, sum1[3] = 2;//初始化
//    for (int i = 4; i < n; i++) {//遍历（必须从4开始，前面没有规律）
//        sum1[i] = sum1[i - 1] + sum1[i - 2] - 1;//计算系数，见上
//        sum2[i] = sum2[i - 1] + sum2[i - 2] + 1;
//    }
//    int b = (m - a * sum1[n - 1]) / sum2[n - 1];//公式
//    printf("%d", a * sum1[x] + b * sum2[x]);
//    return 0;//华丽结束
//}

