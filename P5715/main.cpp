#include <iostream>

int main() {
    int num[3];

    std::cin >> num[0] >> num[1] >> num[2];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3 - i - 1; j++) {
            if (num[j] > num[j + 1]) {
                int temp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = temp;
            }
        }
    }
    for (int i: num) {
        std::cout << i << " ";
    }

    return 0;
}