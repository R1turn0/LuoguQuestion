虽然您可以用快排过，但是您不会手打堆。

虽然您可以用基数过，但是您不会手打堆。

虽然您可以用STL打堆排，但是您还是不会手打堆。

显而易见，手打堆是可行且最能练习我们代码质量的，因为稍有不慎就会错。

以上全部都是扯淡。

这里讲解一下堆排

什么是堆
堆（英语：heap)是计算机科学中一类特殊的数据结构的统称。堆通常是一个可以被看做一棵树的数组对象。

堆的定义
堆中某个节点的值总是不大于或不小于其父节点的值；

堆总是一棵完全二叉树。

堆的分类
分大根堆和小根堆

例如：

                            1
                           / \
                          2   8
                         /\   /\
                        3  7 8  9 

这是一个小根堆。小根堆的定义是：任何一个子节点都不小于它的父节点。因此，堆的根节点总是最小。

又例如：

                            9
                           / \
                          6   8
                         /\   /\
                        3  2 1  4 		

这是一个大根堆。大根堆的定义是：任何一个子节点都不大于它的父节点。因此，堆的根节点总是最大。

堆的存储与遍历。
堆用数组存储。

拿上面的小根堆举例

                            1
                           / \
                          2   8
                         /\   /\
                        3  7 8  9 

用数组存储就是：

1 2 3 4 5 6 7\
1 2 8 3 7 8 9\
显然，堆的存储是按照每一层的顺序存进数组里的。

那么，怎么找到一个堆的父亲与儿子？

拿第二个点2举例。

如图，第二个点2的父亲是第一个点1，第二个点2的儿子为第四个点3与第五个点7。

得出结论：一个点的父亲为这个点的数组下表整除2;一个点的儿子为这个点的数组下标乘2或乘2加1.

很好理解吧。

堆的操作。
重点是如何维护一个堆。

在运行代码的时候，经常会从堆里面插入元素或取出元素。

因此堆的秩序经常会被打乱。

维护堆需要掌握两个操作：将一个点上浮或下沉。

这里拿小根堆举例，大根堆也是一样的。

下沉操作：
这里我将点一更改成9

                            9
                           / \
                          2   8
                         /\   /\
                        3  7 8  9 

1 2 3 4 5 6 7\
9 2 8 3 7 8 9\
它已经不是一个正常的堆了，至少不是一个正常的小根堆。

这时候我们就要将它下沉。

下沉关键代码：

```
void down(int x)//x为需要下沉的点的下标
{
    while((a[x]>=a[x*2]&&x*2<=n)||(a[x]>=a[2*x+1]&&x*2+1<=n))//只要找到有一个点小于它，那么就下沉，直无法下沉为止。。
    {
        if(a[x*2]<=a[x*2+1])//两个子节点，往更小的地方下沉。
        {
            swap(a[x],a[x*2]);
            x*=2;//需要改变下标。
        }
        else
        {
            swap(a[x],a[x*2+1]);
            x=2*x+1;
        }
    }
}
```

下沉之后它就成了这样：

                            2
                           / \
                          3   8
                         /\   /\
                        9  7 8  9

1 2 3 4 5 6 7\
2 3 8 9 7 8 9\
符合堆的性质。

上浮操作：
比下沉简单多了，不作太多讲解。

拿小根堆举例，当一个节点的父节点比它大，那么它就上浮until它呆在它应有的位置为止。

上浮代码：

void up(int x)
{
while(a[x]<a[x/2]&&x>1)//注意这个x>1。如果没了它可能会使x变成0。
{
swap(a[x],a[x/2]);
x/=2;
}
}
插入操作
往堆里面插入一个元素，可能会使堆不正常。

那么这样做，（不分大小根堆）：

1.最大下标加1，一个元素插入堆底（数组后）。

2.对它实行上升操作。

上代码可能会好理解一点。

```
void work(int x)
{
    a[++n]=x;
    up(n);
}
```

建堆操作
好吧重点来了。

这里讲的建堆，就是给你很多数字，把它存进数组里使其变成一个堆。

注意，排序一遍之后再建堆也是可以的，但是你既然排序过了还用什么堆排呢？

很简单。

1.最大标加1，插入队尾。

2.上升。

3.回到1.，直到没有数据再次插入。

删除堆顶元素
很多人不知道为什么要删除。

其实当这个堆是一个正常的堆时，它的根节点总是最大或最小的。

堆排序只要求你把它输出出来，然后将根的值赋为堆底元素（即当前最大下标所指的数组，记得最大下标要减一），最后对堆顶（因为执行上一操作会打破堆的正常秩序）执行下沉操作。

给出代码：

	a[1] =a[n];
    n--;
    down(1);

其中a数组是存储这个堆的数组，n为它的最大下标。

就到这里了吧。
回到原题，这一题要求我们每次累加最大的。

我们就建大根堆。

具体注释代码会有的。

有些地方会编译错误，说不定是故意的。

```
#include <cstdio>
#include <iostream>

using namespace std;

#define N 1000000

int a[N], n;    //a数组存储堆，n为堆的最大下标。

void down(int x)//下沉
{
    while ((a[x] <= a[x * 2] && x * 2 <= n) || (a[x] <= a[2 * x + 1] && x * 2 + 1 <= n)) {
        int wrong = 0;
        try {//检查异常情况
            if (a[x * 2] >= a[x * 2 + 1]) throw wrong;//当找出x的左儿子比x的右二子大（或相等）时停止try的运行并抛出异常。
            swap(a[x], a[x * 2 + 1]);
            x = 2 * x + 1;
        }
        catch (int error) {//当接收到异常
            if (wrong == error) {
                swap(a[x], a[x * 2]);
                x *= 2;
            }
        }
        //实际上这个try和throw和catch完全可以用if和else 和else if 代替，但是如此写比较正式（扯淡吧）
    }
}

void up(int x)//下沉
{
    while (a[x] > a[x / 2] && x > 1) {
        swap(a[x], a[x / 2]);
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
```