#include <iostream>

int main() {
    int n;
    int sun = 0;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        sun += i;
    }
    std::cout << sun;
    return 0;
}
