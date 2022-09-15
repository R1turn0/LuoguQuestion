#include <bits/stdc++.h>

using namespace std;

int a, b, c, d, p[10];

string check(int x) {
    if (0 < x % (a + b) && x % (a + b) <= a && 0 < x % (c + d) && x % (c + d) <= c) {
        return "both";
    }
    if((x % (a + b) > a || x % (a + b) == 0) && (x % (c + d) > c || x % (c + d) == 0)) {
        return "none";
    }
    else{
        return "one";
    }
}

int main(){
    cin >> a >> b >> c >> d >> p[1] >> p[2] >> p[3];
    for (int i = 1; i <= 3; ++i){
        cout << check(p[i]) << endl;
    }
    return 0;
}