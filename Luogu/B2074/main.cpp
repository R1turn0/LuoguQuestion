#include <iostream>

int a, b, ans = 1;

int main() {
    std::cin >> a >> b;
    a %= 7;
    for (int i = 1; i <= b; i++) {
        ans *= a;
        ans %= 7;
    }
    switch (ans) {
        case 0:
            std::cout << "Sunday";
            break;
        case 1:
            std::cout << "Monday";
            break;
        case 2:
            std::cout << "Tuesday";
            break;
        case 3:
            std::cout << "Wednesday";
            break;
        case 4:
            std::cout << "Thursday";
            break;
        case 5:
            std::cout << "Friday";
            break;
        case 6:
            std::cout << "Saturday";
            break;
        default:
            break;
    }
    return 0;
}

/*
 * a ≡ b mod c ,则 a × b mod c = ((a mod c) × (b mod c)) mod c
 */