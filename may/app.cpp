#include "app.h"

namespace may {

app::app()
{
    m_db = new JsonDB();
    m_randomTest = new RandomTest<std::string, std::shared_ptr<Word>>();
    m_dateTest   = new DateTest<std::string, std::shared_ptr<Word>>();

}

app::~app()
{
    delete m_db;
}

bool app::Load(std::string &dbfile)
{
    return m_db->Load(dbfile);
}

bool app::Save(std::string& dbfile)
{
    return m_db->Save(dbfile);
}

bool app::AddWord(std::string& word, std::string& meaning)
{
    return m_db->AddWord(word, meaning);
}

bool app::GetWords(std::vector<std::string>& words, std::vector<std::string>& meanings, app::EStrategyType type)
{
    m_strategyType = type;
    if (m_strategyType == RANDOM_TEST)
    {
    }
    else if (m_strategyType == DATE_TEST)
    {
        std::vector<std::string> dates = m_db->GetDates();
        if (!dates.empty())
        {
            std::string lastDay = dates.back();
            m_dateTest->GetWordsByKey(lastDay, words, meanings, m_db->GetDatas());
            return true;
        }
        //return m_dateTest->GetWordsByKey()

    }
    return false;
}

}
