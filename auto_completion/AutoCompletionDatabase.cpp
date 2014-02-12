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
    // La liste n'est pas vide ou mot recherch� existe d�j� dans la database, on incr�mente la valeur associ�e
    if (insertIterator != this->m_Database.end() && (*insertIterator) == mot)
    {
        insertIterator->incrementerOccurences();
    }
    // Le mot n'existe pas dans la database, insertion
    else
    {
        this->m_Database.insert(insertIterator, mot);
    }
}

void AutoCompletionDatabase::save(const std::string & fileName)
{
}