//#include <iostream>
//
//static int light[2000000];
//double a;
//int t;
//
//int main() {
//    int n;
//    std::cin >> n;
//    while (n--) {
//        std::cin >> a >> t;
//        for (int i = 1; i <= t; i++) {
//            light[(int)(a * i)] = !light[(int)(a * i)];
//        }
//    }
//    for (int i = 1; ;i++) {
//        if (light[i] == 1) {
//            std::cout << i;
//            break;
//        }
//    }
//    return 0;
//}

#include<bits/stdc++.h> //万能头文件

#define f(i, j, n) for(i=j;i<=n;i++) //for循环简写，福利福利~

int main() {
    std::ios::sync_with_stdio(false); //cin，cout快读快输，写scanf和printf的就不要加了，会RE
    int n, t, i, j, ans = 0;
    double a; //为了保险我们还是开double
    std::cin >> n;
    f(i, 1, n) {
        std::cin >> a >> t;
//        f(j, 1, t) ans ^= int(j * a); //重点：位运算，直接异或，这里注意要用int强制把j*a的值转换成整型
        for (j = 1; j <= t; j++) {
            int temp = (int) (j * a);
            std::cout << ans << " ^ " << temp;
            ans ^= temp;
            std::cout <<  " = " << ans << " ";

            std::bitset<32> binary(ans);
            std::cout << binary << std::endl;
        }
    }
    std::cout << ans << std::endl; //输出ans即可
    return 0; //华丽丽地结束
}
