#include <iostream>
#include<bits/stdc++.h>

using namespace std;

string run(int x, int i = 0, string s = string("")) {
    if (x == 0)return string("0");
    //拼接字符串，应题意，要把低次方接在后面
    do if (x & 1)s = (i == 1 ? "2" : "2(" + run(i) + ")") + (s == "" ? "" : "+") + s;
    while (++i, x >>= 1);//每次向右移位
    return s;
}

int main() {
    int x;
    cin >> x;
    cout << run(x) << endl;
}


// ======== 以二进制形式输出 ========
void binary_print(unsigned int num) {
    int i;
    int bit;
    int size = sizeof(num) * 8;
    // 这里的size是输入参数v的位数，直接用32代替也可以，但写成sizeof(num)*8这样更为通用。
    for (i = 0; i < size; i++) {
        bit = num & (1 << (size - i - 1));//提取出第i位的值
        if (bit == 0)
            putchar('0');
        else
            putchar('1');
    }
}
