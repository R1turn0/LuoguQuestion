#include <iostream>
#include <algorithm>

int a[3];
std::string str;

int main() {
    std::cin >> a[0] >> a[1] >> a[2] >> str;
    std::sort(a, a + 3);
    for (int i = 0; i < 3; i++) {
        if (str[i] == 'A') std::cout << a[0] << ' ';
        else if (str[i] == 'B') std::cout << a[1] << ' ';
        else if (str[i] == 'C') std::cout << a[2] << ' ';
    }
    return 0;
}
