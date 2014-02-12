/**
 * @file Mot.h
 * @brief Déclaration de la classe Mot
 * @author Antoine Colmard
 * @author Nicolas Prugne
 */

#pragma once

#include <string>

/**
 *	@brief Classe Mot
 *	
 *	This class manages different sets of data in order to propose an interface to manipulate a square grid graph.
 *	The class stores a matrix of nodes and a list of edges. It has a width and an height. And finally,
 *	it uses a PathFinder object to calculate the shortest path between two nodes. 
 */

class Mot
{
private:
	std::string m_Mot;
	unsigned int m_uOccurences;

public:
	Mot(const std::string & s);
	Mot(const Mot & m);
	Mot & operator=(const Mot & m);

	bool operator == (const Mot & m);
	bool operator<(const Mot & m);

	const std::string & getMot() const;
	void incrementerOccurences();

	~Mot(void);
};

