#include "AutoCompletionDatabase.h"

AutoCompletionDatabase::AutoCompletionDatabase(void)
{
}


AutoCompletionDatabase::~AutoCompletionDatabase(void)
{

}

void AutoCompletionDatabase::insertMot(Mot &mot)
{
    auto insertIterator = std::lower_bound(this->m_Database.begin(), this->m_Database.end(), mot);
    // Le mot recherch� existe d�j� dans la database, on incr�mente la valeur associ�e
    if ((*insertIterator) == mot)
    {
        insertIterator->incrementerOccurences();
    }
    // Le mot n'existe pas dans la database, insertion
    else
    {
        this->m_Database.insert(insertIterator, mot);
    }
}

bool AutoCompletionDatabase::save(const std::string & fileName)
{
	
}