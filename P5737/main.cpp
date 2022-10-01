#include <iostream>

int main() {
    int x, y, year, num = 0;
    int leap[1000];
    std::cin >> x >> y;
    year = x;

    for (int i = 0; i < (y - x) + 1; i++, year++) {
        if (year % 4 == 0) {
            if (year % 100 != 0 || year % 400 == 0) {
                leap[num] = year;
                num++;
            }
        }
    }

    std::cout << num << std::endl;
    for (int i = 0; i < num; i++) {
        std::cout << leap[i] << " ";
    }
    return 0;
}
