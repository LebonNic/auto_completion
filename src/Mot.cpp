/**
 * @file Mot.cpp
 * @brief Impl�mentation de la classe Mot
 * @author Antoine Colmard
 * @author Nicolas Prugne
 */

#include "Mot.h"

/**
 * @brief compareOccurences Compare le nombre d'occurences entre deux mots
 * @param a Mot a
 * @param b Mot b
 * @return La diff�rence entre le nombre d'occurences de a et de b
 */
bool compareOccurences(const Mot &a, const Mot &b)
{
    return a.getOccurences() < b.getOccurences();
}

/**
 * @brief Mot::operator < Op�rateur de comparaison de mots
 * @param m Mot � comparer
 * @return True si le mot est inf�rieur au mot pass�, false sinon
 */
bool Mot::operator<(const Mot & m)
{
	return (this->m_Mot < m.m_Mot);
}

/**
 * @brief Mot::operator == Op�rateur d'�galit� de mots
 * @param m Mot � comparer
 * @return True si �galit� sur les cha�nes de caract�res, false sinon
 */
bool Mot::operator == (const Mot & m)
{
	return (this->m_Mot == m.m_Mot);
}

/**
 * @brief Mot::Mot Constructeur de mot
 * @param s Valeur de la cha�ne associ�e
 */
Mot::Mot(const std::string & s)
{
	m_Mot = s;
	m_uOccurences = 0;
}

/**
 * @brief Mot::Mot Constructeur
 * @param s Valeur de la cha�ne associ�e
 * @param occurences Nombre d'occurences du mot
 */
Mot::Mot(const std::string & s, unsigned int occurences)
{
	m_Mot = s;
	m_uOccurences = occurences;
}

/**
 * @brief Mot::Mot Constructeur par copie de mot
 * @param m Mot � copier
 */
Mot::Mot(const Mot & m)
{
	this->m_Mot = m.m_Mot;
	this->m_uOccurences = m.m_uOccurences;
}

/**
 * @brief Mot::operator = Op�rateur d'affectation de mot
 * @param m Mot � affecter
 * @return Mot affect�
 */
Mot & Mot::operator=(const Mot & m)
{
	if(this != &m)
	{
		this->m_Mot = m.m_Mot;
		this->m_uOccurences = m.m_uOccurences;
	}
	return (*this);
}

/**
 * @brief Mot::~Mot Destructeur de mot
 */
Mot::~Mot(void)
{
}

/**
 * @brief Mot::getMot Obtient la cha�ne de caract�re li�e
 * @return Cha�ne de caract�re li�e
 */
const std::string & Mot::getMot() const
{
	return m_Mot;
}

/**
 * @brief Mot::getOccurences Obtient le nombre d'occurences du mot
 * @return Nombre d'occurences du mot
 */
unsigned int Mot::getOccurences() const
{
	return m_uOccurences;
}

/**
 * @brief Mot::incrementerOccurences Incr�mente le nombre d'ocurrences du mot
 */
void Mot::incrementerOccurences()
{
	++m_uOccurences;
}
