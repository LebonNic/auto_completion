#pragma once
#include <algorithm>
#include <list>
#include <fstream>
#include <sstream>
#include <iostream>

#include "Mot.h"

class AutoCompletionDatabase
{
private:
    std::list<Mot> m_Database;

	bool load(const std::string & fileName);
    std::list<Mot> autoCompletion(const std::string &partial);
public:
	AutoCompletionDatabase(void);
	AutoCompletionDatabase(const std::string & fileName);
    ~AutoCompletionDatabase(void);

    void insertMot(Mot &mot);
	bool save(const std::string & fileName) const;
	
    void affichageMotCompleted(const std::string &partial);
};

