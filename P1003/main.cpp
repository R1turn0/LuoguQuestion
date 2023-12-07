#include <iostream>

#define MAXN 10005

int a[MAXN], b[MAXN], g[MAXN], k[MAXN];
int x, y;
int result = 0;

int is_cover(int x1, int y1, int x2, int y2);

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
//        std::cin >> a[i] >> b[i] >> g[i] >> k[i];
        scanf_s("%d%d%d%d", &a[i], &b[i], &g[i], &k[i]);
    }
    std::cin >> x >> y;

    for (int i = 0; i < n; i++) {
        if (is_cover(a[i], b[i], a[i] + g[i], b[i] + k[i])) {
            result = i + 1;
        }
    }

//    std::cout << x << " " << y << std::endl;
//    std::cout << (result == 0 ? -1 : result) << std::endl;
    printf("%d", result == 0 ? -1 : result);

    return 0;
}

int is_cover(int x1, int y1, int x2, int y2) {
    if (x1 <= x && y1 <= y && x2 > x && y2 > y)
        return 1;
    else
        return 0;
}
