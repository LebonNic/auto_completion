#pragma once

#include <string>

class Mot
{
private:
	std::string m_Mot;
	unsigned int m_uOccurences;

public:
	Mot(const std::string & s);
	Mot(const Mot & m);
	Mot & operator=(const Mot & m);
	bool operator<(const Mot & m);

	const std::string & getMot() const;
	void incrementerOccurences();

	~Mot(void);
};

