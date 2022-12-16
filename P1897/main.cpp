#include <iostream>
#include <vector>

int main() {
    int n, tmp;
    std::vector<int>a;

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> tmp;
        a.push_back(tmp);
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
