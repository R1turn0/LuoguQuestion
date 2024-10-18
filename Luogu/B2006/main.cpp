#include <iostream>
#include<bits/stdc++.h>

int main() {
    double x, a, y, b;
    std::cin >> x >> a >> y >> b;
    std::cout << std::fixed << std::setprecision(2) << (x * a - y * b) / (a - b) << std::endl;
    return 0;
}
