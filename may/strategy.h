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
    virtual bool GetWordsByKey(T1& key, std::vector<T1>& words, std::vector<T1>& meanings, std::map<T1, T2>& data) = 0;
};

template<typename T1, typename T2>
class RandomTest : public Strategy<T1, T2>
{
public:
    RandomTest() {}
    ~RandomTest() {}
    // 通过key来决定随机提取已掌握的或者还未掌握的词
    virtual bool GetWordsByKey(T1& key, std::vector<T1>& words, std::vector<T1>& meanings, std::map<T1, T2>& data)
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
    virtual bool GetWordsByKey(T1& key, std::vector<T1>& words, std::vector<T1>& meanings, std::map<T1, T2>& data)
    {
        return true;
    }

};


}
#endif // STRATEGY_H
