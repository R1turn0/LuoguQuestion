#include<cstdio>

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++)
            putchar(48 | ~i & 1);
        for (int j = i + 1; j <= n; j++)
            putchar(48 | i & 1);
        putchar(10);
    }
    return 0;
}