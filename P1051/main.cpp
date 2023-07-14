#include <iostream>

struct student {
    std::string name;   // 姓名
    int age;            // 平均成绩
    int ageClass;       // 班级平均成绩
    char cadre;         // 是否为学生干部
    char west;          // 是否为西部学生
    int thesis;         // 论文数
};

int main() {
    int n;
    std::cin >> n;
    student stu[n];
    for (int i = 0; i < n; i++) {
        std::cin >> stu[i].name >> stu[i].age >> stu[i].ageClass
        >> stu[i].cadre >> stu[i].west >> stu[i].thesis;
    }
    return 0;
}
