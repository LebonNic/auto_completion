/**
 * @file Mot.cpp
 * @brief Définition de la classe Mot
 * @author Antoine Colmard
 * @author Nicolas Prugne
 */

#include "Mot.h"

Mot::Mot(const std::string & s)
{
	m_Mot = s;
	m_uOccurences = 0;
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
