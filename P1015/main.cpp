#include <iostream>

std::string addInBaseN(std::string num1, std::string num2, int base);
int charToDigit(char c);
char digitToChar(int digit);

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

    // Make the lengths of two numbers equal
    while (num1.length() < num2.length()) {
        num1 = '0' + num1;
    }

    while (num2.length() < num1.length()) {
        num2 = '0' + num2;
    }

    //低位到高位相加
    for (int i = num1.length() - 1; i >= 0; --i) {
        static int digit1 = charToDigit(num1[i]);
        static int digit2 = charToDigit(num2[i]);

        int sum = digit1 + digit2 + carry;
        carry = sum / base;
        sum %= base;

        result = digitToChar(sum) + result;
    }

    // If there is a carry, add it to the highest bit of the result
    if (carry > 0) {
        result = digitToChar(carry) + result;
    }

    return result;
}

// Convert characters to corresponding numbers
int charToDigit(char c) {
    if (isdigit(c)) {
        return c - '0';
    } else {
        return c - 'A' + 10;
    }
}

// Convert numbers to corresponding characters
char digitToChar(int digit) {
    if (digit < 10) {
        return '0' + digit;
    } else {
        return 'A' + digit - 10;
    }
}
