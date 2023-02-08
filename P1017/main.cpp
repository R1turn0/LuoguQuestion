#include <iostream>
#include <string>

using namespace std;
const char nc[20] = {'0', '1', '2', '3', '4', '5', '6',
                     '7', '8', '9', 'A', 'B', 'C', 'D',
                     'E', 'F', 'G', 'H', 'I','J'};
string ans;

int main() {
    int m, n, k, t, s;
    while (cin >> m >> n) {
        ans = "";
        s = m;
        while (m != 0) {
            k = m % n;
            t = m / n;
            if (k < 0) {
                k -= n;
                t++;
            }
            m = t;
            ans.push_back(nc[k]);
        }
        cout << s << "=";
        for (int i = ans.length() - 1; i >= 0; i--) {
            cout << ans[i];
        }
        cout << "(base" << n << ")" << endl;
    }
    return 0;
}


//#include <bits/stdc++.h>
//
//using namespace std;
//
//int main() {
//    char js[] = "0123456789ABCDEFGHIJ";//常量数组保存对应基数，常量大法吼啊
//    int n, r;
//    scanf("%d%d", &n, &r);
//    printf("%d=", n);//提前输出n，因为后面n变化了，如果想在后面输出，就要多加一个变量保存n
//    stack<int> s;//用栈来保存倒序的结果，便于输出
//    while (n) {
//        int a = n % r;
//        n /= r;
//        if (a < 0) {
//            a -= r;
//            n++;
//        }//如果余数为负数，余数减去进制数，商加1
//        s.push(a);//结果进栈
//    }
//    while (!s.empty()) {//输出结果
//        printf("%c", js[s.top()]);
//        s.pop();
//    }
//    printf("(base%d)\n", r);
//    return 0;
//}
