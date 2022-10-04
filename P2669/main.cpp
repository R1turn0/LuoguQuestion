#include <iostream>

int main() {
    int day, wages = 1, money = 0;
    int i;
    std::cin >> day;
    for (i = 0; i < day; i++) {
        money += (wages * wages);
        day -= wages;
        wages++;
    }
    std::cout << money + day * (i + 1);
    return 0;
}
