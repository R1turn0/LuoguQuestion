#include <iostream>
#include <vector>

void OneLine(int len);
void TwoLine(int len);
void ThreeLine(int len, std::string work);

int main() {
    std::string work;
    int len;

    std::cin >> work;
    len = work.length();

    OneLine(len);
    TwoLine(len);
    ThreeLine(len, work);
    TwoLine(len);
    OneLine(len);

    return 0;
}

void OneLine(int len) {
    int Wendy = 1;
    std::cout << ".";
    for (int i = 0; i < len; i++) {
        if (Wendy % 3 != 0)
            std::cout << ".#..";
        else
            std::cout << ".*..";
        Wendy++;
    }
    std::cout << std::endl;
}

void TwoLine(int len) {
    int Wendy = 1;
    std::cout << ".";
    for (int i = 0; i < len; i++) {
        if (Wendy % 3 != 0)
            std::cout << "#.#.";
        else
            std::cout << "*.*.";
        Wendy++;
    }
    std::cout << std::endl;
}

void ThreeLine(int len, std::string work) {
    int Wendy = 1;
    int num = (len / 3) * 2;
    std::cout << "#";
    for (int i = 0; i < len; i++) {
        std::cout << "." << work[i] << ".";
        if ((Wendy % 3 == 2 || Wendy % 3 + 3 == 3) && (num > 0)) {
            std::cout << "*";
            num--;
        }
        else
            std::cout << "#";
        Wendy++;
    }
    std::cout << std::endl;
}