#include<bits/stdc++.h>

static std::string str[20];
static int use[20], length = 0, n;

void solve(std::string strnow, int lengthnow);

int canlink(std::string str1, std::string str2);

int main() {
    std::cin >> n;
    for (int i = 0; i <= n; i++) use[i] = 0, std::cin >> str[i]; // str[n]Ϊ��ʼ�ַ�
    // Ϊ��ָ����һ���ַ���������Ϊcanlink��Ҫ�ص�����С����̳���-1������Ҫ��ǰ�����һ��������䳤�ȵġ� ����������ǿ����canlink�����Ƚ����һλ��
    solve(' ' + str[n], 1);
    std::cout << length << std::endl;
    return 0;
}

void solve(std::string strnow, int lengthnow) {
    length = std::max(lengthnow, length); // ������󳤶�
    for (int i = 0; i < n; i++) {
        if (use[i] >= 2) continue; // ���ַ���ʹ�ô�����ҪС��2
        int c = canlink(strnow, str[i]);//��ȡ�ص�����
        if (c > 0) { // ���ص����־Ϳ�ʼdfs
            use[i]++;
            solve(str[i], lengthnow + str[i].length() - c);
            use[i]--;
        }
    }
}

int canlink(std::string str1, std::string str2) {
    for (int i = 1; i < std::min(str1.length(), str2.length()); i++) { // �ص����ȴ�1��ʼ��ֱ����̵��ַ�������-1����Ϊ���ܰ�����
        int flag = 1;
        for (int j = 0; j < i; j++)
            if (str1[str1.length() - i + j] != str2[j]) flag = 0; // �������Ƿ����
        if (flag) return i; // ���������������return
    }
    return 0; // ���ص����֣�����0
}
