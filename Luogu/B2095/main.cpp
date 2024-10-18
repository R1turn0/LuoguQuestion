#include<bits/stdc++.h>

int n;
double a[310];

int main() {
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    std::sort(a + 1, a + n + 1);
    double jas = 0;//计数器
    for (int i = 2; i < n; i++)
        jas += a[i];
    std::cout << std::fixed << std::setprecision(2) << jas / (n - 2) << " "
         << std::max(fabs(a[2] - jas / (n - 2)), fabs(a[n - 1] - jas / (n - 2)));
    return 0;
}
