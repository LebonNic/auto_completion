/**
 * @file Mot.cpp
 * @brief Définition de la classe Mot
 * @author Antoine Colmard
 * @author Nicolas Prugne
 */

#include "Mot.h"

int compareOccurences(const Mot &a, const Mot &b)
{
    return a.
}

Mot::Mot(const std::string & s)
{
	m_Mot = s;
	m_uOccurences = 0;
}

Mot::Mot(const std::string & s, unsigned int occurences)
{
	m_Mot = s;
	m_uOccurences = occurences;
}

Mot::~Mot(void)
{
}

Mot::Mot(const Mot & m)
{
	this->m_Mot = m.m_Mot;
	this->m_uOccurences = m.m_uOccurences;
}

Mot & Mot::operator=(const Mot & m)
{
	if(this != &m)
	{
		this->m_Mot = m.m_Mot;
		this->m_uOccurences = m.m_uOccurences;
	}
	return (*this);
}

bool Mot::operator == (const Mot & m)
{
	return (this->m_Mot == m.m_Mot);
}

const std::string & Mot::getMot() const
{
	return m_Mot;
}

void Mot::incrementerOccurences()
{
	++m_uOccurences;
}

bool Mot::operator<(const Mot & m)
{
	return (this->m_Mot < m.m_Mot);
}
