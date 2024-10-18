#include <iostream>

int main() {
    int x;
    std::cin >> x;
    if (x == 1 || x == 0)
        std::cout << "Today, I ate " << x << " apple." << std::endl;
    else
        std::cout << "Today, I ate " << x << " apples." << std::endl;
    return 0;
}
