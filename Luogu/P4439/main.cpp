#include <iostream>

int main() {
    int n, sun = 2;
    char str1, str2;
    std::cin >> n >> str1;
    for (int i = 0; i < n - 1; i++) {
        std::cin >> str2;
        if (str1 != str2) sun++;
        str1 = str2;
    }
    std::cout << sun;
    return 0;
}
