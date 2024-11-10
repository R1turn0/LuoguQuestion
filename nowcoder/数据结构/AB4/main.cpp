#include <iostream>
#include <vector>
#include <stack>
#include <string>

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        // write code here
        std::stack<int> st;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int n1 = st.top();
                st.pop();
                int n2 = st.top();
                st.pop();
                if (tokens[i] == "+")st.push(n1 + n2);
                if (tokens[i] == "-")st.push(n2 - n1);
                if (tokens[i] == "*")st.push(n1 * n2);
                if (tokens[i] == "/")st.push(n2 / n1);
            }
            else {
                int k = std::stoi(tokens[i]);
                st.push(k);
            }
        }
        return st.top();

    }
};

int main() {
    Solution sln;
    std::vector<std::string> tokens;

    sln.evalRPN(tokens);
    
    return 0;
}
