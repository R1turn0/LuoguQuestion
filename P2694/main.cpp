#include <iostream>

static int x[51], y[51];

int main() {
    int g, n;
    std::cin >> g;
    while (g--) {
        int fj_x = 0;
        bool is_win = true;
        std::cin >> n;
        for (int i = 0; i < n; i++) {
            std::cin >> x[i] >> y[i];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (y[j] > y[j + 1]) {
                    int temp = y[j + 1];
                    y[j + 1] = y[j];
                    y[j] = temp;
                    temp = x[j + 1];
                    x[j + 1] = x[j];
                    x[j] = temp;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            int dist = x[i] - fj_x;
            dist = (dist ^ (dist >> 31)) - (dist >> 31); // 绝对值((x ^ (x >> 31)) - (x >> 31))
            for (int z = i - 1; z >= 0; z--) y[i] -= y[z];
            if (dist > y[i]) {
                is_win = false;
                std::cout << "Notabletocatch" << std::endl;
                break;
            }
            fj_x = x[i];
        }
        if (is_win) std::cout << "Abletocatch" << std::endl;
    }
    return 0;
}
