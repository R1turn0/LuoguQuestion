#include <iostream>
#include <vector>
#include<bits/stdc++.h>

int main() {
    int N;
    int a[10];

    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }

    // prev_permutation
    // 变换范围 [first, last) 为来自于相对于 operator< 或 comp 的字典序的所有排列集合的上个排列。
    if (std::prev_permutation(a, a + N)) {
        for (int i = 0; i < N; i++) {
            std::cout << a[i] << ' ';
        }
    }
    else {
        std::cout << "ERROR";
    }
    std::cout << std::endl;

//    int temp;
//    std::vector<int> gift;
//    for (i = 0; i < N; i++) {
//        std::cin >> temp;
//        gift.push_back(order);
//    }
//    for (i = 0; i < N; i++) { // 冒泡排序
//        for (int j = 0; j < N - i - 1; j++) {
//            if (gift[j] > gift[j + 1]) {
//                temp = gift[j];
//                gift[j] = gift[j + 1];
//                gift[j + 1] = temp;
//            }
//        }
//    }

    return 0;
}
