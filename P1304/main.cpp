#include <iostream>

int main() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= (n - 2) / 2; i++) {
        std::cout << 2 * i + 2 << "=" << std::endl;
    }
    return 0;
}
