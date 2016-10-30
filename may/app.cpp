#include "app.h"

namespace may {

app::app()
{
    m_db = new DB();

}

app::~app()
{
    delete m_db;
}

bool app::Load(std::string &dbfile)
{
    m_db->Load(dbfile);
}

bool app::Save(std::string& dbfile)
{
    m_db->Save(dbfile);
}

void app::AddWord(std::string& word, std::string& meaning)
{
    m_db->AddWord(word, meaning);
}

}
