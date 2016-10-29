#include "word.h"

namespace may {

Word::Word()
{
    m_word = "";
    m_phonogram = "";
    m_meaning = "";
    m_addDate = Date::CurrentDate();
    m_recentlyDate = Date::CurrentDate();
    m_rightCount = 0;
    m_wrongCount = 0;
    m_isMaster = false;
}

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

void  Word::init_keys()
{
    m_keys.push_back("word");
    m_keys.push_back("meaning");
    m_keys.push_back("addDate");
    m_keys.push_back("recentlyDate");
    m_keys.push_back("rightCount");
    m_keys.push_back("wrongCount");
    m_keys.push_back("isMaster");
}

Json::Value Word::serialize()
{
    Json::Value root;
    root["word"]         = m_word;
    root["meaning"]      = m_meaning;
    root["addDate"]      = m_addDate.toString();
    root["recentlyDate"] = m_recentlyDate.toString();
    root["rightCount"]   = m_rightCount;
    root["wrongCount"]   = m_wrongCount;
    root["isMaster"]     = m_isMaster ? 1 : 0;
    return root;
}

bool Word::deserialize(Json::Value root)
{
    if(root.isNull() || parse_error(root))
    {
        return false;
    }

    Json::Value val = root["word"];
    m_word = val.asString();
    val = root["meaning"];
    m_meaning = val.asString();
    val = root["addDate"];
    m_addDate = Date(val.asString());
    val = root["recentlyDate"];
    m_recentlyDate = Date(val.asString());
    val = root["rightCount"];
    m_rightCount = val.asInt();
    val = root["wrongCount"];
    m_wrongCount = val.asInt();
    val = root["isMaster"];
    m_isMaster = val.asInt() == 0;

    return true;
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
    bool isRight = word == m_word;
    isRight ? AddRightCount() : AddWrongCount();
    return isRight;
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


