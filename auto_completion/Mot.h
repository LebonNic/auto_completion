/**
 * @file Mot.h
 * @brief Déclaration de la classe Mot
 * @author Antoine Colmard
 * @author Nicolas Prugne
 */

#pragma once

#include <string>

/**
 * @brief Permet de manipuler une chaine de caractères associée à un nombre d'occurences dans un texte, fichier, etc...
 */
class Mot
{
private:
	std::string m_Mot;
	unsigned int m_uOccurences;

public:
	Mot(const std::string & s);
	Mot(const std::string & s, unsigned int occurences);
	Mot(const Mot & m);
	Mot & operator=(const Mot & m);

	bool operator == (const Mot & m);
	bool operator<(const Mot & m);

	const std::string & getMot() const;
	unsigned int getOccurences() const;
	void incrementerOccurences();

	~Mot(void);
};

bool compareOccurences(const Mot &a, const Mot &b);
