/**
 * @file AutoCompletionDatabase.h
 * @brief Déclaration de la classe AutoCompletionDatabase
 * @author Antoine Colmard
 * @author Nicolas Prugne
 */

#pragma once
#include <algorithm>
#include <list>
#include <fstream>
#include <sstream>
#include <iostream>

#include "Mot.h"

/**
 * @brief Classe de stockage des mots pour l'autocomplétion
 */
class AutoCompletionDatabase
{
private:
    std::list<Mot> m_Database;
	std::string m_fileName;

	bool load(const std::string & fileName);
	bool save(const std::string & fileName) const;

    std::list<Mot> autoCompletion(const std::string &partial);
public:
	AutoCompletionDatabase(void);
	AutoCompletionDatabase(const AutoCompletionDatabase & database);
	AutoCompletionDatabase(const std::string & fileName, bool sortLoadedList = true);
	AutoCompletionDatabase & operator=(const AutoCompletionDatabase & database);
    ~AutoCompletionDatabase(void);

    void insertMot(Mot &mot);
	void saveInFile() const;
	void saveInFile(const std::string & fileName) const;
	
    void affichageMotCompleted(const std::string &partial);
};

