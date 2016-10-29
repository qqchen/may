#include "db.h"
#include <iostream>

namespace may {

DB::DB()
{

}

//////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////

JsonDB::JsonDB()
{
    //DB();
}

JsonDB::~JsonDB()
{
    for (auto iter = m_datas.begin(); iter != m_datas.end(); ++iter)
    {
        std::vector<Word*>& words = iter->second;
        for (auto wIter = words.begin(); wIter != words.end(); ++wIter)
        {
            Word* pWord = *wIter;
            delete pWord;
            pWord = NULL;
        }
        words.clear();
    }
    m_datas.clear();
}

bool JsonDB::Load(std::string &dbfile)
{
    bool loadSuccess = read(dbfile);
    return loadSuccess;
}

bool JsonDB::Save(std::string& dbfile)
{
    std::cout << "[Json::Save] " << dbfile << std::endl;
    write(dbfile);
    return true;
}

Json::Value JsonDB::serialize()
{
    Json::Value root;
    for (auto iter = m_datas.begin(); iter != m_datas.end(); ++iter)
    {
        std::string date = iter->first;
        std::vector<Word*>& oneDateData = iter->second;
        if (date.empty() || oneDateData.empty())
            continue;

        Json::Value dateVal;
        Json::Value wordVal;
        for (size_t  i = 0; i < oneDateData.size(); ++i)
        {
            Word* pWord = oneDateData[i];
            if (pWord != NULL)
                wordVal.append(pWord->serialize());
        }
        Json::Value val;
        val["date"] = dateVal;
        val["word"] = wordVal;
        root.append(val);
    }
    return root;
}

bool JsonDB::deserialize(Json::Value root)
{
    if (root.isNull())
        return false;

    for (auto i = 0; i < root.size(); ++i)
    {
        Json::Value& val = root[i];
        Json::Value& dateVal = val["date"];
        Json::Value& wordVal = val["word"];
        if (dateVal.isNull() || wordVal.isNull())
            continue;
        std::string date = dateVal.asString();
        std::vector<Word*> oneDateWords;
        for (auto j = 0; j < wordVal.size(); ++j)
        {
            Json::Value& oneWordVal = wordVal[j];
            if (oneWordVal.isNull())
                continue;
            Word* pWord = new Word();
            pWord->deserialize(oneWordVal);
            oneDateWords.push_back(pWord);
        }
        if (date.empty() || oneDateWords.empty())
            continue;
        m_datas.insert(std::pair<std::string, std::vector<Word*> >(date, oneDateWords));
    }

    return true;
}

void JsonDB::AddWord(std::string &word, std::string &meaning)
{
    std::cout << "[Json::AddWord] : " << word << ", " << meaning << std::endl;

    std::string date = Date::CurrentDate().toString();
    auto iter = m_datas.find(date);
    if (iter != m_datas.end())
    {
        std::vector<Word*>& words = iter->second;
        Word* pWord = new Word(word, meaning);
        if(pWord != NULL)
            words.push_back(pWord);
    }
    else
    {
        std::vector<Word*> words;
        Word* pWord = new Word(word, meaning);
        if(pWord != NULL)
        {
            words.push_back(pWord);
            m_datas.insert(std::pair<std::string, std::vector<Word*> >(date, words));
        }
    }
}

}

