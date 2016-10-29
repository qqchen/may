#ifndef DB_H
#define DB_H
#include "JsonObject.h"
#include <vector>

namespace may {

class DB
{
public:
    DB();
    virtual void Load(std::string& dbfile) = 0;
};

class JsonDB : public DB
{
public:
    JsonDB();
    virtual void Load(std::string &dbfile);

private:


};

}



#endif // DB_H
