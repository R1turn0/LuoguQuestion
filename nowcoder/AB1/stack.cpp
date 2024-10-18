#include <iostream>
#include <cstring>

class stack {
private:
    int a[100001];
    int* p = a;
public:
    void push(int num) {
        *(++p) = num;
    }
    void pop() {
        if (p == a) std::cout << "error" << std::endl;
        else {
            std::cout << *p << std::endl;
            p--;
        }
    }
    void top() {
        if (p == a) std::cout << "error" << std::endl;
        else std::cout << *p << std::endl;
    }
};

int main() {
    std::string opt;
    int n, num;
    stack s;

    std::cin >> n;
    while (n--) {
        std::cin >> opt;
        if (opt == "push") {
            std::cin >> num;
            s.push(num);
        }
        if (opt == "pop") {
            s.pop();
        }
        if (opt == "top") {
            s.top();
        }
    }

    return 0;
}


//int main() {
//    std::string opt;
//    int n;
//    int num;
//    int* p = a;
//
//    std::cin >> n;
//    for (int i = 0; i < n; i++) {
//        std::cin >> opt;
//        if (opt == "push") {
//            std::cin >> num;
//            *(++p) = num;
//        }
//        else if (opt == "pop") {
//            if (p == a) std::cout << "error" << std::endl;
//            else {
//                std::cout << *p << std::endl;
//                p--;
//            }
//        }
//        else if (opt == "top") {
//            if (p == a) std::cout << "error" << std::endl;
//            else std::cout << *p << std::endl;
//        }
//    }
//
//    return 0;
//}