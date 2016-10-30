#ifndef APP_H
#define APP_H

#include "db.h"

namespace may {

class app
{
public:
    app();
    ~app();
    bool Load(std::string &dbfile);
    bool Save(std::string& dbfile);
    void AddWord(std::string& word, std::string& meaning);

private:
    DB* m_db;
};

}

#endif // APP_H
