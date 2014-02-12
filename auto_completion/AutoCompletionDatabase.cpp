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