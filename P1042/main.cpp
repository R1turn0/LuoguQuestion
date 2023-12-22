#include <iostream>

std::string fraction;

//char faction[2500][25];

int main() {
//    std::cout << "输入字符串（在'E'的位置上停止读取）：" << std::endl;

    // 从标准输入读取整行数据
    std::getline(std::cin, fraction);

    // 找到字符串中第一个'E'的位置
    size_t pos = fraction.find('E');

    // 如果找到了'E'，截取字符串到'E'位置
    if (pos != std::string::npos) {
        fraction = fraction.substr(0, pos);
    }


    for (int i = 0; i < (fraction.size() / 11 + fraction.size() % 11 == 0 ? 0 : 1); i++) {
        std::cout << fraction << std::endl;
    }

    return 0;
}
