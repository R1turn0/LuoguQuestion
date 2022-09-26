#include<iomanip>
#include<cstring>
#include<iostream>//C++常用头文件
#include<algorithm>
//头文件--如上
using namespace std;
int a[1001],n,m;//这里是全局变量 ，下面也行！！
int main(){
	//int a[1001],n,m;
    cin>>n>>m;
    for(int i=n;i<=m;i++){
        int j=i;
        while(j>0){//循环
            a[j%10]++;
            j/=10;//更新j的值
        }
    }
    for(int i=0;i<=9;i++){
       cout<<a[i]<<" ";//输出别忘了
    }
    return 0;//（别懒）！！
}