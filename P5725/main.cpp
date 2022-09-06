#include <iostream>

void PutSquare(int n);
void PutTriangle(int n);

int main() {
    int n;
    std::cin >> n;

    PutSquare(n);
    std::cout << std::endl;
    PutTriangle(n);

    return 0;
}

void PutSquare(int n) {
    int num = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            num++;
            if (num < 10)
                std::cout << "0" << num;
            else
                std::cout << num;
        }
        std::cout << std::endl;
    }
}

void PutTriangle(int n) {
    int num = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++)
            std::cout << "  ";
        for (int j = 0; j < n - (n - i - 1); j++) {
            num++;
            if (num < 10)
                std::cout << "0" << num;
            else
                std::cout << num;
        }
        std::cout << std::endl;
    }
}