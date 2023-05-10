#include <iostream>

int return_week_day(unsigned int, unsigned int, unsigned int);

int main() {
    int n;
    int year, may, day, week;
    const char *str_week[7] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
    const char *str_may[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul",
                               "Aug", "Sep", "Oct", "Nov", "Dec"};

    std::cout << "Please enter the need to the number: ";
    std::cin >> n;
    std::cout<< "Please input start Date: ";
    scanf("%4d %2d %2d", &year, &may, &day);
//    std::cin >> year >> may >> day;
    std::cout << std::endl;
    week = return_week_day(year, may, day);
    while (n--) {
        std::cout << "git commit --amend --date \"" << str_week[week - 1] << " " << str_may[may - 1] << " " << day
                  << " 11:30:00 " << year << " +0800\"" << std::endl;
        day++;
        week++;
        if (((may == 1 || may == 3 || may == 5 || may == 7 || may == 8 || may == 10 || may == 12) && day > 31) ||
            ((may == 4 || may == 6 || may == 9 || may == 11) && day > 30) ||
            (may == 2 && ((year % 4 == 0 && day > 29 ) || (year % 4 != 0 && day > 28)))) {
            may++;
            day = 1;
        }
        if (week > 7) {
            week -= 7;
        }
    }
    return 0;
}

int return_week_day(unsigned int year, unsigned int month, unsigned int day) {
    int week = 0;
    unsigned int y = 0, c = 0, m = 0, d = 0;
    if (month == 1 || month == 2) {
        c = (year - 1) / 100;
        y = (year - 1) % 100;
        m = month + 12;
        d = day;
    } else {
        c = year / 100;
        y = year % 100;
        m = month;
        d = day;
    }

    week = y + y / 4 + c / 4 - 2 * c + 26 * (m + 1) / 10 + d - 1; //蔡勒公式
    week = week >= 0 ? (week % 7) : (week % 7 + 7); //week为负时取模
    if (week == 0) //星期日不作为一周的第一天
    {
        week = 7;
    }

    return week;
}
