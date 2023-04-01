#include <iostream>

int n, k, cnt;

void dfs(int last, int sum, int cur) {
    if (cur == k) {
        if (sum == n) cnt++;
        return;
    }
    // 剪枝，只用枚举到sum+i*(k-cur)<=n为止
    for (int i = last; sum + i * (k - cur) <= n; i++) {
        dfs(i, sum + i, cur + 1);
    }
}

int main() {
    std::cin >> n >> k;
    dfs(1, 0, 0);
    std::cout << cnt;
    return 0;
}
