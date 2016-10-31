#ifndef DB_H
#define DB_H
#include "JsonObject.h"
#include <vector>
#include <map>
#include "word.h"
#include <memory>

namespace may {

class DB
{
public:
    DB();
    virtual bool Load(std::string& dbfile) = 0;
    virtual bool Save(std::string& dbfile) = 0;
    virtual bool AddWord(std::string& word, std::string& meaning) = 0;
    virtual bool HasWord(std::string& word) = 0;
    virtual std::shared_ptr<Word> FindWord(std::string& word) = 0;
};

class JsonDB : public DB, JsonObject
{
public:
    JsonDB();
    ~JsonDB();
    virtual bool Load(std::string &dbfile);
    virtual bool Save(std::string& dbfile);
    virtual bool AddWord(std::string& word, std::string& meaning);
    virtual bool HasWord(std::string& word);
    virtual std::shared_ptr<Word> FindWord(std::string& word);
    virtual Json::Value serialize();
    virtual bool deserialize(Json::Value root);


private:
    std::map<std::string, std::vector<std::shared_ptr<Word>> > m_datas;
};

}



#endif // DB_H
