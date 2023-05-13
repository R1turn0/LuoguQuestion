#include <iostream>

int main() {
    int n;
    int line = 0;
    int num;
    int is = 0;
    std::cin >> n;
    while (std::cin >> num) {
        is = !is;
        if (is) {
            for (int i = 0; i < num; i++) {
                std::cout << "0";
                line++;
                if (line == n) {
                    std::cout << std::endl;
                    line = 0;
                }
            }
        }
        else {
            for (int i = 0; i < num; i++) {
                std::cout << "1";
                line++;
                if (line == n) {
                    std::cout << std::endl;
                    line = 0;
                }
            }
        }
    }
    return 0;
}
