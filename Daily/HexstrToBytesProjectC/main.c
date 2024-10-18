#include "HexstrToBytes.h"

int main()
{
//    unsigned char hexArray[PKT_ARRAY_SIZE] = {0};
    unsigned char *hexArray = (unsigned char*)malloc(HEX_ARRAY_SIZE);
    unsigned short DateSize = 0;
    unsigned short i;
    const char *fileName = "../ptp.txt";

    getHexArrayFromFile(fileName, hexArray, &DateSize);
    printf("DateSize:%d\n", DateSize);
    for (i = 1; i <= DateSize; i++) {
        printf("[%d]0x%02x ", i, hexArray[i - 1]);
    }
    free(hexArray);
    hexArray = NULL;
    return 0;
}
