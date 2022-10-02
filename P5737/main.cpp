#include <iostream>
#include <vector>

int main() {
    int x, y, year, num = 0;
    std::vector<int> leap;
    std::cin >> x >> y;
    year = x;

    for (int i = 0; i < (y - x) + 1; i++, year++) {
        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
            leap.push_back(year);
            num++;
        }
    }

    std::cout << num << std::endl;
    for (int i : leap) {
        std::cout << i << " ";
    }
    return 0;
}
