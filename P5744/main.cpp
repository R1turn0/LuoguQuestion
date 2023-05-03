#include <iostream>

int main() {
    int n;
    std::string name;
    int age, res;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> name >> age >> res;
        if (res > 500)
            res = 600;
        else
            res *= 1.2;
        std::cout << name << ' ' << age + 1 << ' ' << res << std::endl;
    }
    return 0;
}
