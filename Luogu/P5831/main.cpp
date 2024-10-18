#include<bits/stdc++.h>

using namespace std;
int k, n, a[25], c = 0;
bool book[25][25];

int main() {
    memset(book, true, sizeof(book));
    cin >> k >> n;
    while (k--)//k天的循环
    {
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) book[a[i]][a[i]] = false;
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
                book[a[j]][a[i]] = false;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (book[i][j])
                c++;
    cout << c;
    return 0;
}