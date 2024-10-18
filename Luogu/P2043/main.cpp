#include <cstring>
#include <iostream>

using namespace std;

int re[10001];//记录某一个质因子的个数
int ss[10001];
int n;

void db() {//打表判断质数，用数组下标代替该数
    ss[1] = 0;
    ss[2] = 1;//1不是质数，2是质数
    for (int i = 2; i <= 10000; i++) {
        if (ss[i]) {
            for (int j = 2; j <= 10000 / i; j++) {
                ss[i * j] = 0;
            }
        }
    }
}

void divide(int k) {//分解质因数函数
    int t = k;//防止运行混乱加一个数引用要分解的数
    if (ss[k]) {//如果该数本身即为质数则不需多加判断
        re[k]++;
        return;
    }
    for (int i = 2; i <= t; i++) {//如果该数为一个合数
        if (ss[i]) {
            if (k % i == 0) {//如果该数为质因子
                re[i]++;//这个质因子个数+1
                k /= i;//原数除以质因子
                if (k == 1) return;//如果分解完毕则退出函数
                i--;//模拟上述方法
            }
        }
    }
    return;
}

int main() {
    memset(ss, 1, sizeof(ss));//初始化，注意初始化一定要看好是1还是0（吃过大亏）
    memset(re, 0, sizeof(re));
    cin >> n;
    db();
    for (int i = 2; i <= n; i++) divide(i);//分解每一位
    for (int i = 1; i <= n; i++) {
        if (re[i]) {//如果分解过程中出现了该质因子
            cout << i << " " << re[i] << endl;//输出该质因子与该质因子的个数
        }
    }
    return 0;
}