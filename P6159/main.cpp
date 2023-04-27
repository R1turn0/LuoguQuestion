#include <iostream>

long long n, p, k;

int main() {
    std::cin >> n >> p >> k;
    std::cout << p * k % n << std::endl;
    return 0;
}
