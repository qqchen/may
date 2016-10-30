#include "date.h"
#include <ctime>
#include <ratio>
#include <chrono>
#include <iostream>
#include <assert.h>

namespace may {

Date::Date()
{

}

Date::Date(int year, int mon, int day, int hour, int minute)
{
    assert(year > 0 && mon > 0 && mon <= 12 && day > 0 && day < 32 && hour >= 0&& hour < 25 && minute >= 0 && minute < 60);
    m_year = year;
    m_month = mon;
    m_day = day;
    m_hour = hour;
    m_minute = minute;
}

Date::Date(std::string& date)
{

}

Date Date::CurrentDate()
{
//    using std::chrono::system_clock;
//     system_clock::time_point today = system_clock::now();
//     std::time_t tt;
//     tt = system_clock::to_time_t ( today );
//     std::cout << "today is: " << ctime(&tt);
    auto today = std::chrono::system_clock::to_time_t
    (std::chrono::system_clock::now());
     struct tm* ptm = localtime(&today);
     int year = (int)ptm->tm_year + 1900;
     int month = (int)ptm->tm_mon + 1;
     int day = (int)ptm->tm_mday;
     int hour = (int)ptm->tm_hour;
     int minute = (int)ptm->tm_min;
    return Date(year, month, day, hour, minute);
}

std::string Date::toString()
{
    std::string seperate("/");
    std::string currentDateString = std::to_string(m_year) + seperate + std::to_string(m_month) + seperate +
            std::to_string(m_day) + seperate + std::to_string(m_hour) + seperate + std::to_string(m_minute);
    return currentDateString;
}

std::string Date::toDateString()
{
    std::string seperate("/");
    std::string currentDateString = std::to_string(m_year) + seperate + std::to_string(m_month) + seperate + std::to_string(m_day);
    return currentDateString;
}

std::string Date::getCurrentSystemTime()
{
    auto tt = std::chrono::system_clock::to_time_t
    (std::chrono::system_clock::now());
    struct tm* ptm = localtime(&tt);
    char date[60] = {0};
    sprintf(date, "%d-%02d-%02d      %02d:%02d:%02d",
        (int)ptm->tm_year + 1900,(int)ptm->tm_mon + 1,(int)ptm->tm_mday,
        (int)ptm->tm_hour,(int)ptm->tm_min,(int)ptm->tm_sec);
    return std::string(date);
}



}


