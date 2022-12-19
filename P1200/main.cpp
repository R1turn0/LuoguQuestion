#include <iostream>

int main() {
    std::string a, b;
    int ans = 1, num = 1; //这里要注意起始值必须为1，要是0的话所有的数乘出来都是0了....
    std::cin >> a >> b; // 输入
    for (char i : a) ans *= i - '@';
    // @的编号为64 ，A的编号65-@的编号64不就是所对应的英语字母序号了嘛...
    for (char i : b) num *= i - '@';
    // 同上
    ans %= 47, num %= 47; // 根据题意，mod 47
    if (ans == num)
        std::cout << "GO";
    else
        std::cout << "STAY"; //输出
    return 0; //完美结束
}