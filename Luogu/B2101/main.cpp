#include <iostream>

static int m, n;
static int temp = 0, sum = 0;

int main() {
    std::cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> temp;
            if (i == 0 || i == m - 1 || j == 0 || j == n - 1) sum += temp;
        }
    }
    std::cout << sum;
    return 0;
}
