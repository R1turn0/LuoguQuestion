#include <iostream>
#include <stack>
#include <cmath>

long long k, n, ans;
std::stack<int> S;

int main() {
    std::cin >> k >> n;
    while (n) S.push(n & 1), n >>= 1;
    while (!S.empty()) ans += S.top() * pow(k, S.size() - 1), S.pop();
    std::cout << ans << std::endl;
    return 0;
}