#include <iostream>
#include <string>
#include <cctype> // for isalpha and isdigit

using namespace std;

// 函数：分类包裹 ID
string classify_id(const string& package_id) {
    if (isalpha(package_id[0])) { // ID 以字母开头
        if (package_id.substr(1).find_first_not_of("0123456789") == string::npos) {
            return "standard"; // 字母后面全是数字
        }
        else if (package_id.substr(1).find_first_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") != string::npos) {
            if (package_id.substr(1).find_first_of("0123456789") != string::npos) {
                return "mix"; // 字母后面包含字母和数字
            }
            else {
                return "invalid";
            }
        }
        else {
            return "invalid"; // 其他情况
        }
    }
    else if (isdigit(package_id[0])) { // ID 以数字开头
        if (package_id.substr(1).find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") == string::npos) {
            return "special"; // 字母后面全是字母
        }
        else {
            return "invalid"; // 其他情况
        }
    }
    else {
        return "invalid"; // 其他情况
    }
}

int main() {
    int n;
    cin >> n; // 输入包裹数量
    cin.ignore(); // 忽略换行符

    // 处理每个包裹的 ID
    for (int i = 0; i < n; ++i) {
        string package_id;
        getline(cin, package_id); // 读取包裹 ID
        cout << classify_id(package_id) << endl; // 输出分类结果
    }

    return 0;
}
