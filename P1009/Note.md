# P1009

本题目为测试高精度乘法、加法

以下为解题思路

## 运算符重载

```angular2html
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>

using namespace std;

struct fantastic     //嗯，开始重载了
{
    int len, s[9999];

    fantastic() {
        memset(s, 0, sizeof(s));
        len = 1;
    }

    fantastic operator=(const char *num) {
        len = strlen(num);
        for (int i = 0; i < len; ++i)
            s[i] = num[len - i - 1] - '0';
        return *this;
    }

    fantastic operator=(const int num) {
        char calculate[9999];
        sprintf(calculate, "%d", num);
        *this = calculate;
        return *this;
    }

    fantastic(const int num) {
        *this = num;
    }

    fantastic(const char *num) {
        *this = num;
    }

    fantastic operator+(const fantastic &calculate)   //这里在重载 “+” 的运算
    {
        fantastic c;
        c.len = max(len, calculate.len) + 1;                //这里就是我们熟悉的竖式模拟了
        for (int i = 0, x = 0; i < c.len; ++i) {
            c.s[i] = s[i] + calculate.s[i] + x;
            x = c.s[i] / 10;
            c.s[i] = c.s[i] % 10;
        }
        if (c.s[c.len - 1] == 0)
            --c.len;
        return c;
    }

    fantastic operator*(const fantastic &x)           //然后再来波 “*” 的运算
    {
        fantastic c;
        c.len = len + x.len;                 //又是我们熟悉的竖式模拟
        for (int i = 0; i < len; ++i)
            for (int j = 0; j < x.len; ++j) {
                c.s[i + j] += s[i] * x.s[j];
                c.s[i + j + 1] += c.s[i + j] / 10;
                c.s[i + j] %= 10;
            }
        if (c.s[c.len - 1] == 0)
            --c.len;
        return c;
    }
};

ostream &operator<<(ostream &out, const fantastic &x)   //重载一下输出
{
    for (int i = x.len - 1; i >= 0; --i)
        cout << x.s[i];
    return out;
}

istream &operator>>(istream &in, fantastic &x)       //重载一下输入
{
    char num[9999];
    in >> num;
    x = num;
    return in;
}

int main()         //然后就可以愉快的开始主程序啦
{
    int n;
    fantastic ans = 0, num = 1;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        num = num * i;
        ans = ans + num;
    }
    cout << ans << endl;
}                                         //非常的简单明了
```
```angular2html
Python
    print(reduce(lambda x,y:x+y,[reduce(lambda x,y:x*y,range(1,i+1)) for i in range(1, int(raw_input())+1)]))
or:
    print(sum(__import__('math').factorial(i) for i in range(1,int(input())+1)))
```