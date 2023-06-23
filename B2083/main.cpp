#include <iostream>

int main() {
    int a, b;
    std::string c;
    int f;
    std::cin >> a >> b >> c >> f;
    for (int i = 0; i < b; i++) {
        std::cout << c;
    }
    std::cout << std::endl;
    while (--a > 1) {
        std::cout << c;
        if (f == 0){
            for (int i = 0; i < b - 2; i++)
                std::cout << ' ';
            std::cout << c << std::endl;
        }
        else{
            for (int i = 0; i < b - 1; i++) {
                std::cout << c;
            }
            std::cout << std::endl;
        }
    }
    for (int i = 0; i < b; i++) {
        std::cout << c;
    }
    return 0;
}
