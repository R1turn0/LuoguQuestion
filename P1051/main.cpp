#include <iostream>

struct student {
    char name[20];
    int age;
    int ageClass;
    std::string cadre;
    std::string west;
    int thesis;
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
