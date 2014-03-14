/**
 * @file main.cpp
 * @brief Point d'entr�e du programme
 * @author Antoine Colmard
 * @author Nicolas Prugne
 */

#include "AutoCompletionDatabase.h"
#include "Mot.h"
#include <ctime>

int main(int argc, char **argv)
{
    double duration;
    std::clock_t start;
    AutoCompletionDatabase database;
    // Chargement du fichier si sp�cifi�
    if (argc > 1)
    {
        start = std::clock();
        std::cout << "Chargement de la base de donnees \"" << argv[1] << "\" en cours ..." << std::endl;
        database = AutoCompletionDatabase(argv[1]);
        duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
        std::cout << "Chargement termine (" << duration << "s)." << std::endl;
    }

    // Recherche motif
	start = std::clock();
	std::cout << "Recherche de mots commencant par \"verbal\" ..." << std::endl; 
	database.affichageMotCompleted("verbal");
	duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
	std::cout << "Recherche terminee (" << duration << "s)." << std::endl;

    // Fermeture base de donn�es
    std::cout << "Dechargement de la base de donnees ..." << std::endl;
	return EXIT_SUCCESS;
}