#include <iostream>
#include <cmath>

int main() {
    int n;
    scanf_s("%d", &n, sizeof(int));
    printf("%.2f", (pow(((1 + sqrt(5)) / 2), n) - pow(((1 - sqrt(5)) / 2), n)) / sqrt(5));
    return 0;
}

// 直接算斐波那契数列（阿偶~，相比之下上边那种直接开出来不好吗？
//int main() {
//    int n;
//    long long a = 1, b = 1, c = 0;
//    std::cin >> n;
//    if (n == 1 || n == 2) { std::cout << 1 << ".00" << std::endl; return 0; }
//    for (int i = 0; i < n - 2; i++) {
//        c = a + b;
//        a = b; b = c;
//    }
//    std::cout << c << ".00" << std::endl;
//    return 0;
//}
