#include <iostream>
#include <math.h>

int main() {
    int n;
    double cole = 500.0;
    double rectangle_cap = 6.0;
    double rectangle_wide = 9.0;
    double pi = 3.141593;
    int r = 5;
    int r1 = 4, r2 = 10;
    double v = 4.0 / 3 * pi * r1 * r1 * r1 + 4.0 / 3 * pi * r2 * r2 * r2;

    std::cin >> n;
    switch (n) {
        case 1:
            std::cout << "I love Luogu!";
            break;
        case 2:
            std::cout << 2 + 4 << " " << 10 - 2 - 4;
            break;
        case 3:
            std::cout << 14 / 4 << std::endl << (14 / 4) * 4 << std::endl << (14 - ((14 / 4) * 4));
            break;
        case 4:
            // iomanip
            std::cout << 500.0 / 3 << std::endl;
            break;
        case 5:
            std::cout << (260 + 220) / (20 + 12);
            break;
        case 6:
            std::cout << sqrt(rectangle_cap * rectangle_cap + rectangle_wide * rectangle_wide);
            break;
        case 7:
            std::cout << 100 + 10 << std::endl;
            std::cout << 100 + 10 - 20 << std::endl;
            std::cout << 0;
            break;
        case 8:
            std::cout << 2 * r * pi << std::endl;
            std::cout << r * r * pi << std::endl;
            std::cout << 4.0 / 3.0 * pi * r * r * r;
            break;
        case 9:
            std::cout << (((1 + 1) * 2 + 1) * 2 + 1) * 2;
            break;
        case 10:
            std::cout << 9 << std::endl;
            break;
        case 11:
            std::cout << 100.0 / (8 - 5) << std::endl;
            break;
        case 12:
            std::cout << 'M' - 'A' + 1 << std::endl;
            std::cout << char('A' - 1 + 18) << std::endl;
            break;
        case 13:
            v = pow(v, 1.0 / 3);
            printf("%.0lf\n", v);
            break;
        case 14:
            std::cout << 50 << std::endl;
            break;
    }

    return 0;
}