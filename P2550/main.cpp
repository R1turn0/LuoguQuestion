#include <iostream>

int n;
int win[7];
int prize[7] = {0};
int num = 0;
int tmp;

int main() {
    std::cin >> n;
    for (int &i : win)
        std::cin >> i;
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < 7; i++) {
            std::cin >> tmp;
            for (int &z : win)
                if (z == tmp)
                    num++;
        }
        prize[--num]++;
        num = 0;
    }
    for (int i = 6; i >= 0; i--) {
        std::cout << prize[i] << " ";
    }
    return 0;
}
