#include <iostream>
#include <vector>
#include<bits/stdc++.h>

int main() {
    int N, order;
    int i;
    int temp;
    int a[1000];
    std::vector<int> gift;

    std::cin >> N;
//    for (i = 0; i < N; i++) {
//        std::cin >> order;
//        gift.push_back(order);
//    }

    for (i = 0; i < N; i++) {
        std::cin >> a[i];
    }

    if (std::prev_permutation(a, a + N)) {
        for (i = 0; i < )
    }


//    // 冒泡排序
//    for (i = 0; i < N; i++) {
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
