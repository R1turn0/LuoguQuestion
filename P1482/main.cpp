#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string score1;
    int num1, num2;
    int num3, num4;
    int tmp, tmp1, tmp2;

    scanf("%d/%d", &num1, &num2);
    scanf("%d/%d", &num3, &num4);

    tmp1 = num1 * num3;
    tmp2 = num2 * num4;

    printf("%d %d\n",tmp2 / std::__gcd(tmp1,tmp2),tmp1 / std::__gcd(tmp1,tmp2));

//    while ((tmp = tmp1 % tmp2)) {
//        tmp1 = tmp2;
//        tmp2 = tmp;
//    }
//
//    num1 = num1 * num3 / tmp2;
//    num2 = num2 * num4 / tmp2;
//
//    std::cout << num2 << " " << num1;

    return 0;
}
