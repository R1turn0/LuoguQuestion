#include <bits/stdc++.h>

static int pixel[10000];
static int outPixel[10000];

int main() {
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < n * m; i++) {
        std::cin >> pixel[i];
        outPixel[i] = pixel[i];
    }
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            outPixel[i * m + j] = floor((pixel[i * m + j] + pixel[(i - 1) * m + j] + pixel[(i + 1) * m + j] \
                    + pixel[i * m + (j - 1)] + pixel[i * m + (j + 1)]) * 1.0 / 5 + 0.5);
        }
    }
    for (int i = 0; i < n * m; i++) {
        if (i % m == 0 && i != 0)
            std::cout << std::endl;
        std::cout << outPixel[i] << " ";
    }

    return 0;
}
