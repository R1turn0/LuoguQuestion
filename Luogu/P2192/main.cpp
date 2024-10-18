#include <iostream>

int main() {
    int n, num;
    int five = 0, zero = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> num;
        if (num == 5) five++;
        else if (num == 0) zero++;
    }
    if (zero == 0) std::cout << "-1" << std::endl;
    else if (five < 9) std::cout << "0" << std::endl;
    else {
        for (int i = 0; i < five - (five % 9); i++) std::cout << "5";
        for (int i = 0; i < zero; i++) std::cout << "0";
    }
    return 0;
}
