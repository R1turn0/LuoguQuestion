#include <iostream>
#include <cstring>

int main() {
    int n;
    char num[61] = {'\0'};
    std::string str;
    unsigned long len;

    std::cin >> n;
//    for (int i = 0;i < n; i++) {
//        std::cin >> num;
//        len  = strlen(num);
//        if (num[len - 1] % 2 == 0)
//            std::cout << "even" << std::endl;
//        else
//            std::cout << "odd" << std::endl;
//    }

    for (int i = 0; i < n; i++) {
        std::cin >> str;
        if (str.back() % 2 == 0)
            std::cout << "even" << std::endl;
        else
            std::cout << "odd" << std::endl;
    }

    return 0;
}


/*
#include <cstdio>
//用getchar读入比较scanf快，最弱的快速读入int型就是不用scanf，一个一个字符用getchar读入
using namespace std;
int main()
{
    int n;
    char x,s;
    scanf("%lld", &n);
    getchar();
    // 既然要用getchar就要吞掉输入完n后的回车
    // 前面两行可用n=0;while (((x=getchar())!=EOF)&&x!='\n') n=n*10+x-'0';
    // 即正整数的快速读入
    while (n--)
    {
        scanf("lld",&x);
        while (((x = getchar()) != EOF) && x != '\n')
            s = x;
        // 读入x，若x不是回车且读入进了东西，将s赋值为x，不然停止循环
        // s储存着这个数的最后一位
        // EOF指End Of File，就是这个输入完了，读不到任何东西
        // !=EOF是很有用的，如果出题人丧心病狂输入完不打回车（十分常见），没有任何东西读入，getchar就会返回EOF（即-1）你就会死循环
        // 我曾去掉!=EOF重新提交，最后全部TLE
        s -= '0';
        if (s % 2)
            printf("odd\n");
        else
            printf("even\n");
    }
    return 0;
}
*/