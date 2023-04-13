#include <iostream>

int main() {
    int sun = 0;
    std::string str;
    std::cin >> str;
    for (int i = 0; i < str.size() - 1; i++)
        if (str[i] != str[i + 1])
            sun++;
    if (str[str.size() - 1] == '0')
        sun++;
    std::cout << sun;
    return 0;
}
