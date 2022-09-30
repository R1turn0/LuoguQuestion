//
// Created by r1turn0 on 22-9-26.
//
#include "DoubleArrayAverage.h"

// （隐式调用/显式调用）Windows生成动态库时在函数前添加__declspec(dllexport)以生成动态链接库

int inputRowAndCol(unsigned int *row, unsigned *col) {
    int buffer;
    printf("Please input row and col:");
    if (EOF == scanf("%u %u", row, col)) {
        puts("Input row and col Error!");
        exit(0);
    }
    while ((buffer = getchar()) != EOF && buffer != '\n');
//    fflush(stdin);
    printf("Input %u row %u col double data:\n", *row, *col);
    return 1;
}

int inputDoubleArray(double *twoDimenArray, unsigned int row, unsigned int col) {
    int i, buffer;
    char inputTmp[255];
    char *pTmp = NULL;
    unsigned int n_scaned;
    double *tmp = (double*) malloc(sizeof(double) * col);
    while (1) {
        puts("Input data like this -> 1.1,2.0,3.14,5.6...");
        printf("Please input double array %u's row data:", row + 1);
        // 以字符串形式输入到字符串数组中
        if (1 != scanf("%s", inputTmp)) {
            puts("Please input again!");
            continue;
        }
        pTmp = inputTmp;
        for (i = 0, n_scaned = 0; i < col; i++) {
            // 将char型数组中的数据以浮点型写入tmp中
            if (1 == sscanf(pTmp, "%lf", &tmp[i])) {
                n_scaned++;
                pTmp = strstr(pTmp, ",");
                if (pTmp != NULL) {
                    pTmp++;
                    continue;
                } else {
                    break;
                }
            }
        }
        if (n_scaned != col) {
            printf("Input date is not %u!", col);
            while ((buffer = getchar()) != EOF && buffer != '\n');
            continue;
        } else {
            memcpy(twoDimenArray + (row * col), tmp, sizeof(double) *col);
            free(tmp);
            tmp = NULL;
            return 1;
        }
    }
    return 0;
}

int outputDoubleArray(double *twoDimenArray, unsigned int row, unsigned int col) {
    int i, j;
    printf("Your Two-dimensional data:\n");
    for (i = 0; i < row; i++) {
        printf("    ");
        for (j = 0; j < col; j++) {
            printf("%.2lf ", twoDimenArray[col * i + j]);
        }
        puts("");
    }
    return 1;
}

double doubleAverage(const double *twoDimenArray, unsigned int row, unsigned int col) {
    int i, j;
    double age = 0.0;
    for (i = 0; i < col; i++) {
        age += twoDimenArray[(col * row) + i];
    }
    age /= i;
    return age;
}