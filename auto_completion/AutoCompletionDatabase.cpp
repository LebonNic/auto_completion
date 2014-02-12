/**
 * @file AutoCompletionDatabase.cpp
 * @brief Implémentation de la classe AutoCompletionDatabase
 * @author Antoine Colmard
 * @author Nicolas Prugne
 */
#include "AutoCompletionDatabase.h"

#pragma region "Constructeurs"
/**
 * @brief AutoCompletionDatabase::AutoCompletionDatabase Constructeur par défaut de database
 */
AutoCompletionDatabase::AutoCompletionDatabase(void)
{
    m_fileName = "";
}

/**
 * @brief AutoCompletionDatabase::AutoCompletionDatabase Constructeur de database par chargement de fichier
 * @param fileName Nom du fichier à charger
 */
AutoCompletionDatabase::AutoCompletionDatabase(const std::string & fileName)
{
	m_fileName = fileName;
	load(fileName);
}
#pragma endregion

#pragma region "Destructeur"
/**
 * @brief AutoCompletionDatabase::~AutoCompletionDatabase Destructeur de database
 */
AutoCompletionDatabase::~AutoCompletionDatabase(void)
{
    this->saveInFile();
}
#pragma endregion

#pragma region "Serialisation"
/**
 * @brief AutoCompletionDatabase::save Sauvegarde de la database
 * @param fileName Emplacement de la sauvegarde
 * @return True si la sauvegarde a été réalisée avec succès, false sinon
 */
bool AutoCompletionDatabase::save(const std::string & fileName) const
{
	bool savingSuccess = true;

	std::ofstream file = std::ofstream(fileName);

	if(file.is_open())
	{
		for(auto mot = m_Database.begin(); mot != m_Database.end(); ++mot)
			file << mot->getMot() << " " << mot->getOccurences() << std::endl;
	}
	else
		savingSuccess = false;

	return savingSuccess;
}

/**
 * @brief AutoCompletionDatabase::load Charge la database depuis un fichier
 * @param fileName Fichier à charger
 * @return True le chargement a été réalisé avec succès, false sinon
 */
bool AutoCompletionDatabase::load(const std::string & fileName)
{
	bool parsingSuccess = true;

	std::ifstream file = std::ifstream(fileName);
	std::string line,
				word;
	unsigned int occurences;
	
	if(file.is_open())
	{
		while(parsingSuccess && std::getline(file, line))
		{
			std::stringstream ss(line);

			if(!(ss >> word >> occurences))
				parsingSuccess = false;

			else
				m_Database.push_back(Mot(word, occurences));
		}
	}
	else
		parsingSuccess = false;

    return parsingSuccess;
}
#pragma endregion

#pragma region "Méthodes"
/**
 * @brief AutoCompletionDatabase::insertMot Insert un mot dans la database, incrémente ses occurences s'il existe déjà
 * @param mot Mot à insérer
 */
void AutoCompletionDatabase::insertMot(Mot &mot)
{
    std::list<Mot>::iterator insertIterator = std::lower_bound(this->m_Database.begin(), this->m_Database.end(), mot);
    // La liste n'est pas vide ou mot recherché existe déjà dans la database, on incrémente la valeur associée
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

/**
 * @brief AutoCompletionDatabase::autoCompletion Récupère la liste des complétion de la chaîne partielle triés sur leur nombre d'occurences
 * @param partial Chaîne partielle à compléter
 * @return Liste des complétions triées par occurences
 */
std::list<Mot> AutoCompletionDatabase::autoCompletion(const std::string &partial)
{
    std::list<Mot> autoCompletionList;
    std::list<Mot>::iterator first = std::lower_bound(this->m_Database.begin(), this->m_Database.end(), Mot(partial));
    std::list<Mot>::iterator last = first;
    unsigned int length = (unsigned int) partial.length();
	
    while(last != this->m_Database.end() && last->getMot().substr(0,length) == partial)
        ++last;

    for(std::list<Mot>::iterator it = first; it != last; ++it)
    {
        std::list<Mot>::iterator insertIterator = std::lower_bound(autoCompletionList.begin(), autoCompletionList.end(), *it, compareOccurences);
        autoCompletionList.insert(insertIterator, *it);
    }

    return autoCompletionList;
}

/**
 * @brief AutoCompletionDatabase::affichageMotCompleted Affiche les complétions de la chaîne partielle passée
 * @param partial Chaîne partielle à compléter
 */
void AutoCompletionDatabase::affichageMotCompleted(const std::string &partial)
{
    std::list<Mot> autoCompletedList = this->autoCompletion(partial);

	for (std::list<Mot>::reverse_iterator it = autoCompletedList.rbegin(); it != autoCompletedList.rend(); ++it)
        std::cout << it->getMot() << std::endl;
}

/**
 * @brief AutoCompletionDatabase::saveInFile Met à jour le fichier de database chargé
 */
void AutoCompletionDatabase::saveInFile() const
{
    if (m_fileName != "")
    {
	    save(m_fileName);
    }
}

/**
 * @brief AutoCompletionDatabase::saveInFile Sauvegarde le fichier à l'emplacement spécifié
 * @param fileName Emplacement du fichier
 */
void AutoCompletionDatabase::saveInFile(const std::string & fileName) const
{
	save(fileName);
}
#pragma endregion