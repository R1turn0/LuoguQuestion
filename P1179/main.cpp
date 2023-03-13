#include <iostream>

int main() {
    int l, r;
    int sum = 0;
    std::cin >> l >> r;
    for (int i = l; i <= r; i++) {
        int tmp = i;
        while (tmp != 0) {
            if (tmp % 10 == 2) sum++;
            tmp /= 10;
        }

    }
    std::cout << sum << std::endl;
    return 0;
}
