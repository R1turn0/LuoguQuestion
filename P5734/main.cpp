#include<iostream>
#include<string>

int n;
std::string str, str1, str2;
int num, a, b;      //并不全有用

int main() {
    std::cin >> n;
    std::cin >> str;
    for (int i = 0; i < n; i++) {
        std::cin >> num;
        switch (num) {
            case 1:
                std::cin >> str1;
                str += str1;
                std::cout << str << std::endl;
                break;
            case 2:
                std::cin >> a >> b;
                str2 = str.substr(a,b);
                str = str2;
                std::cout << str << std::endl;
                break;
            case 3:
                std::cin >> a >> str1;
                str.insert(a, str1);
                std::cout << str << std::endl;
                break;
            case 4:
                std::cin >> str1;
                if (str.find(str1) < str.size())//找不到会返回一个诡异的数字（反正比字符串长）
                    std::cout << str.find(str1) << std::endl;
                else
                    std::cout << -1 << std::endl;
                break;
        }
    }
    return 0;
}