#include <iostream>

int main() {
    int n, temp = 0, sum = 0;
    int a, b;
    std::cin >> n >> a;
    for (int i = 0; i < n - 1; i++) {
        std::cin >> b;
        if (b == a + 1) {
            temp++;
        } else {
            if (temp > sum) sum = temp;
            temp = 0;
        }
        a = b;
    }
    if (temp > sum) sum = temp;
    std::cout << ++sum;
    return 0;
}
