#include <iostream>
#include <stack>

int main()
{
    std::stack<int> a;
    int num;
    while (true)
    {
        std::cin >> num;
        if (num == 0)
            break;
        a.push(num);
    }
    while (!a.empty())
    {
        std::cout << a.top() << " " ;
        a.pop();
    }

    return 0;
}

//#include<iostream>
//#include<vector>//STL vector的头文件
//using namespace std;
//vector<int> a;//定义一个int型的vector
//int c;//STL可以完全不用担心数组大小的问题,这个和string类似
//int main(){
//    while(1){//有时候也可以巧用死循环
//        cin>>c;
//        if(c==0) break;//终止条件
//        a.push_back(c);//将括号里的元素压入vector尾部
//    }
//    while(!a.empty()){
//        cout<<a.back()<<" ";//.back()是一个返回vector尾部元素的函数
//        a.pop_back();//删除vector尾部的元素
//    }
//    /*
//    这一部分输出程序也可以写成：
//    for(int i=a.size()-1;i>=0;i--){//a.size()返回a中元素的个数
//        cout<<a[i]<<" ";
//    }
//    要注意vector是从a[0]开始存储a.size()个元素，要当心越界访问
//    */
//    return 0;
//}