#include <iostream>
#include <valarray>

unsigned long long feb(int n);

void factoring(unsigned long long num);

int main() {
    int n;
    std::cin >> n;
    unsigned long long num = feb(n) % (unsigned long long) pow(2, 31);
    std::cout << num << '=';
    factoring(num);
    return 0;
}

//unsigned long long feb(int n) {
//    // 递归 //
//    if (n <= 2) {
//        return 1;
//    } else {
//        return feb(n - 1) + feb(n - 2);
//    }
//}

unsigned long long feb(int n) {
    // 循环 //
    unsigned long long a = 1, b = 1, c = 0;
    for (int i = 0; i < n - 2; i++) {
        c = a + b;
//        std::cout << c << ", ";
        a = b;
        b = c;
    }
    return b;
}

void factoring(unsigned long long num) {
//    unsigned long long rem;
//    if (num <= 2) {
//        std::cout << num;
//        return;
//    }
//    for (int i = 2; i <= 11; i++) { // 这段代码有问题，猜测是这里的原因，需要除以质数，所以只循环到11太小了
//        rem = num % i;
//        if (rem == 0) {
//            std::cout << i;
//            num /= i;
//            if (num != 1) std::cout << '*';
//            i = 1;
//        }
//    }
//    if (num != 1) std::cout << num;
    for (int i = 2; i <= num; i++) {
        while (num % i == 0)//遇到能除尽的就往下使劲除
        {
            std::cout << i;
            if (i != num) std::cout << '*';
            num /= i;
        }
    }
}
