#include <iostream>

int main() {
    int day, pich = 1;
    std::cin >> day;
    for (int i = 0; i < day - 1; i++) {
        pich = (pich + 1) * 2;
    }
    std::cout << pich << std::endl;
    return 0;
}
