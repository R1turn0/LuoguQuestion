#include <iostream>

int main() {
    int N;
    int num[50];
    int Winner = 0;
    std::cin >> N ;

    for (int i = 0; i < N; i++) {
        std::cin >> num[i];
        if (num[i] % 2 != 0)
            std::cout << "zs wins" << std::endl;
        else
            std::cout << "pb wins" << std::endl;
    }
    return 0;
}
