#include <iostream>

int main() {
    int lag, pre, num, rig;
    char id;
    scanf("%1d-%3d-%5d-%1c", &lag, &pre, &num, &id);
    rig = lag * 1 + (pre / 100 % 10) * 2 + (pre / 10 % 10) * 3 + (pre % 10) * 4
            + (num / 10000 % 10) * 5 + (num / 1000 % 10) * 6 + (num / 100 % 10) * 7
            + (num / 10 % 10) * 8 + (num % 10) * 9;
    if (((rig %= 11) == 10 && id == 'X') && rig == (id - '0'))
        std::cout << "Right";
    else {
        if (rig == 10)
            printf("%d-%d-%d-X", lag, pre, num);
        else
            printf("%d-%d-%d-%d", lag, pre, num, rig);
    }
    return 0;
}

//int main() {
//    char num[10];
//    for (char i : num) std::cin >> i;
//    for (int i = 1; i <= 10; i++) {
//
//    }
//}