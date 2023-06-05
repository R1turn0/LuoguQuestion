#include <iostream>

int main() {
    int lag, pre, num;
    char id;
    int rig;
    scanf("%1d-%3d-%5d-%1c", &lag, &pre, &num, &id);
    rig = lag * 1 + (pre / 100 % 10) * 2 + (pre / 10 % 10) * 3 + (pre % 10) * 4
            + (num / 10000 % 10) * 5 + (num / 1000 % 10) * 6 + (num / 100 % 10) * 7
            + (num / 10 % 10) * 8 + (num % 10) * 9;
    if ((rig %= 11) == 10 && id == 'X')
        std::cout << "Right";
    else {
        if (rig == id - '0')
            std::cout << "Right";
        else {
            if (rig == 10)
                printf("%d-%d-%d-X", lag, pre, num);
            else
                printf("%d-%d-%d-%d", lag, pre, num, rig);
        }
    }
    return 0;
}
