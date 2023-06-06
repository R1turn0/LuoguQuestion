#include <cstdio>

int a[3];
char str, num;

int main() {
    while (scanf("%c:=%c;", &str, &num) == 2)//充分利用c++语言优势
        a[str - 'a'] = num >= '0' && num <= '9' ? num - '0' : a[num - 'a']; //赋值语句简洁明了
    printf("%d %d %d", a[0], a[1], a[2]);
}