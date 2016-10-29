#ifndef DB_H
#define DB_H
#include "JsonObject.h"
#include <vector>
#include <map>
#include "word.h"

namespace may {

class DB
{
public:
    DB();
    virtual bool Load(std::string& dbfile) = 0;
    virtual bool Save(std::string& dbfile) = 0;
    virtual void AddWord(std::string& word, std::string& meaning) = 0;
};

class JsonDB : public DB, JsonObject
{
public:
    JsonDB();
    ~JsonDB();
    virtual bool Load(std::string &dbfile);
    virtual bool Save(std::string& dbfile);
    virtual void AddWord(std::string& word, std::string& meaning);
    virtual Json::Value serialize();
    virtual bool deserialize(Json::Value root);


private:
    std::map<std::string, std::vector<Word*> > m_datas;
};

}



#endif // DB_H
