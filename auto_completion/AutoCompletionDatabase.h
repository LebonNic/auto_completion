#pragma once
#include <algorithm>
#include <list>

#include "Mot.h"

class AutoCompletionDatabase
{
private:
    std::list<Mot> m_Database;
public:
    AutoCompletionDatabase(void);
    ~AutoCompletionDatabase(void);

    void insertMot(Mot &mot);
	bool save(const std::string & fileName);
    std::list<Mot> autoCompletion(const std::string &partial);
};

