
#ifndef HEXSTRTOBYTES_HEXSTRTOBYTES_H
#define HEXSTRTOBYTES_HEXSTRTOBYTES_H

#include <stdio.h>
#include <stdlib.h>
#define HEX_ARRAY_SIZE  1024 * 1024 * 10

int charToInt(char);
void getHexArrayFromFile(const char*, unsigned char*, unsigned short*);
//void putHexArrayToFile(const char*, unsigned char*);
void putHexArrayToFile(unsigned char);


#endif //HEXSTRTOBYTES_HEXSTRTOBYTES_H