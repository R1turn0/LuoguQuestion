#include <cstdio>
using namespace std;
int n,m,k,i,x1,x2,y1,y2,i1,j1,s;
bool b[241][241];
int main()
{
    scanf("%d %d %d",&n,&m,&k); //读入大小以及指令个数
    for (i=1;i<=k;i++)
    {
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2); //读入犁的长方形的坐标(由于题面中说明了x1<x2,y1<y2,所以不用比较).
        for (i1=x1;i1<=x2;i1++)
            for (j1=y1;j1<=y2;j1++) //二重循环,模拟犁田
                if (!b[i1][j1]) //如果当前格子没被犁过
                {
                    s++; //累加计数器
                    b[i1][j1]=1; //作标记
                }
    }
    printf("%d\n",s); //输出格数
}