#include <iostream>
#include <set>

std::set<int> num;

int countNumbersWithSum(const std::set<int>& numberSet);

int main() {
    int n, tmp;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> tmp;
        num.insert(tmp);
    }
    std::cout << countNumbersWithSum(num) << std::endl;
    return 0;
}

// 计算满足条件的数的个数
int countNumbersWithSum(const std::set<int>& numberSet) {
    int count = 0;
    for (int num1 : numberSet) {
        for (int num2 : numberSet) {
            if (num1 != num2 && numberSet.count(num1 + num2) > 0) {
                count++;
            }
        }
    }
    return count / 2; // 每对数会被计数两次，所以除以2
}