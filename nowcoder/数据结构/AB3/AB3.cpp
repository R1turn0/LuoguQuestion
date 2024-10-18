#include <iostream>
#include <cstring>
#include <stack>
#include <unordered_map>

class Solution {
private:
    std::string s;  // 将 s 设为私有

public:
    // 构造函数
    Solution(const std::string& input) : s(input) {
    }

    // 获取私有成员 s 的 getter 方法
    std::string getS() const {
        return s;
    }

    // 移除双引号的方法
    std::string removeQuotes(const std::string& s) {
        std::string result = s;

        // 使用 remove() 和 erase() 将双引号去掉
        result.erase(remove(result.begin(), result.end(), '\"'), result.end());

        return result;
    }

    // 判断括号序列是否合法
    bool isValid(const std::string& s) {
        // 定义栈来存放左括号
        std::stack<char> stack;

        // 定义映射，用来匹配右括号对应的左括号
        std::unordered_map<char, char> mapping = { {')', '('}, {'}', '{'}, {']', '['} };

        // 遍历字符串的每个字符
        for (const char& c : s) {
            if (mapping.find(c) == mapping.end()) // 如果是左括号，压入栈中
                stack.push(c);
            else { // 如果是右括号则检查栈顶是否匹配
                if (stack.empty() || stack.top() != mapping[c])
                    return false;
                else
                    stack.pop();
            }
        }
        return stack.empty();
    }
};

int main() {
    std::string input;

    std::cin >> input;

    // 创建 Solution 对象
    Solution slu(input);

    // 调用 getS() 获取私有成员 s，并移除双引号后验证括号序列是否合法
    std::cout << slu.isValid(slu.removeQuotes(slu.getS())) << std::endl;

    return 0;
}
