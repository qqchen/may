#include "strategy.h"

namespace may {

Strategy::Strategy()
{

}

//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////

RandomTest::RandomTest()
{

}

RandomTest::~RandomTest()
{

}

bool RandomTest::GetWords(std::vector<std::string> &words, std::vector<std::string> &meanings)
{
    return true;
}

//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////

DateTest::DateTest()
{

}

DateTest::~DateTest()
{

}

bool DateTest::GetWords(std::vector<std::string> &words, std::vector<std::string> &meanings)
{
    return true;
}

bool DateTest::GetWordsByDate(std::string &date, std::vector<std::string> &words, std::vector<std::string> &meanings)
{
    return true;
}

}
