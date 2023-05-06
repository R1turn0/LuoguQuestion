#include <iostream>

int main() {
    int a, i = 0;
    std::cin >> a;
    while (a) {
        a /= 2;
        i++;
    }
    std::cout << i;
    return 0;
}
