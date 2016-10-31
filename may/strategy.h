#ifndef STRATEGY_H
#define STRATEGY_H
#include <map>
#include <vector>
#include <string>

namespace may {

/**************************************
 * 用于描述学习策略，如随机测试、按天测试
 * ************************************/
template<typename T1, typename T2>
class Strategy
{
public:
    Strategy() {}
    virtual bool GetWordsByKey(T1& key, std::vector<T1>& words, std::vector<T1>& meanings, const std::map<T1, std::vector<T2>>& data) = 0;
    virtual bool AddWordRightCount(T1& key)
    {
        bool found = false;
        for (auto iter = m_currentDatas.begin(); iter != m_currentDatas.end(); ++iter)
        {
            T2& oneWord = *iter;
            if (oneWord->GetWord() == key)
            {
                oneWord->AddRightCount();
                found = true;
                break;
            }
        }
        return found;
    }

    virtual bool AddWordWrongCount(T1& key)
    {
        bool found = false;
        for (auto iter = m_currentDatas.begin(); iter != m_currentDatas.end(); ++iter)
        {
            T2& oneWord = *iter;
            if (oneWord->GetWord() == key)
            {
                oneWord->AddWrongCount();
                found = true;
                break;
            }
        }
        return found;
    }

    std::vector<T2> m_currentDatas;
};

template<typename T1, typename T2>
class RandomTest : public Strategy<T1, T2>
{
public:
    RandomTest() {}
    ~RandomTest() {}
    // 通过key来决定随机提取已掌握的或者还未掌握的词
    virtual bool GetWordsByKey(T1& key, std::vector<T1>& words, std::vector<T1>& meanings, const std::map<T1, std::vector<T2>>& data)
    {
        return true;
    }

};

template<typename T1, typename T2>
class DateTest : public Strategy<T1, T2>
{
public:
    DateTest() {}
    ~DateTest() {}
    // 按天取词
    virtual bool GetWordsByKey(T1& key, std::vector<T1>& words, std::vector<T1>& meanings, const std::map<T1, std::vector<T2>>& data)
    {
        auto iter = data.find(key);
        if (iter == data.end())
            return false;
        words.clear();
        meanings.clear();
        m_currentDatas.clear();
        const std::vector<T2>& datasOfOneDay = iter->second;
        m_currentDatas = datasOfOneDay;
        for (auto dIter = datasOfOneDay.begin(); dIter != datasOfOneDay.end(); ++dIter)
        {
            const T2& oneWord = *dIter;
            words.push_back(oneWord->GetWord());
            meanings.push_back(oneWord->GetMeaning());
        }

        return true;
    }

};


}
#endif // STRATEGY_H
