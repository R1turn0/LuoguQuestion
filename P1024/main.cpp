#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main() {
    double a, b, c, d;
    double as, bs, t, si;
    double x1, x2, x3;
    cin >> a >> b >> c >> d;
    as = b * b - 3 * a * c;
    bs = b * c - 9 * a * d;
    t = (2 * as * b - 3 * a * bs) / (2 * sqrt(as * as * as));
    si = acos(t);
    x1 = (-b - 2 * sqrt(as) * cos(si / 3)) / (3 * a);
    x2 = (-b + sqrt(as) * (cos(si / 3) + sqrt(3) * sin(si / 3))) / (3 * a);
    x3 = (-b + sqrt(as) * (cos(si / 3) - sqrt(3) * sin(si / 3))) / (3 * a);
    cout << fixed << setprecision(2) << x1 << " ";
    cout << fixed << setprecision(2) << x3 << " ";
    cout << fixed << setprecision(2) << x2 << " ";
    return 0;
}
/*
 * 盛金公式：
 * 一元三次方程:aX的三次方+bX的二次方+cX+d=0
 * 重根判别公式：
 *     A=b的二次方-3ac
 *     B=bc-9ad
 *     C=c的二次方-3bd
 * 当A=B=0时，X1=X2=X3= -b/3a= -c/b = -3d/c
 */
