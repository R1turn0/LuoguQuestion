//#include<cstdio>
//
//using namespace std;
//int n, a[40][40], x, y;
//
//int main() {
//    scanf_s("%d", &n, sizeof(int));
//    x = 1, y = (n + 1) / 2;
//    for (int i = 1; i <= n * n; i++) {
//        a[x][y] = i;
//        if (!a[(x - 2 + n) % n + 1][y % n + 1]) x = (x - 2 + n) % n + 1, y = y % n + 1;
//        else x = x % n + 1;//数学运算
//    }
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= n; j++) {
//            printf("%d ", a[i][j]);
//        }
//        printf("\n");
//    }
//}

#include "iostream"

using namespace std;

class A {
    int x;
public:
    A(int i) { x = i; }

    void show() {
        cout << "A class show():x=" << x << endl;
    }

    virtual void display() {
        cout << "A class virtual display():x=" << x << endl;
    }
};

class B : public A {
    int y;
public:
    B(int i, int j) : A(i) { y = j; }

    void show() {
        cout << "B class show(): y=" << y << endl;
    }

    void display()//前面有无virtual都可以
    {
        cout << "B class virtual display():y=" << y << endl;
    }

};

int main(int argc, char *argv[]) {
    A a(5), *pa;
    B b(10, 20);
    pa = &b;
    pa->show();
    pa->display();
    system("pause");
    return 0;
}