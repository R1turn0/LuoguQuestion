//#include <iostream>
//
//int main() {
//    int x = 0, k = 0;
//    int n = 0;
//
//    std::cin >> n;
//    for (k = 1; k < 1000; k++) {
//        for (x = 1; x <= 100; x++) {
//            if ((364 * x + 1092 * k) == n) {
//                std::cout << x << std::endl;
//                std::cout << k << std::endl;
//                return 0;
//            }
//            else if ((364 * x + 1092 * k) > n)
//                break;
//        }
//    }
//}


// ========O(1)========
#include<cstdio>

int read() {//没什么用的快读
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}

int main() {//主函数
    int n = read() / 364;//读入，开始直接/364
    if (n <= 103) printf("%d\n%d\n", n - 3, 1);//k可以取到1的情况
    else {//k不能取1
        if (n % 3 == 0) printf("%d\n%d\n", 99, (n - 99) / 3);//分类讨论，直接输出
        if (n % 3 == 1) printf("%d\n%d\n", 100, (n - 100) / 3);
        if (n % 3 == 2) printf("%d\n%d\n", 98, (n - 98) / 3);
    }
    return 0;//华丽结束
}