//#include <iostream>
//#include <algorithm>
//#include <cmath>
//
//std::string addInBaseN(std::string num1, std::string num2, int base);
//int charToDigit(char c);
//char digitToChar(int digit);
//std::string reversed(std::string num);
//bool isPalindrome(int num);
//bool isPalindromeInBaseN(const std::string& number, int base);
//int convertToDecimal(const std::string& nBaseNumber, int base);
//
//int main() {
//    std::string num;
//    int base;
//
//    std::cin >> base;
//
////    std::cout << "Input first num: ";
//    std::cin >> num;
//
//    // 进行加法运算并输出结果
////    std::string result = addInBaseN(num, reversed(num), base);
////    std::cout << "The sun is: ";
////    std::cout << result << std::endl;
//    for (int i = 1; i <= 30; i++) {
//        num = addInBaseN(num, reversed(num), base);
//        if (isPalindromeInBaseN(num, base)) {
//            std::cout << "STEP=" << i << std::endl;
//            return 0;
//        }
//    }
//    std::cout << "Impossible!" << std::endl;
//    return 0;
//}
//
//std::string addInBaseN(std::string num1, std::string num2, int base) {
//    std::string result;
//    int carry = 0;
//
//    // Make the lengths of two numbers equal
//    while (num1.length() < num2.length()) {
//        num1 = '0' + num1;
//    }
//
//    while (num2.length() < num1.length()) {
//        num2 = '0' + num2;
//    }
//
//    //低位到高位相加
//    for (int i = num1.length() - 1; i >= 0; --i) {
//        int digit1 = charToDigit(num1[i]);
//        int digit2 = charToDigit(num2[i]);
//
//        int sum = digit1 + digit2 + carry;
//        carry = sum / base;
//        sum %= base;
//
//        result = digitToChar(sum) + result;
//    }
//
//    // If there is a carry, add it to the highest bit of the result
//    if (carry > 0) {
//        result = digitToChar(carry) + result;
//    }
//
//    return result;
//}
//
//// Convert characters to corresponding numbers
//int charToDigit(char c) {
//    if (isdigit(c)) {
//        return c - '0';
//    } else {
//        return c - 'A' + 10;
//    }
//}
//
//// Convert numbers to corresponding characters
//char digitToChar(int digit) {
//    if (digit < 10) {
//        return '0' + digit;
//    } else {
//        return 'A' + digit - 10;
//    }
//}
//
//std::string reversed(std::string num) {
////    int reversedNumber;
//    std::reverse(num.begin(), num.end());
////    reversedNumber = std::stoi(num);
//
//    return num;
//}
//
//bool isPalindrome(int num) {
//    int originalNum = num;
//    int reversedNum = 0;
//
//    while (num > 0) {
//        int digit = num % 10;
//        reversedNum = reversedNum * 10 + digit;
//        num /= 10;
//    }
//
//    return originalNum == reversedNum;
//}
//
//bool isPalindromeInBaseN(const std::string& number, int base) {
//    std::string originalNumber = number;
//    std::string reversedNumber;
//
//    // 反转字符串
//    for (auto it = originalNumber.rbegin(); it != originalNumber.rend(); ++it) {
//        reversedNumber += *it;
//    }
//
//    return originalNumber == reversedNumber;
//}
//
//int convertToDecimal(const std::string& nBaseNumber, int base) {
//    int decimalNumber = 0;
//
//    for (size_t i = 0; i < nBaseNumber.length(); ++i) {
//        char digitChar = nBaseNumber[i];
//
//        int digitValue;
//        if (isdigit(digitChar)) {
//            digitValue = digitChar - '0';
//        } else {
//            digitValue = 10 + (toupper(digitChar) - 'A');
//        }
//
//        decimalNumber += digitValue * static_cast<int>(pow(base, nBaseNumber.length() - i - 1));
//    }
//
//    return decimalNumber;
//}

#include <cstdio>
#include <cstring>

#define S 303

static int n, a[S], l;
static char c[S], d[S];

auto pd = []() -> bool {
    for (int i = 0; i < l; ++i)
        if (c[i] != c[l - 1 - i]) return false;
    return true;
};

auto add = []() {
    for (int i = 0; i < l; i++) { d[l - i - 1] = c[i]; }
    l += 2;
    for (int i = 0; i < l; ++i) {
        c[i] += d[i];
        if (c[i] >= n) c[i + 1]++, c[i] -= n;
    }
    while (!c[l - 1]) --l;
};

int main() {
    scanf("%d%s", &n, c);
    l = strlen(c);
    for (int i = 0; i < l; ++i) {
        if (c[i] >= '0' && c[i] <= '9') c[i] -= '0';
        else c[i] = c[i] - 'A' + 10;
    }
    int step = 0;
    while (!pd()) {
        ++step;
        if (step > 30) break;
        add();
    }
    if (step <= 30) printf("STEP=%d\n", step);
    else puts("Impossible!");
    return 0;
}
