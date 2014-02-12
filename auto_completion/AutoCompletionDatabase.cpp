#include "AutoCompletionDatabase.h"

AutoCompletionDatabase::AutoCompletionDatabase(void)
{

}

AutoCompletionDatabase::AutoCompletionDatabase(const std::string & fileName)
{
	m_fileName = fileName;
	load(fileName);
}

AutoCompletionDatabase::~AutoCompletionDatabase(void)
{

}

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

bool AutoCompletionDatabase::save(const std::string & fileName) const
{
	bool savingSuccess = true;

	std::ofstream file = std::ofstream(fileName);

	if(file.is_open())
	{
		for(auto mot = m_Database.begin(); mot != m_Database.end(); ++mot)
			file << (*mot).getMot() << (*mot).getOccurences() << std::endl;
	}
	else
		savingSuccess = false;

	return savingSuccess;
}

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

std::list<Mot> AutoCompletionDatabase::autoCompletion(const std::string &partial)
{
    std::list<Mot> autoCompletionList;
    std::list<Mot>::iterator first = std::lower_bound(this->m_Database.begin(), this->m_Database.end(), Mot(partial));
    std::list<Mot>::iterator last = first;
    unsigned int length = partial.length();
	
    while(last != this->m_Database.end() && last->getMot().substr(0,length) == partial)
        ++last;

    for(std::list<Mot>::iterator it = first; it != last; ++it)
    {
        std::list<Mot>::iterator insertIterator = std::lower_bound(autoCompletionList.begin(), autoCompletionList.end(), *it, compareOccurences);
        autoCompletionList.insert(insertIterator, *it);
    }

    return autoCompletionList;
}

void AutoCompletionDatabase::affichageMotCompleted(const std::string &partial)
{
    std::list<Mot> autoCompletedList = this->autoCompletion(partial);

	for (std::list<Mot>::reverse_iterator it = autoCompletedList.rbegin(); it != autoCompletedList.rend(); ++it)
        std::cout << it->getMot() << std::endl;
}

void AutoCompletionDatabase::saveInFile() const
{
	save(m_fileName); //TODO tester si la base a été initilisée à partir d'un fichier, auquel cas la données membre m_fileName sera bien initilisée
						// mais pas dans le cas contraire
}

void AutoCompletionDatabase::saveInFile(const std::string & fileName) const
{
	save(fileName);
}