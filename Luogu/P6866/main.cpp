#include <cstdio>

int n, m, ans;
char a[100][100];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%s", a[i]);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (a[i][j] == '*' && (!i || a[i - 1][j] == '.') && (!j || a[i][j - 1] == '.'))
                ++ans;
    printf("%d", ans);
    return 0;
}
