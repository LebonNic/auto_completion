#include "AutoCompletionDatabase.h"

AutoCompletionDatabase::AutoCompletionDatabase(void)
{
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
	bool parsingSucces = true;

	std::ifstream file = std::ifstream(fileName);
	std::string line,
				word;
	
	if(file.is_open())
	{
		while(std::getline(file, line))
{
			std::stringstream ss(line);
		}
	}
	else
		parsingSucces = false;

    return parsingSucces;
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