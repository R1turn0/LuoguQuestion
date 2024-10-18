#include <bits/stdc++.h>

int main() {
    int n, x;
    std::cin >> n >> x;
    std::stringstream ss;
    for (n++; --n; ss << n);     //把1-n的值都存放到字符串流中
    std::string s = ss.str();
    std::cout << count(s.begin(), s.end(), x + '0') << std::endl;    //运用count函数直接出结果，简简单单
    return 0;
}