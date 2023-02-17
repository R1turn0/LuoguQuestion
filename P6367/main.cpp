#include <iostream>

int main() {
    int n;
    char *name[100];
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> *name[i];
    }
    for (int i = 0; i < n; i++) {
        std::cout << *name[i];
    }
    return 0;
}
