#include <iostream>
#include <vector>
#include <stack>
#include <sstream>

#define METHOD2

#ifdef METHOD1
class Solution {
public:
    bool IsPopOrder(std::vector<int>& pushV, std::vector<int>& popV) {
        int j = 0; // 遍历入栈的下标
        int n = pushV.size(); 
        std::stack<int> s; // 辅助栈

        // 遍历出栈的数组
        for (int i = 0; i < n; i++) {
            // 入栈：栈为空或者栈顶不等于出栈数组
            while (j < n && (s.empty() || s.top() != popV[i])) {
                s.push(pushV[j]);
                j++;
            }
            if (s.top() == popV[i])
                s.pop();
            else
                return false;
        }
        return true;
    }
};
#endif

#ifdef METHOD2
#endif
class Solution {
public:
    bool IsPopOrder(std::vector<int>& pushV, std::vector<int>& popV) {
        int n = 0, j = 0;
        for (int num : pushV) {
            pushV[n] = num;
            while (n >= 0 && pushV[n] == popV[j]) {
                j++, n--;
            }
            n++;
        }
        return n == 0;
    }
};

int main() {
    bool result;
    std::vector<int> pushV, popV;
    std::string input;
    std::string temp;
    int num;

    std::getline(std::cin, input);

    // 解析第一个数组
    std::stringstream ss1(input);
    char ch;
    while (ss1 >> ch) {
        if (ch == '[' || ch == ']' || ch == ',') {
            continue;
        }
        else if (isdigit(ch)) {
            ss1.putback(ch);
            ss1 >> num;
            pushV.push_back(num);
        }
    }

    std::getline(std::cin, input);

    // 解析第二个数组
    std::stringstream ss2(input);
    while (ss2 >> ch) {
        if (ch == '[' || ch == ']' || ch == ',') {
            continue;
        }
        else if (isdigit(ch)) {
            ss2.putback(ch);
            ss2 >> num;
            popV.push_back(num);
        }
    }

    Solution solution;
    result = solution.IsPopOrder(pushV, popV);

    if (result)
        std::cout << "True" << std::endl;
    else
        std::cout << "False" << std::endl;
    
    return 0;
}
