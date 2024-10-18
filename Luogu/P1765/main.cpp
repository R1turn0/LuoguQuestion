#include <iostream>

static std::string str;
static int num[26] = {1, 2, 3,
                      1, 2, 3,
                      1, 2, 3,
                      1, 2, 3,
                      1, 2, 3,
                      1, 2, 3, 4,
                      1, 2, 3,
                      1, 2, 3, 4
};

int main() {
    int sum = 0;
    getline(std::cin, str);
    for (char i: str) {
        if (i >= 'a' && i <= 'z')
            sum += num[i - 'a'];
        else if (i >= 'A' && i <= 'Z')
            sum += num[i - 'A'];
        else if (i == ' ') sum++;
    }
    std::cout << sum << std::endl;
    return 0;
}
