#include <iostream>

int main() {
    int head, num = 0;
    int apple[10];
    for (int & i : apple)
        std::cin >> i;
    std::cin >> head;
    head += 30;
    for (int i : apple) {
        if (i <= head) {
            num++;
        }
    }
    std::cout << num;
    return 0;
}
