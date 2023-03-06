#include <iostream>

int a[20][20];

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        a[i][0] = a[i][i] = 1;
        for (int j = 1; j < i; j++) {
            a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
