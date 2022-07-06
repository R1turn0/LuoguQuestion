#include <iostream>
#include <algorithm>


std::basic_string<char> funtion (std::string s1, std::string s2){
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] < s2[i]) {
            return "-1";
        }
    }
    return s2;
}

int main() {
    int n;
    std::string x, z, y;

    std::cin >> n;
    std::cin >> x >> z;

    std::cout << funtion(x, z);

    return 0;
}

// 这题比较有有意思的地方就是有多个解。
//
//如果X有任何一个地方小于Z，就找不到解，输出-1，结束。
//
//如果没有，因为Y本身就是Z的一种解，就不用找了，直接输出Z。