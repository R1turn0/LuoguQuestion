#include <iostream>

void sort(int* p, int n) {
    int tmp = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n - i; j++) {
            if(p[j-1] > p[j]) {
                tmp = p[j-1];
                p[j-1] = p[j];
                p[j] = tmp;
            }
        }
    }
}

//int binarySearch(int* p, int left, int right, int target) {
//    while (left < right) {
//        int mid = (left + right) / 2;
//        if (p[mid] == target) {
//            return mid;
//        }
//        else if (p[mid] > target) {
//            return binarySearch(p, left, right/2, target);
//        }
//        else if (p[mid] < target) {
//            return binarySearch(p, right/2, right, target);
//        }
//    }
//}


void outPut(int* p, int n) {
    for (int i = 0; i < n; i++)
        std::cout << p[i] << " ";
}

int main() {
    int l, n;
    int p[5000];
    int max = 0, min = 0, mid = 5000;

    std::cin >> l;
    std::cin >> n;
    for (int i = 0; i < n; i++)
        std::cin >> p[i];

    if (l == 0 || n == 0) {
        std::cout << min << " " << max << std::endl;
        return 0;
    }
    sort(p, n);

    for (int i = 0; i < n; i++) {
        if ((l/2 - p[i]) < mid)
            mid = p[i];
    }
    if (mid > l/2)
        min = (l + 1) - mid;
    else
        min = mid;

    max = l - p[0];

    std::cout << min << " " << max;
    return 0;
}
