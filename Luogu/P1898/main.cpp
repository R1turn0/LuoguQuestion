#include <iostream>
#include <cstring>

std::string fate(std::string num);

int main()
{
    char str[11] = {0};
    int st;
    std::string num;

    std::cin >> str >> st;

    for (int i = 0; i < strlen(str); i++) {
        num.append(std::to_string(str[i] - 'A' + st));
    }
    num = fate(num);
    if (num == "00") num = '0';
    std::cout << num << std::endl;

    return 0;
}

std::string fate(std::string num) {
    std::string temp;
    for (int i = 0; i < num.size() - 1; i++) {
        temp.append(std::to_string(((num[i] - '0') + (num[i + 1] - '0')) % 10));
    }
    if (temp == "100" || temp.size() <= 2) {
        return temp;
    }
    return fate(temp);
}

// 删除字符串前所有的'0' //
//void removeLeadingZeros(std::string &str) {
//    // 找到第一个非零字符的索引
//    size_t nonZeroIndex = str.find_first_not_of('0');
//
//    // 如果存在非零字符，则移动字符串并截断
//    if (nonZeroIndex != std::string::npos && nonZeroIndex > 0) {
//        str = str.substr(nonZeroIndex);
//    }
//}
