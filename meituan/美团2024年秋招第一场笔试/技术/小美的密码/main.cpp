#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n; // 输入密码字符串的个数
    string correct_password;
    cin >> correct_password; // 输入正确的密码

    unordered_set<string> unique_passwords; // 使用集合去重
    vector<string> passwords; // 存储记得的密码

    // 输入小美记得的密码
    for (int i = 0; i < n; ++i) {
        string password;
        cin >> password;
        unique_passwords.insert(password); // 去重
    }

    // 将唯一的密码放入向量并排序
    for (const auto& pw : unique_passwords) {
        passwords.push_back(pw);
    }
    sort(passwords.begin(), passwords.end(), [](const string& a, const string& b) {
        return a.size() < b.size(); // 按长度排序
    });

    int min_attempts = 0; // 最少尝试次数
    int max_attempts = 0; // 最多尝试次数
    bool found = false; // 标记是否找到了正确的密码

    // 统计不同长度的密码
    int correct_length = correct_password.size();
    for (const auto& pw : passwords) {
        if (pw.size() < correct_length) {
            max_attempts++; // 对于每个短于正确密码长度的密码
        } else if (pw.size() == correct_length) {
            max_attempts++; // 相同长度密码，最多尝试所有
            if (!found) {
                min_attempts++; // 找到的第一个密码
                found = true; // 标记已找到
            }
        }
    }

    // 输出结果
    cout << min_attempts << " " << max_attempts << endl;
    return 0;
}