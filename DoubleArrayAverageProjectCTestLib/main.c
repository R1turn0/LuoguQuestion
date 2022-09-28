#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib/DoubleArrayAverage.h"

//#pragma comment(lib, "/lib/myDll.a")

int main() {
    int i;

    unsigned int row;
    unsigned int col;
    inputRowAndCol(&row, &col);

    double *twoDimenArray = (double*) malloc(sizeof(double) * row * col);
    // 每次输入一行数据
    for (i = 0; i < row; i++) {
        if (1 != inputDoubleArray(twoDimenArray, i, col)) {
            puts("Runtime Error!");
            exit(0);
        }
    }

    // 输出二维double数组
    outputDoubleArray(twoDimenArray, row, col);
    // 输出第row行平均数
    printf("One row average : %.2lf", doubleAverage(twoDimenArray, 0, col));

    free(twoDimenArray);
    twoDimenArray = NULL;
    return 0;
}
