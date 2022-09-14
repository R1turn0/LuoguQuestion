#include <iostream>

int main() {
    int n, stu, ext;
    int time = 0, mood = 0;

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> stu >> ext;
        time += (stu + ext - 8);
        mood += time;
    }

    std::cout << mood << std::endl;
    return 0;
}
