#include "app.h"

namespace may {

app::app()
{
    m_db = new JsonDB();
    m_randomTest = new RandomTest<std::string, std::vector<Word*>>();
    m_dateTest   = new DateTest<std::string, std::vector<Word*>>();

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

}
