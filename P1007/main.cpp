#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n, l, p, maxv = 0, minv = 0;
    scanf("%d%d", &l, &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p);
        maxv = max(maxv, max(l - p + 1, p));
        minv = max(minv, min(l - p + 1, p));
    }
    printf("%d %d", minv, maxv);
    return 0;
}

//你在桥上看风景，看风景的人在轰炸机上看着你。
//
//首先自行脑补一下，假装你正在20000米高空的轰炸机上用高倍显微镜望远镜默默欣赏士兵离开，你会发现什么东西？一堆花花绿绿的迷彩服在移动。（不是鬼片！不是鬼片！不是鬼片！重要的事情说三遍）
//
//那么当两个士兵撞在一起时，从你的视角看会发生什么？当然他们认为他们都掉头了，但因为你在特高的地方，你会认为他们“穿过”了对方。换言之，这与他们相互穿过并没有任何区别。
//
//然后我们就可以把士兵分开了。比方说有一个士兵在位置3，开始时向右，那么一定有一个士兵在两秒后在位置5。虽然这两个家伙可能不是同一个人，但由于士兵都是相同的，我们可以认为他们相同。
//
//那么我们就可以把所有士兵分开。首先，我们把他们一个个读进去。然后，对于每一个士兵，他有向左和向右两种选择。设士兵在位置p，如果向左，需要p时间单位；向右，需要L-p+1个。分别取max和min，更新答案即可。