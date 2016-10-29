#ifndef DATE_H
#define DATE_H

namespace {

class Date
{
public:
    Date();
    static Date CurrentDate();

    int m_year;
    int m_month;
    int m_date;
    int m_hour;
    int m_minute;
};
}

#endif // DATE_H
