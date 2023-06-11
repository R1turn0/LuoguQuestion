#include <iostream>

int num[101];

int main() {
    int n, age = 0, tmp = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> num[i];
        age += num[i];
    }
    age /= n;
    for (int i = 0; i < n; i++) {
        num[i] -= age;
    }

    return 0;
}

/*
 *  1 -1 4 -2 -1
 */
