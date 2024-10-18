#include <iostream>
#include <bits/stdc++.h>

int n;
int x[100], y[100];

bool cmp(const int &a, const int &b) {
    return a > b;
}

//int mrp(int *a) {
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n - i - 1; j++) {
//            if (a[j] > a[j + 1]) {
//                int tmp = a[j];
//                a[j] = a[j + 1];
//                a[j + 1] = tmp;
//            }
//        }
//    }
//    return 0;
//}

int main() {
    std::cin >> n;
    for (int i = 0; i < n; i++) std::cin >> x[i];
    for (int i = 0; i < n; i++) std::cin >> y[i];
    std::sort(x, x + n, cmp);
    std::sort(y, y + n, cmp);
    for (int i = 0; i < n; i++) {
        if (x[i] > y[i]) {
            std::cout << "NE";
            return 0;
        }
    }
    std::cout << "DA";
    return 0;
}
