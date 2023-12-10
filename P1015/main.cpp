#include <iostream>

std::string addInBaseN(std::string num1, std::string num2, int base);

int main() {
    std::string num1, num2;
    int base;
    int n, m;
    std::cout << "请输入第一个数字: ";
    std::cin >> num1;

    std::cout << "请输入第二个数字: ";
    std::cin >> num2;

    std::cout << "请输入进制数: ";
    std::cin >> base;

    // 进行加法运算并输出结果
    std::string result = addInBaseN(num1, num2, base);
    std::cout << "相加的结果为: " << result << std::endl;
    return 0;
}

std::string addInBaseN(std::string num1, std::string num2, int base) {
    std::string result;
    int carry = 0;

    while (num1.length() < num2.length()) {
        num1 = '0' + num1;
    }
}