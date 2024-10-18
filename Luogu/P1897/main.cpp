#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, tmp;
    int a[100001];
    int fri = 0, nex = 0;
    int time, sun;

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n - i - 1; j++) {
//            if (a[j] > a[j + 1]) {
//                tmp = a[j];
//                a[j] = a[j + 1];
//                a[j + 1] = tmp;
//            }
//        }
//    }

    std::sort(a, a + n);
    sun = n;
    for (int i = 0; i < n; i++) {
        if (a[i] == a[i + 1])
            sun--;
    }
    time = a[n - 1] * (6 + 4) + sun * 5 + n;
    std::cout << time;

    return 0;
}
