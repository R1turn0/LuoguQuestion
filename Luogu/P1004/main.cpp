#include <iostream>
#include <algorithm>

int way[11][11][11][11];
int f[11][11];

int main() {
    int n;
    int x, y;
    int z;
    int *maze;

    std::cin >> n;
    maze = (int *) calloc((n * n) * sizeof(int), ((n + 1) * (n + 1)) * sizeof(int));

    while (true) {
        std::cin >> x >> y >> z;
        if (!x && !y && !z)
            break;
        maze[(x) * n + (y)] = z;
    }

//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= n; j++) {
//            for (int k = 1; k <= n; k++) {
//                z = i + j - k;
//                if (z <= 0) {
//                    break;
//                }
//                way[i][j][k][z] = std::max(way[i - 1][j][k - 1][z],
//                                           std::max(way[i - 1][j][k][z - 1],
//                                                    std::max(way[i][j - 1][k - 1][z], way[i][j - 1][k][z - 1])));
//                if (i == k && j == z) {
//                    way[i][j][k][z] += maze[i * n + j];
//                } else {
//                    way[i][j][k][z] += maze[i * n + j] + maze[k * n + z];
//                }
//            }
//        }
//    }
//    printf("%d\n", way[n][n][n][n]);

    // ======== 01背包 ========
    for (int l = 2; l <= n * 2; l++)//每个点最少横着竖着都走一格，最多都走n格就到终点
        for (int i = l - 1; i >= 1; i--)//和前面说的一样，倒着做
            for (int ii = l - 1; ii >= 1; ii--) {
                int j = l - i;
                int jj = l - ii;//i+j=ii+jj=l
                f[i][ii] = std::max(std::max(f[i][ii], f[i - 1][ii - 1]),
                                    std::max(f[i - 1][ii], f[i][ii - 1])) + maze[i * n + j];
                //重点说明一下吧，这里省略了很多。如果i不减1，意思就是j-1，因为上一个阶段就是l-1嘛。如果ii-1，意思就是说jj不减1。
                f[i][ii] += maze[ii * n + jj] * (i != ii);
                //如果i==ii，其实就是(i==ii&&j==jj)，因为和都是l嘛。如果走过一遍，第二遍走得到的值就是0（题目上说的）。
            }
    printf("%d\n", f[n][n]);
    //输出意思是在路径长度为2*n的阶段，两遍都走到(n,n)的最优值。因为在这里(j=2*n-i=n,jj=2*n-ii=n),所以走到的就是(n,n)的位置

    return 0;
}


////方格取数~深搜  ～(￣▽￣～)(～￣▽￣)～
//#include<iostream>
//    using namespace std;
//    int N=0;
//    int s[15][15],f[11][11][11][11];
//int dfs(int x,int y,int x2,int y2)//两种方案同时执行，表示当第一种方案走到x,y,第二种方案走到x2,y2时到终点取得的最大数
//{
//    if (f[x][y][x2][y2]!=-1) return f[x][y][x2][y2];//如果这种情况已经被记录过了，直接返回，节省时间
//    if (x==N&&y==N&&x2==N&&y2==N) return 0;//如果两种方案都走到了终点，返回结束
//    int M=0;
//    //如果两种方案都不在最后一列，就都往下走，统计取得的数，如果有重复，就减去一部分
//    if (x<N&&x2<N) M=max(M,dfs(x+1,y,x2+1,y2)+s[x+1][y]+s[x2+1][y2]-s[x+1][y]*(x+1==x2+1&&y==y2));
//    //如果第一种方案不在最后一行，第二种方案不在最后一列，第一种就向下走，第二种就向右走，
//    //统计取得的数，如果有重复，就减去一部分
//    if (x<N&&y2<N) M=max(M,dfs(x+1,y,x2,y2+1)+s[x+1][y]+s[x2][y2+1]-s[x+1][y]*(x+1==x2&&y==y2+1));
//    //如果第一种方案不在最后一列，第二种方案不在最后一行，第一种就向右走，第二种就向下走，
//    //统计取得的数，如果有重复，就减去一部分
//    if (y<N&&x2<N) M=max(M,dfs(x,y+1,x2+1,y2)+s[x][y+1]+s[x2+1][y2]-s[x][y+1]*(x==x2+1&&y+1==y2));
//    //如果第一种方案和第二种方案都不在最后一列，就都向右走，统计取得的数，如果有重复，就减去一部分
//    if (y<N&&y2<N) M=max(M,dfs(x,y+1,x2,y2+1)+s[x][y+1]+s[x2][y2+1]-s[x][y+1]*(x==x2&&y+1==y2+1));
//    //对最后那个 s[x][y+1]*(x==x2&&y+1==y2+1))的解释：这个是用来判断两种方案是不是走到了同一格的
//    //如果是真，就返回1，否则返回0，如果是1的话，理所当然的可以减去s[x][y+1]*1,否则减去s[x][y+1]*0相当于
//    //不减,写得有点精简，省了4个if，见谅哈~
//    f[x][y][x2][y2]=M;//记录这种情况
//    return M;//返回最大值
//}
//int main()
//{
//    cin>>N;
//    //将记录数组初始化成-1，因为可能出现取的数为0的情况，如果直接判断f[x][y][x2][y2]!=0（见dfs第一行）
//    //可能出现死循环而导致超时，细节问题
//    for(int a=0;a<=N;a++)
//      for(int b=0;b<=N;b++)
//        for(int c=0;c<=N;c++)
//          for(int d=0;d<=N;d++) f[a][b][c][d]=-1;
//    for(;;)//读入
//    {
//        int t1=0,t2=0,t3=0;
//        cin>>t1>>t2>>t3;
//        if(t1==0&&t2==0&&t3==0) break;
//        s[t1][t2]=t3;
//    }
//    cout<<dfs(1,1,1,1)+s[1][1];//输出，因为dfs中没有考虑第一格，即s[1][1]，所以最后要加一下
//    return 0;
//}