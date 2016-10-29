#ifndef DATE_H
#define DATE_H

#include <string>

namespace may{

class Date
{
public:
    Date();
    Date(std::string& date);
    static Date CurrentDate();
    std::string toString();

    int m_year;
    int m_month;
    int m_date;
    int m_hour;
    int m_minute;
};
}

#endif // DATE_H
