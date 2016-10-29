#include "word.h"

namespace may {

Word::Word(std::string &word) : m_word(word)
{
    m_phonogram = "";
    m_meaning = "";
    m_addDate = Date::CurrentDate();
    m_recentlyDate = Date::CurrentDate();
    m_rightCount = 0;
    m_wrongCount = 0;
    m_isMaster = false;

}

Word::Word(std::string &word, std::string &meaning)
    : m_word(word), m_meaning(meaning)
{
    m_phonogram = "";
    m_addDate = Date::CurrentDate();
    m_recentlyDate = Date::CurrentDate();
    m_rightCount = 0;
    m_wrongCount = 0;
    m_isMaster = false;
}

void Word::SetMeaning(std::string &meaning)
{
    m_meaning = meaning;
}

void Word::SetRecentlyDate(Date &date)
{
    m_recentlyDate = date;
}

void Word::AddRightCount()
{
    ++m_rightCount;
}

void Word::AddWrongCount()
{
    ++m_wrongCount;
}

void Word::SetIsMaster(bool master)
{
    m_isMaster = master;
}

bool Word::IsRight(std::string &word)
{
    word == m_word ? AddRightCount() : AddWrongCount();
}

std::string Word::GetWord()
{
    return m_word;
}

std::string Word::GetPhonogram()
{
    return m_phonogram;
}

std::string Word::GetMeaning()
{
    return m_meaning;
}

Date Word::GetAddDate()
{
    return m_addDate;
}

Date Word::GetRecentlyDate()
{
    return m_recentlyDate;
}

int Word::GetRightCount()
{
    return m_rightCount;
}

int Word::GetWrongCount()
{
    return m_wrongCount;
}

bool Word::GetIsMater()
{
    return m_isMaster;
}

}


