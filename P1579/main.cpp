#include <iostream>

int main() {
/******一维数组******/
    short int array_1[6] = {0};
    printf("///******一维数组******///\t");
    printf("short int array_1[6] = {0};\t");
    printf("(1)          array_1 = %d\t", array_1);
    printf("(2)      array_1 + 1 = %d\t", array_1 + 1);
    printf("(3)         &array_1 = %d\t", &array_1);
    printf("(4)     &array_1 + 1 = %d\t", &array_1 + 1);
    putchar('\n');
    printf("(5)       array_1[0] = %d\t", array_1[0]);
    printf("(6)   array_1[0] + 1 = %d\t", array_1[0] + 1);
    printf("(7)      &array_1[0] = %d\t", &array_1[0]);
    printf("(8)  &array_1[0] + 1 = %d\t", &array_1[0] + 1);
    putchar('\n');

    return 0;
}
