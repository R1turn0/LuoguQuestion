#include <iostream>

int main() {
    double t;
    int n;
    std::cin >> t >> n;
    printf("%.3lf\n", (t / n));
    std::cout << n * 2 << std::endl;
    return 0;
}
