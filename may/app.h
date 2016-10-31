#ifndef APP_H
#define APP_H

#include "db.h"
#include "strategy.h"
namespace may {

class app
{
public:
    typedef Strategy<std::string, std::vector<Word*>> LearningStrategy;
    app();
    ~app();
    bool Load(std::string &dbfile);
    bool Save(std::string& dbfile);
    bool AddWord(std::string& word, std::string& meaning);

private:
    DB* m_db;
    LearningStrategy* m_randomTest;
    LearningStrategy* m_dateTest;
};

}

#endif // APP_H
