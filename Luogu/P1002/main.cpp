//#include<iostream>
//#include<cstring>
//#include<cstdio>
//#include<algorithm>
//#define ull unsigned long long
//using namespace std;
//
//const int fx[] = {0, -2, -1, 1, 2, 2, 1, -1, -2};
//const int fy[] = {0, 1, 2, 2, 1, -1, -2, -2, -1};
//int bx, by, mx, my;
//ull f[2][40];//第一维大小为 2 就好
//bool s[40][40];
//
//int main(){
//    scanf("%d%d%d%d", &bx, &by, &mx, &my);
//    bx += 2; by += 2; mx += 2; my += 2;
//    f[1][2] = 1;//初始化
//    s[mx][my] = 1;
//    for(int i = 1; i <= 8; i++)
//        s[ mx + fx[i] ][ my + fy[i] ] = 1;
//    for(int i = 2; i <= bx; i++){
//        for(int j = 2; j <= by; j++){
//            if(s[i][j]){
//                f[i & 1][j] = 0;//被马拦住了记住清零
//                continue;
//            }
//            f[i & 1][j] = f[(i - 1) & 1][j] + f[i & 1][j - 1];
//            //新的状态转移方程
//        }
//    }
//    printf("%llu\n", f[bx & 1][by]);
//    //输出的时候第一维也要 按位与 一下,即 bx&1
//    return 0;
//}


#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define inf 100010
#define ll long long
#define INF 0x7fffffff
#define ull unsigned long long

const int fx[] = {0, -2, -1, 1, 2, 2, 1, -1, -2};
const int fy[] = {0, 1, 2, 2, 1, -1, -2, -2, -1};

inline int read(){
    int num = 0; char c = getchar(), up = c;
    while(c < '0' || c > '9') up = c, c = getchar();
    while(c >= '0' && c <= '9') num = (num << 1) + (num << 3) + (c ^ '0'), c = getchar();
    return up == '-' ? -num : num;
}

int bx, by, mx, my;
ull f[40];//这次只需要一维数组啦??????
bool s[40][40];

int main() {
    bx = read();by = read();mx = read();my = read();
    bx += 2;by += 2;mx += 2;my += 2;f[2] = 1;//初始化
    s[mx][my] = 1;
    for (int i = 1; i <= 8; i++)
        s[mx + fx[i]][my + fy[i]] = 1;
    for (int i = 2; i <= bx; i++)
    {
        for (int j = 2; j <= by; j++)
        {
            if (s[i][j])
            {
                f[j] = 0;//还是别忘了清零
                continue;
            }
            f[j] += f[j - 1];
            // 全新的 简洁的状态转移方程
        }
    }
    printf("%llu\n", f[by]);
    return 0;
}

