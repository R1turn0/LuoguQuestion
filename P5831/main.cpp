#include <iostream>
#include <cstring>

int main()
{
    int N = 0; // 一个不大于 9 的正整数 nn，输出 n\times nn×n 的蛇形方阵
    std::cin >> N;
    int matrix[N][N];
    memset(matrix, 0, sizeof(matrix));
    int n = N; // n用于保存循环数
    int row = 0; // 行
    int col = 0; // 列
    int start = 1; // 填充数
    for (int count = 0; count < n; count++)
    {
        for (; col < n - 1; col++) // 上
            matrix[row][col] = start++;
        for (; row < n - 1; row++) // 右
            matrix[row][col] = start++;
        for (col = n - 1; col > count; col--) // 下
            matrix[row][col] = start++;
        for (row = n - 1; row > count; row--) // 左
            matrix[row][col] = start++;
        n--; // 外圈循环结束后循环次数 -1
        start--; // 循环结束后start为什么会 +1 ？
        row++;
    }
    if (N % 2 != 0)
        matrix[N / 2][N / 2] = ++start;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%3d", matrix[i][j]);
        std::cout << std::endl;
    }
    return 0;
}
