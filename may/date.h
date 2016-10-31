#ifndef DATE_H
#define DATE_H

#include <string>

namespace may{

class Date
{
public:
    Date();
    Date(int year, int mon, int day, int hour, int minute);
    // 以字符串的形式传入：年/月/日/时/分
    Date(std::string& date);
    static Date CurrentDate();
    // 返回 年/月/日/时/分
    std::string toString();
    // 只返回 年/月/日
    std::string toDateString();

    static std::string getCurrentSystemTime();
    int m_year;
    int m_month;
    int m_day;
    int m_hour;
    int m_minute;
};
}

#endif // DATE_H
