#include <iostream>
#include <vector>

int main() {
    int n, num = 0;
    std::vector<int> mountain;

    std::cin >> n;
    for (int i = 0, mount = 0; i < n; i++) {
        std::cin >> mount;
        mountain.push_back(mount);
    }

    for (int i = 0; i < n; i++) {
        if (mountain[i] > mountain[i + 1]) {
            for (int j = i; j < n - 1; j++) {
                if (mountain[j + 1] > mountain[j]){
                    num++;
                    i = j;
                    break;
                }
            }
        }
    }

    std::cout << num << std::endl;
    return 0;
}
