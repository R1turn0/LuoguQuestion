#include <iostream>

int main() {
    char I;
    std::cin >> I;
    if (I > 90)
        std::cout << (char)(I - 32);
    else
        std::cout << (char)(I + 32);
    return 0;
}
