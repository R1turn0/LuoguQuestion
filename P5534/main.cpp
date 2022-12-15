#include <iostream>

int main() {
    long long num1, num2;
    long long n;
    std::cin >> num1 >> num2 >> n;
    std::cout << (num1 + ((num2 - num1) * (n - 1) + num1)) * n / 2 << std::endl;

    return 0;
}
