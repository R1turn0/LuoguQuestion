#include <iostream>

int main() {
    int n, k;
    int i = 1;
    std::cin >> n >> k;
    while (true) {
        int tmp = (n - k) / 2;
        if (tmp <= 0)
            break;
        n = n - tmp;
        i++;
    }
    std::cout << i << std::endl;
    return 0;
}
