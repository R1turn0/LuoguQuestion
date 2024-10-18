//
// Created by r1turn0 on 22-9-23.
//

#include "HexstrToBytes.h"

void getHexArrayFromFile(const char *fileName, unsigned char* hexArray, unsigned short *DateSize)
{
    FILE *fp = NULL;
    char c;
    int i = 0;
    unsigned char tmp0 = 0, tmp1 = 0;
    unsigned short index = 0;

    fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("can not open %s", fileName);
        return;
    }

    while (1) {
        c = fgetc(fp);
        if (feof(fp) || c == 0xa) {  // 换行符
            if (i % 2 == 1) {
                hexArray[index] = (tmp0 << 4) & 0xFF;
                putHexArrayToFile(hexArray[index]);
                index += 1;
            }
            break;
        }
        i += 1;
        if (i % 2 == 1) {
            tmp0 = charToInt(c);
        }
        if (i % 2 == 0) {
            tmp1 = charToInt(c);
            hexArray[index] = ((tmp0 << 4) + tmp1) & 0xFF;
            putHexArrayToFile(hexArray[index]);
            index += 1;
            tmp0 = 0;
            tmp1 = 0;
        }
    }
    *DateSize = index;

    fclose(fp);
    fp = NULL;
}

void putHexArrayToFile(unsigned char hexArray) {
    FILE *out = NULL;
    const char* putFileName = "../outPut.txt";

    out = fopen(putFileName, "a");
    if (out == NULL) {
        puts("OutPut File open failed!");
        exit(0);
    }
    fprintf(out, "0x%02x ", hexArray);

    fclose(out);
    out = NULL;
}

int charToInt(char ch)
{
    switch (ch) {
        case '0':
            return 0;
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
        case 'a':
            return 10;
        case 'b':
            return 11;
        case 'c':
            return 12;
        case 'd':
            return 13;
        case 'e':
            return 14;
        case 'f':
            return 15;
        case 'A':
            return 10;
        case 'B':
            return 11;
        case 'C':
            return 12;
        case 'D':
            return 13;
        case 'E':
            return 14;
        case 'F':
            return 15;
        default:
            printf("Warrning: Data is wrong. %x", ch);
            return -1;
    }
//    if(ch >= '0' && ch <= '9')
//        return ch-'0';
//    if(ch >= 'A' && ch <= 'F')
//        return ch - 'A' + 10;
//    if(ch >= 'a' && ch <= 'f')
//        return ch - 'a' + 10;
//    printf("\nWarrning: Data is wrong. %x\n", ch);
//    return -1;
}