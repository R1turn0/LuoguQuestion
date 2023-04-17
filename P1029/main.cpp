#include <iostream>
#include <bits/stdc++.h>

long long m, n, ans;

int main() {
    std::cin >> m >> n;
    if (m == n) ans--;
    n *= m;
    for (long long i = 1; i <= sqrt(n); i++)
        if (n % i == 0 && std::__gcd(i, n / i) == m) ans += 2;
    std::cout << ans;
    return 0;
}

/*
 * Problem:
 * x*y=P*Q
 * gcd(x,y)=P 最大公约数
 * lcm(x,y)=Q 最小公倍数
 *
 * Tip:两个数的积等于它们最大公约数和它们最小公倍数的积
 */