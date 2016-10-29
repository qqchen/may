#ifndef WORD_H
#define WORD_H
#include "date.h"
#include "JsonObject.h"

namespace may {

/***********************************
 * 用于描述英文单词
 * *********************************/
class Word : public JsonObject
{
public:
    Word();
    Word(std::string& word);
    Word(std::string &word, std::string& meaning);

    virtual void init_keys();
    virtual Json::Value serialize();
    virtual bool deserialize(Json::Value root);

    void SetMeaning(std::string& meaning);
    void SetRecentlyDate(Date& date);
    void AddRightCount();
    void AddWrongCount();
    void SetIsMaster(bool master);
    bool IsRight(std::string& word);


    std::string   GetWord();
    std::string   GetPhonogram();
    std::string   GetMeaning();
    Date          GetAddDate();
    Date          GetRecentlyDate();
    int           GetRightCount();
    int           GetWrongCount();
    bool          GetIsMater();

private:
    std::string   m_word;                // 单词全拼
    std::string   m_phonogram;           // 单词音标
    std::string   m_meaning;             // 单词的意思
    Date          m_addDate;             // 添加的时间
    Date          m_recentlyDate;        // 最近学习的时间
    int           m_rightCount;          // 正确记忆的次数
    int           m_wrongCount;          // 错误记忆的次数
    bool          m_isMaster;            // 是否已经掌握
};

}



#endif // WORD_H
