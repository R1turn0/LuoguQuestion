#include <iostream>

int main() {
/******一维数组******/
    short int array_1[6] = {0};
    printf("///******一维数组******///\t");
    printf("short int array_1[6] = {0};\t");
    putchar('\n');
    printf("(1)          array_1 = %8d\t\t", array_1);
    printf("(2)      array_1 + 1 = %8d\t\t", array_1 + 1);
    printf("(3)         &array_1 = %8d\t\t", &array_1);
    printf("(4)     &array_1 + 1 = %8d\t\t", &array_1 + 1);
    putchar('\n');
    printf("(5)       array_1[0] = %8d\t\t", array_1[0]);
    printf("(6)   array_1[0] + 1 = %8d\t\t", array_1[0] + 1);
    printf("(7)      &array_1[0] = %8d\t\t", &array_1[0]);
    printf("(8)  &array_1[0] + 1 = %8d\t\t", &array_1[0] + 1);
    putchar('\n');

    /******二维数组******/
    short int array_2[2][4] = {0};
    printf("\n///******二维数组******///\n");
    printf("short int array_2[2][4] = {0};\n");
    printf("(1)          array_2 = %d\n", array_2);
    printf("(2)      array_2 + 1 = %d\n", array_2 + 1);
    printf("(3)         &array_2 = %d\n", &array_2);
    printf("(4)     &array_2 + 1 = %d\n", &array_2 + 1);
    printf("(5)       array_2[0] = %d\n", array_2[0]);
    printf("(6)   array_2[0] + 1 = %d\n", array_2[0] + 1);
    printf("(7)      &array_2[0] = %d\n", &array_2[0]);
    printf("(8)  &array_2[0] + 1 = %d\n", &array_2[0] + 1);
    printf("(9)       array_2[0][0] = %d\n", array_2[0][0]);
    printf("(10)  array_2[0][0] + 1 = %d\n", array_2[0][0] + 1);
    printf("(11)     &array_2[0][0] = %d\n", &array_2[0][0]);
    printf("(12) &array_2[0][0] + 1 = %d\n", &array_2[0][0] + 1);

    return 0;
}
