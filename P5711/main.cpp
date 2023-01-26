#include <iostream>

int main() {
    short year = 0;
    scanf("%4hd", &year);

    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                std::cout << '1';
                return 0;
            }
        }
    }
    std::cout << '0';

    return 0;
}
