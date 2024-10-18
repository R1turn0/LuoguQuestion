#include <cstdio>

int n, m, k;
int tot[1004], vis[1004][1004], a[1004][1004];

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            scanf("%d", &a[i][j]);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (!vis[j][a[i][j]]) {
                vis[j][a[i][j]] = 1;
                tot[a[i][j]]++;
            }
        }
    }
    for (int i = 1; i <= k; ++i)
        printf("%d ", tot[i]);
    return 0;
}