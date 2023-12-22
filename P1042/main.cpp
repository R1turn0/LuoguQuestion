#include <iostream>

int scorer(const std::string &fraction, int ps);


int main() {
    std::string fraction;
    while (true) {
        static std::string input;
        // 从标准输入读取整行数据
        std::getline(std::cin, input);
        // 找到字符串中第一个'E'的位置
        size_t pos = input.find('E');
        // 如果找到了'E'，截取字符串到'E'位置
        if (pos != std::string::npos) {
            input = input.substr(0, pos);
            fraction.append(input);
            break;
        }
        fraction.append(input);
    }



//    std::cout << fraction << std::endl;
    scorer(fraction, 11);
    std::cout << std::endl;
    scorer(fraction, 21);

    return 0;
}

int scorer(const std::string &fraction, int ps) {
//    for (size_t i = 0; i < fraction.size(); i += ps) {
//        std::string substr = fraction.substr(i, ps);
//        int win_w = 0;
//        for (char ch: substr) {
//            if (ch == 'W') {
//                win_w++;
//            }
//        }
//        std::cout << win_w << ":" << substr.size() - win_w << std::endl;
//    }

    int w_win = 0, l_win = 0;
    for (int i = 0; fraction[i] != fraction.empty(); i++) {
        if (fraction[i] == 'W') {
            w_win++;
        } else if (fraction[i] == 'L') {
            l_win++;
        }
        if ((w_win >= ps || l_win >= ps) && (w_win - l_win > 1 || w_win - l_win < -1)) {
            std::cout << w_win << ":" << l_win << std::endl;
            w_win = l_win = 0;
        }
    }
    std::cout << w_win << ":" << l_win << std::endl;
    return 0;
}
