#include <iostream>

int num[2000000];
int stu[2000000];

int main() {
    int n, m;
    int prb;
    std::cin >> n >> m;
    for (int i = 0; i < n; i++)
        std::cin >> num[i];
    while (m--) {
        std::cin >> prb;
        std::cout << num[--prb] << std::endl;
    }
    return 0;
}
