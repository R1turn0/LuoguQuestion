//#include <iostream>
//#include <vector>
//
//int main() {
//    unsigned int n, len;
//    std::vector<unsigned int> stud;
//    unsigned int sum = 0;
//
//    std::cin >> n;
//    for (int i = 0; i < n; i++) {
//        std::cin >> len;
//        stud.push_back(len);
//    }
//    for (int i = 0; i < n-1; i++) {
//        if (stud[i] > stud[i+1])
//            sum += stud[i];
//        else
//            sum += stud[i+1];
//    }
//
//    std::cout << sum << std::endl;
//    return 0;
//}

#include <iostream>

int main() {
    unsigned int n;
    unsigned int front, after;
    long long sum;

    std::cin >> n;
    std::cin >> front;
    for (int i = 0; i < n-1; i++) {
        std::cin >> after;
        if (front > after) {
            sum += front;
        }
        else
            sum += after;
        front = after;
    }
    std::cout << sum;
    return 0;
}

