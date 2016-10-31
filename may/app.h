#ifndef APP_H
#define APP_H

#include "db.h"
#include "strategy.h"
#include <memory>

namespace may {

class app
{
public:
    typedef Strategy<std::string, std::shared_ptr<Word>> LearningStrategy;
    typedef enum {RANDOM_TEST = 0, DATE_TEST} EStrategyType;
    app();
    ~app();
    bool Load(std::string &dbfile);
    bool Save(std::string& dbfile);
    bool AddWord(std::string& word, std::string& meaning);
    bool GetWords(std::vector<std::string>& words, std::vector<std::string>& meanings, EStrategyType type = DATE_TEST);

private:
    DB* m_db;
    LearningStrategy* m_randomTest;
    LearningStrategy* m_dateTest;
    EStrategyType     m_strategyType;
};

}

#endif // APP_H
