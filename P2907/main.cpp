#include<iostream>

int k;

int f(int a) {        //请别吐槽这个函数名-_-||
    if (a - k > 0 && (a - k) % 2 == 0) return f((a + k) / 2) + f((a - k) / 2);//终于散伙咯
    else return 1;    //想分手!没门
}

int main() {
    int n;
    std::cin >> n >> k;
    std::cout << f(n);
    return 0;
}