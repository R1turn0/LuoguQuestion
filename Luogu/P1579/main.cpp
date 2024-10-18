#include <iostream>

bool is_prime_numbers(int num);

int main() {
    int n;
    std::cin >> n;
    for (int i = 2; i < n / 3; i++) {
        if (!is_prime_numbers(i)) continue;
        for (int j = i; j < n / 3; j++) {
            if (!is_prime_numbers(j)) continue;
            int k = n - i - j;
            if (is_prime_numbers(k)) {
                std::cout << i << " " << j << " " << k << std::endl;
                return 0;
            }
        }
    }

    return 0;
}

bool is_prime_numbers(int num) {
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}
