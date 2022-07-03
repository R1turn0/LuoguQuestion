// https://www.luogu.com.cn/problem/P1014
#include<iostream>
#include<cmath>

int main(){
    long long l = 1, r, mid, n, a;
    std::cin >> n;
    r = n;
    while ( l < r ){
        mid = ( l + r ) / 2;
        if ( mid * ( mid + 1 ) / 2 < n )
            l = mid + 1;
        else
            r = mid;
    }
    a = n - l * ( l - 1 ) / 2;
    if ( l % 2 == 0 )
        std::cout << a << '/' << l + 1 - a;
    else
        std::cout << l + 1 - a << '/' << a;
    return 0;
}