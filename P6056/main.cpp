#include<bits/stdc++.h>

int s, I, r, n;

int main() {
    double a, b;
    std::cin >> s >> I >> n >> a >> b;
    for (int i = 1; i <= n; i++) {
        int si = s, ii = I;
        r += ceil(ii * b);
        I -= ceil(ii * b);
        I += ceil(a * si * ii);
        s -= ceil(a * si * ii);
        if (s < 0) {
            I += s;
            s = 0;
        }
        if (I < 0) {
            I = 0;
            r += I;
        }
    }
    std::cout << s << ' ' << I << ' ' << r;
    return 0;
}
