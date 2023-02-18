#include <map>
#include <string>
#include <iostream>

int n;
std::map<std::string, int> mp;

int main() {
    std::cin >> n;
    int ans = 0;
    std::string tmp;
    for (int i = 0; i < n; ++i) {
        std::cin >> tmp;
        int k = i - mp[tmp];
        if (mp[tmp]++ > k) ++ans;
    }
    std::cout << ans << std::endl;
    return 0;
}