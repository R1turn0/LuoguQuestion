#include <iostream>

int main() {
    unsigned int N, num = 0;
    std::cin >> N;

    while (N != 1) {
        if(N % 2  == 0)
            N = N / 2;
        else
            N = N * 3 + 1;
        num++;
    }

    std::cout << num << std::endl;
    return 0;
}
