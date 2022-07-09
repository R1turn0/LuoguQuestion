#include <iostream>

long long factorial(int n) {
    if(n == 1)
        return 1;
    return n * factorial(n-1);
}

int main() {
    int n = 0;
    std::cin >> n;
    long long num = factorial(n);   // 三年OI一场梦 不开long long见祖宗
    std::cout << num << std::endl;
    return 0;
}
