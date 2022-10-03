//
// Created by r1turn0 on 22-9-26.
//

#ifndef DOUBLEARRAYAVERAGE_H
#define DOUBLEARRAYAVERAGE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inputRowAndCol(unsigned int *row, unsigned int *col);

int inputDoubleArray(double *Array, unsigned int currentRow, unsigned int col);

int outputDoubleArray(double *Array, unsigned int row, unsigned int col);

double doubleAverage(const double *Array, unsigned int currentRow, unsigned int col);

#endif //DOUBLEARRAYAVERAGE_H
