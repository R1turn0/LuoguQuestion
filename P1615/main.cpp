#include <iostream>

int main() {
    int start_h, start_min, start_s;
    int stop_h, stop_min, stop_s;
    long long n, time;

    scanf("%d:%d:%d", &start_h, &start_min, &start_s);
    scanf("%d:%d:%d", &stop_h, &stop_min, &stop_s);
    std::cin >> n;

    time = stop_s - start_s + (stop_min - start_min) * 60 + (stop_h - start_h) * 60 * 60;
//    std::cout << std::endl << "time = " << time << std::endl;

    std::cout << time * n;

    return 0;
}
