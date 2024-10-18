#include <iostream>

int main() {
    int sum = 0;
    std::string s;
    std::cin >> s;

    for(char i : s) {
        if(i == '1')
            sum++;
    }

    std::cout << sum << std::endl;
    return 0;
}
