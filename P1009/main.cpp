#include <iostream>

long long fact(long long, long long);

int main() {
    int n;
    long long num = 0;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        num += fact(1, i);
    }
    std::cout << num << std::endl;
    return 0;
}

long long fact(long long num, long long n) {
    num = num * n;
    if (n - 1 == 0)
        return num;
    return fact(num, n - 1);
}