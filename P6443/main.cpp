#include <iostream>

int main() {
    int m, n, k;
    int ans = 0;
    std::cin >> m >> n >> k;

    while (k) {
        if ((m / 2) >= n)
            m -= 1;
        else
            n -= 1;
        k -= 1;
    }

    for (ans = 0; ; ans++) {
        if (m == 0 || n == 0)
            break;
        m -= 2;
        n--;
    }

    std::cout << ans << std::endl;
    return 0;
}
