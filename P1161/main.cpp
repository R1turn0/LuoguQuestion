#include <iostream>

static int light[2000000];
double a;
int t;

int main() {
    int n;
    std::cin >> n;
    while (n--) {
        std::cin >> a >> t;
        for (int i = 1; i <= t; i++) {
            light[(int)(a * i)] = !light[(int)(a * i)];
        }
    }
    for (int i = 1; ;i++) {
        if (light[i] == 1) {
            std::cout << i;
            break;
        }
    }
    return 0;
}
