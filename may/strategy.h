#ifndef STRATEGY_H
#define STRATEGY_H
#include <map>
#include <vector>
#include <string>

namespace may {

/**************************************
 * 用于描述学习策略，如随机测试、按天测试
 * ************************************/
class Strategy
{
public:
    Strategy();
    virtual bool GetWords(std::vector<std::string>& words, std::vector<std::string>& meanings) = 0;
};

class RandomTest : public Strategy
{
public:
    RandomTest();
    ~RandomTest();
    virtual bool GetWords(std::vector<std::string>& words, std::vector<std::string>& meanings);

};

class DateTest : public Strategy
{
public:
    DateTest();
    ~DateTest();
    virtual bool GetWords(std::vector<std::string>& words, std::vector<std::string>& meanings);
    bool GetWordsByDate(std::string& date, std::vector<std::string>& words, std::vector<std::string>& meanings);

};


}
#endif // STRATEGY_H
