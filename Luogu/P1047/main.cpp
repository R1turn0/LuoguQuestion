#include <iostream>
#include <cstring>
#include <array>

int main() {
    int l, m; // 马路的长度 ll 和区域的数目 mm
    std::cin >> l >> m;
    int sum = 0;
    std::array<int, 100000> wanglaoban{};
    wanglaoban.fill(1);
    int u[m], v[m]; // 表示一个区域的起始点和终止点的坐标。
    for (int i = 0; i < m; i++)
        std::cin >> u[i] >> v[i];
    for (int i = 0; i < m; i++)
        for (int j = u[i]; j <= v[i]; j++)
            wanglaoban[j] = 0;
    for (int i = 0; i <= l; i++)
        sum += wanglaoban[i];
    std::cout << sum;

    return 0;
}