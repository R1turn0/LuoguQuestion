#include <cstdio>
#include <iostream>

#define N 1000000

int a[N], n;    //a数组存储堆，n为堆的最大下标。

void down(int x)//下沉
{
    while ((a[x] <= a[x * 2] && x * 2 <= n) || (a[x] <= a[2 * x + 1] && x * 2 + 1 <= n)) {
        int wrong = 0;
        try {//检查异常情况
            if (a[x * 2] >= a[x * 2 + 1]) throw wrong;//当找出x的左儿子比x的右二子大（或相等）时停止try的运行并抛出异常。
            std::swap(a[x], a[x * 2 + 1]);
            x = 2 * x + 1;
        }
        catch (int error) {//当接收到异常
            if (wrong == error) {
                std::swap(a[x], a[x * 2]);
                x *= 2;
            }
        }
        //实际上这个try和throw和catch完全可以用if和else 和else if 代替，但是如此写比较正式（扯淡吧）
    }
}

void up(int x)//下沉
{
    while (a[x] > a[x / 2] && x > 1) {
        std::swap(a[x], a[x / 2]);
        x /= 2;
    }
}

void work(int x)//插入堆底
{
    a[++n] = x;
    up(n);
}

int main() {
    int ans = 0, sum = 0, h;
    int nn;
    scanf("%d%d", &nn, &h); //nn代表要插入的元素数量，h代表书架的高度。
    int b;
    for (register int i = 1; i <= nn; i++) {
        scanf("%d", &b);
        work(b);//读入一个插入一个建堆。
    }
    while (true) {
        int wrong = 0;
        sum += a[1];//大根堆，堆顶最大。
        ans++;
        try {
            if (sum >= h) throw wrong;//当高度足够时跳出。
            a[1] = a[n];
            n--;
            down(1);
        }
        catch (int error) {
            if (wrong == error)
                break;
        }
    }
    printf("%d", ans);
    return 0;
}