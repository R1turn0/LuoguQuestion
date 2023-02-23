//#include<iostream>
//
//int k;
//
//int f(int a) {        //请别吐槽这个函数名-_-||
//    if (a - k > 0 && (a - k) % 2 == 0) return f((a + k) / 2) + f((a - k) / 2);//终于散伙咯
//    else return 1;    //想分手!没门
//}
//
//int main() {
//    int n;
//    std::cin >> n >> k;
//    std::cout << f(n);
//    return 0;
//}

#include<bits/stdc++.h>

#define ll long long
using namespace std;

ll k, n;//谨慎起见

ll dfs(int v) {//代表有v群奶牛出现时的最终群数
    if (v <= k) return 1;//如果剩下的奶牛数小于要分的数量，就不会分裂，返回1
    //不能写成if(v<k) return 1，那样在v==k的时候会死递归
    if ((v - k) % 2 == 0) return (dfs((v - k) / 2)/*少的那群*/+ dfs((v + k) / 2/*多的那群*/));//能分裂就继续分裂
    else return 1;//不能分裂就保留
}

int main() {
    scanf("%lld%lld", &n, &k);//输入
    printf("%lld", dfs(n));//输出
    return 0;//可不写，但不能写作return 1，会RE
}