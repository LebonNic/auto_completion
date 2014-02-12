/**
 * @file main.cpp
 * @brief Point d'entrée du programme
 * @author Antoine Colmard
 * @author Nicolas Prugne
 */

#include "AutoCompletionDatabase.h"
#include "Mot.h"

int main(int argc, char**argv)
{
    AutoCompletionDatabase database("../data/data.txt");
	database.affichageMotCompleted("ab");
	system("PAUSE");
	return EXIT_SUCCESS;
}