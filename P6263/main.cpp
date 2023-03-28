#include <iostream>

int main() {
    std::string str;
    int a[8] = {0};
    std::cin >> str;
    for (char i : str) {
        if (i == '1' || i == 'Q' || i == 'A' || i == 'Z')
            a[0]++;
        if (i == '2' || i == 'W' || i == 'S' || i == 'X')
            a[1]++;
        if (i == '3' || i == 'E' || i == 'D' || i == 'C')
            a[2]++;
        if (i == '4' || i == 'R' || i == 'F' || i == 'V' || i == '5' || i == 'T' ||
            i == 'G' || i == 'B')
            a[3]++;
        if (i == '6' || i == 'Y' || i == 'H' || i == 'N' || i == '7' || i == 'U' ||
            i == 'J' || i == 'M')
            a[4]++;
        if (i == '8' || i == 'I' || i == 'K' || i == ',')
            a[5]++;
        if (i == '9' || i == 'O' || i == 'L' || i == '.')
            a[6]++;
        if (i == '0' || i == 'P' || i == ';' || i == '/' || i == '-' || i == '[' ||
            i == ']' || i == '=' || i == '\'')//注意这里判断字符 ' 的时候需要加一个 \；
			a[7]++;
    }
    for (int & i : a) {
        std::cout << i << std::endl;
    }
    return 0;
}
