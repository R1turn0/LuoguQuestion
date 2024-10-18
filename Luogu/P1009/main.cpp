#include<iostream>
#include<cstdio>

using namespace std;
int n, calculate[101] = {0}, result[101] = {0};

// 高精度乘法
void mul(int digit) {
    int carry = 0;  // 进位
    for (int i = 100; i >= 0; i--) {
        calculate[i] = calculate[i] * digit + carry;    // 位数相乘加上低阶进位
        carry = calculate[i] / 10;  // 计算该数位上需要进位的大小
        calculate[i] = calculate[i] % 10;   // 计算该数位上的数 [0, 10)
    }
}

// 高精度加法
void add() {
    int carry = 0;  // 进位
    for (int i = 100; i >= 0; i--) {
        result[i] = result[i] + calculate[i] + carry;
        carry = result[i] / 10;
        result[i] = result[i] % 10;
    }
}

// 输出
void output() {
    int w = 0;
    // 循环过滤数组中无用的0
    for (int i = 0; i <= 100; i++) {
        if (result[i] != 0) {
            w = i;
            break;
        }
    }
    for (int i = w; i <= 100; i++)
        printf("%d", result[i]);
}

int main() {
    scanf("%d", &n);
    result[100] = calculate[100] = 1;
    for (int i = 2; i <= n; i++) {
        mul(i);
        add();
    }
    output();
    return 0;
}
