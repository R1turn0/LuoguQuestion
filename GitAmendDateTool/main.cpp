#include <iostream>
#include <iomanip>

int return_week_day(unsigned int, unsigned int, unsigned int);

int main() {
    int n;
    int year, month, day, week;
    const char *str_week[7] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
    const char *str_may[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul",
                               "Aug", "Sep", "Oct", "Nov", "Dec"};

    std::cout << "Please enter the need to the number: ";
    std::cin >> n;
    std::cout << "Please enter the start date (YYYY MM DD): ";
    scanf("%4d %2d %2d", &year, &month, &day);
//    std::cin >> year >> month >> day;
    std::cout << std::endl;
    week = return_week_day(year, month, day);
    while (n--) {
        // 可以使用std::setfill和std::setw设置输出宽度和填充零，确保日期部分的输出格式一致
        std::cout << "git commit --amend --date \""
                  << str_week[week - 1] << " "
                  << str_may[month - 1] << " "
                  << day << " 11:30:00 " << year << " +0800\"" << std::endl;
        day++;
        week++;
        if (((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) &&
             day > 31) ||
            ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) ||
            (month == 2 && ((year % 4 == 0 && day > 29) || (year % 4 != 0 && day > 28)))) {
            month++;
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

    // 蔡勒公式：计算星期的公式
    week = y + y / 4 + c / 4 - 2 * c + 26 * (m + 1) / 10 + d - 1;
    week = week >= 0 ? (week % 7) : (week % 7 + 7); // week为负时取模
    if (week == 0) // 星期日不作为一周的第一天
    {
        week = 7;
    }

    getchar();
    return week;
}
