#include "db.h"
#include <iostream>
#include <memory>

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
        //std::shared_ptr<Word>
        std::vector<std::shared_ptr<Word>>& words = iter->second;
//        for (auto wIter = words.begin(); wIter != words.end(); ++wIter)
//        {
//            std::shared_ptr<Word> pWord = *wIter;
//            delete pWord;
//            pWord = NULL;
//        }
        words.clear();
    }
    m_datas.clear();
}

bool JsonDB::Load(std::string &dbfile)
{
    bool loadSuccess = read(dbfile);
    //std::cout << "[Json::Load] : size  : " << m_datas.size() << std::endl;
    //std::cout << "[Json::Load] : state : " << loadSuccess << std::endl;
    return loadSuccess;
}

bool JsonDB::Save(std::string& dbfile)
{
    //std::cout << "[Json::Save] " << dbfile << std::endl;
    write(dbfile);
    return true;
}

Json::Value JsonDB::serialize()
{
    Json::Value root;
    for (auto iter = m_datas.begin(); iter != m_datas.end(); ++iter)
    {
        std::string date = iter->first;
        std::vector<std::shared_ptr<Word>>& oneDateData = iter->second;
        if (date.empty() || oneDateData.empty())
            continue;

        Json::Value wordVal;
        for (size_t  i = 0; i < oneDateData.size(); ++i)
        {
            std::shared_ptr<Word> pWord = oneDateData[i];
            if (pWord != NULL)
                wordVal.append(pWord->serialize());
        }
        Json::Value val;
        val["date"] = date;
        val["word"] = wordVal;
        root.append(val);
    }
    return root;
}

bool JsonDB::deserialize(Json::Value root)
{
    if (root.isNull())
        return false;

    //std::cout << "[JsonDB::deserialize] : root size : " << root.size() << std::endl;
    for (auto i = 0; i < root.size(); ++i)
    {
        Json::Value val = root[i];
        Json::Value dateVal = val["date"];
        Json::Value wordVal = val["word"];
        if (dateVal.isNull() || wordVal.isNull())
            continue;
        std::string date = dateVal.asString();
        std::vector<std::shared_ptr<Word>> oneDateWords;
        for (auto j = 0; j < wordVal.size(); ++j)
        {
            Json::Value oneWordVal = wordVal[j];
            if (oneWordVal.isNull())
                continue;
            std::shared_ptr<Word> pWord(new Word());
            pWord->deserialize(oneWordVal);
            oneDateWords.push_back(pWord);
        }
        //std::cout << "[JsonDB::deserialize] : " << date << " " << oneDateWords.size() << std::endl;
        if (date.empty() || oneDateWords.empty())
            continue;
        m_datas.insert(std::pair<std::string, std::vector<std::shared_ptr<Word>> >(date, oneDateWords));
    }

    return true;
}

bool JsonDB::AddWord(std::string &word, std::string &meaning)
{
    //std::cout << "[Json::AddWord] : " << word << ", " << meaning << std::endl;

    if (HasWord(word))
        return false;
    std::string date = Date::CurrentDate().toDateString();
    //std::cout << "[Json::AddWord] : current date : " << date << std::endl;

    auto iter = m_datas.find(date);
    if (iter != m_datas.end())
    {
        std::vector<std::shared_ptr<Word>>& words = iter->second;
        std::shared_ptr<Word> pWord(new Word(word, meaning));
        if(pWord != NULL)
            words.push_back(pWord);
    }
    else
    {
        std::vector<std::shared_ptr<Word>> words;
        std::shared_ptr<Word> pWord(new Word(word, meaning));
        if(pWord != NULL)
        {
            words.push_back(pWord);
            m_datas.insert(std::pair<std::string, std::vector<std::shared_ptr<Word>> >(date, words));
        }
    }
    return true;
}

bool JsonDB::HasWord(std::string &word)
{
    std::shared_ptr<Word> pWord = FindWord(word);
    return pWord != NULL;
}

std::shared_ptr<Word> JsonDB::FindWord(std::string &word)
{
    for(auto iter = m_datas.begin(); iter != m_datas.end(); ++iter)
    {
        std::vector<std::shared_ptr<Word>> words = iter->second;
        for (auto wIter = words.begin(); wIter != words.end(); ++wIter)
        {
            std::shared_ptr<Word> pWord = *wIter;
            if (pWord->GetWord() == word)
                return pWord;
        }
    }
    return NULL;
}

const DB::DataMap& JsonDB::GetDatas()
{
    return m_datas;
}

std::vector<std::string> JsonDB::GetDates()
{
    std::vector<std::string> dates;
    for(auto iter = m_datas.begin(); iter != m_datas.end(); ++iter)
    {
        dates.push_back(iter->first);
    }
    return dates;
}

//const JsonDB::DataMap& JsonDB::GetDatas()
//{
//    return m_datas;
//}

}

