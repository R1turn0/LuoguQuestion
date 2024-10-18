#include <iostream>
#include <string>
#include <cctype> // for isalpha and isdigit

using namespace std;

// ������������� ID
string classify_id(const string& package_id) {
    if (isalpha(package_id[0])) { // ID ����ĸ��ͷ
        if (package_id.substr(1).find_first_not_of("0123456789") == string::npos) {
            return "standard"; // ��ĸ����ȫ������
        }
        else if (package_id.substr(1).find_first_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") != string::npos) {
            if (package_id.substr(1).find_first_of("0123456789") != string::npos) {
                return "mix"; // ��ĸ���������ĸ������
            }
            else {
                return "invalid";
            }
        }
        else {
            return "invalid"; // �������
        }
    }
    else if (isdigit(package_id[0])) { // ID �����ֿ�ͷ
        if (package_id.substr(1).find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") == string::npos) {
            return "special"; // ��ĸ����ȫ����ĸ
        }
        else {
            return "invalid"; // �������
        }
    }
    else {
        return "invalid"; // �������
    }
}

int main() {
    int n;
    cin >> n; // �����������
    cin.ignore(); // ���Ի��з�

    // ����ÿ�������� ID
    for (int i = 0; i < n; ++i) {
        string package_id;
        getline(cin, package_id); // ��ȡ���� ID
        cout << classify_id(package_id) << endl; // ���������
    }

    return 0;
}
