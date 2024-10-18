#include <iostream>

int main() {
    int n;
    std::cin >> n;
    if (11 + 3 * n < 5 * n)
        std::cout << "Luogu" << std::endl;
    else
        std::cout << "Local" << std::endl;
    return 0;
}
