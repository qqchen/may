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
    typedef std::vector<std::shared_ptr<Word>> WordVector;
    typedef std::map<std::string, WordVector> DataMap;
    DB();
    virtual bool Load(std::string& dbfile) = 0;
    virtual bool Save(std::string& dbfile) = 0;
    virtual bool AddWord(std::string& word, std::string& meaning) = 0;
    virtual bool HasWord(std::string& word) = 0;
    virtual std::shared_ptr<Word> FindWord(std::string& word) = 0;
    virtual const DataMap& GetDatas() = 0;
    virtual std::vector<std::string> GetDates() = 0;
    //virtual const DataMap& GetDatas();
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
    virtual const DataMap& GetDatas();
    virtual std::vector<std::string> GetDates();



private:
    DataMap m_datas;
};

}



#endif // DB_H
