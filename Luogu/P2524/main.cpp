#include <bits/stdc++.h>

const int fac[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};//阶乘

inline int Contor(char s[], int n) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
//        std::cout << ans << std::endl;
        int smaller = 0;
        for (int j = i + 1; j < n; j++)
            if (s[i] > s[j])
                smaller++;
        ans += smaller * fac[n - i - 1];
    }
    return ans + 1;
}

int main() {
    int n;
    char s[108];

    std::cin >> n >> s;
    std::cout << Contor(s, n);
}

/*
 * 字典序：123 > 132 > 213 > 231 > 312 > 321
 */