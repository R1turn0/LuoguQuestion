#include <iostream>

int main() {
    int n;
    int a[100];
    int min = 1000;

    std::cin >> n;
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
        if(a[i] < min)
            min = a[i];
    }

    std::cout << min << std::endl;
    return 0;
}
