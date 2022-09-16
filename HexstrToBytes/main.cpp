#include <cstdio>
#include <cstddef>

#define PKT_ARRAY_SIZE  1024 * 1024
#define uint8_t  unsigned char
#define uint16_t unsigned short

static int chartoint(char ch);
static void get_hex_array_from_file(char *pkt_name, uint8_t pkt_array[PKT_ARRAY_SIZE], uint16_t *total_bytes);

int main()
{
    uint8_t pkt_array[PKT_ARRAY_SIZE] = {0};
    uint16_t total_bytes = 0;
    uint16_t i = 0;
    char* pkt_name = "../ptp.txt";

    get_hex_array_from_file(pkt_name, pkt_array, &total_bytes);
    printf("total_bytes:%d ", total_bytes);
    for (i = 1; i <= total_bytes; i++) {
        printf("0x%02x ", pkt_array[i-1]);
        if (i % 16 == 0)
            printf(" ");
    }
    printf(" ");
    return 0;
}

static int chartoint(char ch)
{
    if(ch >= '0' && ch <= '9')
        return ch-'0';
    if(ch >= 'A' && ch <= 'F')
        return ch - 'A' + 10;
    if(ch >= 'a' && ch <= 'f')
        return ch - 'a' + 10;
    printf("Warrning: Data is wrong. %x", ch);
    return -1;
}

static void get_hex_array_from_file(char *pkt_name, uint8_t pkt_array[PKT_ARRAY_SIZE], uint16_t *total_bytes)
{
    FILE *fp = nullptr;
    char c;
    int i = 0;
    uint8_t tmp0 = 0, tmp1 = 0;
    uint16_t index = 0;

    fp = fopen(pkt_name, "r");
    if (fp == nullptr) {
        printf("can not open %s", pkt_name);
        return;
    }

    while (true) {
        c = fgetc(fp);
        if (feof(fp) || c == 0xa) {  //换行符
            if (i % 2 == 1) {
                pkt_array[index] = tmp0 & 0xFF;
                *total_bytes += 1;
            }
            break;
        }
        i += 1;
        if (i % 2 == 1) {
            tmp0 = chartoint(c);
        }
        if (i % 2 == 0) {
            tmp1 = chartoint(c);
            pkt_array[index] = ((tmp0 << 4) + tmp1) & 0xFF;
            index += 1;
            tmp0 = 0;
            tmp1 = 0;
        }
    }
    *total_bytes = index;

    fclose(fp);
}
