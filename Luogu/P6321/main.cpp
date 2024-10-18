#include<bits/stdc++.h>
using namespace std;
char a[55][55];
int main () {
    int r,c,zr,zc;//老老实实按题目定义
    cin>>r>>c>>zr>>zc;//r:原行数 c:原列数 zr：放大行数 zc放大列数
    for(int i=1;i<=r;++i){
        for(int j=1;j<=c;++j){
            cin>>a[i][j];
        }
    }//常规二维数组输入
    for(int i=1;i<=r;i++){//四重循环
        //这里控制原行数
        for(int m=1;m<=zr;m++){
            //枚举放大后的行数
            for(int j=1;j<=c;j++){
                //这里控制原列数
                for(int l=1;l<=zc;l++)//枚举放大后的列数
                    putchar(a[i][j]);//输出 （快捷）
            }
            printf("\n");//换行位置很重要 （在这一行所有列的字符输完 后再换行）
        }
    }
    return 0;
}

/*
#include<bits/stdc++.h>
// Forever_chen
#define RT register
using namespace std;
template<class t> inline t read(t &x){
    char c=getchar();bool f=0;x=0;
    while(!isdigit(c)) f|=c=='-',c=getchar();
    while(isdigit(c))x=(x<<1)+(x<<3)+(c^48),c=getchar();
    if(f)x=-x;return x;
}
template<class t>inline void write(t x){
    if(x<0)putchar('-'),write(-x);
    else{if(x>9)write(x/10);putchar('0'+x%10);}
}
template<class t>inline void writeln(t x){
    write(x);putchar('\n');
    return;
}
template<class t>inline void write_blank(t x){
    write(x);putchar(' ');
    return;
}
int r,c,zr,zc;
char ch[60][60];
signed main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    read(r),read(c),read(zr),read(zc);
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin>>ch[i][j];
        }
    }
    for(int i=1;i<=r;i++){
        for(int m=1;m<=zr;m++){
            for(int j=1;j<=c;j++){
                for(int l=1;l<=zc;l++){
                    cout<<ch[i][j];
                }
            }
            cout<<endl;
        }
    }
    //system("pause");
    return 0;
}
*/
