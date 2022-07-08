#include <iostream>

int main() {
    int k = 0, n = 0;
    std::cin >> k;
    double S = 0;
    while(true) {
        n++;
        S += 1.0 / n; // 浮点上下文中使用的整数除法的结果,可能损失精度
        if (S > k)
            break;
    }
    std::cout << n;

return 0;
}


/*
// 欧拉推导过求调和级数有限多项和的表达式
#include<cstdio>
#include<cmath>
const double gamma=0.5772156649;
int main() {
    int k,n;
    scanf("%d",&k);
    n=exp(k-gamma)+0.5;
    printf("%d",n);
    return 0;
}
 * */