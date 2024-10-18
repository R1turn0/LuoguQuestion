# 题解

## 深度优先算法 DFS

dfs 虽然dfs没有dp快，但是这道题数据很小，对于和我一样的蒟蒻来说，如果在比赛中dp和dfs同样能过那最好还是用dfs，因为dfs的思路简单不容易错而且代码好写方便改错。这里因为要考虑到不重复，所以可以按升序记录每一次划分：记录上一次划分所用的数，保证当前划分所用数不小于上次划分所用分数，当划分次数等于k时比较该次划分所得总分是否与n相同并记录次数。

有一个不得不做的剪枝就是枚举当前划分所用分数时应该从last(上次划分所用分数)枚举到sum+i*(k-cur)<=n为止，因为之后划分的分数一定大于或等于当前划分所用分数。这个剪枝不做的话不仅会TLE，在TLE之间就爆栈RE了(洛谷测评机没有无限栈，差评）

```C++
#include<cstdio>

int n,k,cnt;

void dfs(int last,int sum,int cur)
{
    if(cur==k)
    {
        if(sum==n) cnt++;
        return;
    }
    for(int i=last;sum+i*(k-cur)<=n;i++)//剪枝，只用枚举到sum+i*(k-cur)<=n为止
        dfs(i,sum+i,cur+1);
}

int main()
{
    scanf("%d%d",&n,&k);
    dfs(1,0,0);
    printf("%d",cnt);
}
```

## 动态规划 DP



```C++
#include<bits/stdc++.h>
using namespace std;
int n,k,f[201][7];  //f[k][x] k 分成 x 份 ={f[k-1][x-1],f[k-x][x]}
int main(){
    cin >> n >> k;
    for (int i=1;i<=n;i++) {f[i][1]=1;f[i][0]=1;}for (int x=2;x<=k;x++) {f[1][x]=0;f[0][x]=0;}  // 边界，为了防止炸，我把有0的也处理了
    for (int i=2;i<=n;i++)
        for (int x=2;x<=k;x++)
            if (i>x) f[i][x]=f[i-1][x-1]+f[i-x][x];
            else f[i][x]=f[i-1][x-1];
    cout<<f[n][k];
    return 0;
}
```