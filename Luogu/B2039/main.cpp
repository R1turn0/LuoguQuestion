#include <iostream>

int main() {
    int num1, num2;
    std::cin >> num1 >> num2;
    if (num1 > num2)
        std::cout << ">";
    else if (num1 == num2)
        std::cout << "=";
    else
        std::cout << "<";
    return 0;
}
