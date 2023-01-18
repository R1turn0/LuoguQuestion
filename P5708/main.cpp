#include <iostream>
#include "math.h"

int main() {
    int a, b, c;
    double p;
    double S;

    std::cin >> a >> b >> c;
    p = 0.5 * (a + b + c);
    S = sqrt(p * (p - a) * (p - b) * (p - c));
    printf("%.1f", S);

    return 0;
}
