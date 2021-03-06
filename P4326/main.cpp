#include <iostream>

#define PI 3.14159265358979323

int main() {
    double r;
    std::cin >> r;
    double s1, s2;

    s1 = PI * r * r;
    s2 = r * r * 2.0;

    printf("%.6f\n%.6f\n", s1, s2);
    return 0;
}

// 这道题关键就是理解“出租车几何”中的圆的半径应该怎么计算
// dis(T1,T2)=sqrt((x1-x2)^2+(y1-y2)^2)
// 所以它的面积也很明确：当边长半径为n时,它就是两个底为2n，高为n的三角形拼合起来。因为沿着格点的线段长度定义不变，角度定义也不变，所以此时，三角形面积公式不变。因此我们得到这个世界下的圆面积公式：
//S=(2n×n÷2)×2=n×n×2S=(2n×n÷2)×2=n×n×2