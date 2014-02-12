/**
 * @file main.cpp
 * @brief Point d'entrée du programme
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
    // Chargement du fichier si spécifié
    if (argc > 1)
    {
        start = std::clock();
        std::cout << "Chargement de la base de donnees \"" << argv[1] << "\" en cours ..." << std::endl;
        database = AutoCompletionDatabase(argv[1]);
        duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
        std::cout << "Chargement termine (" << duration << "s)." << std::endl;
    }

    // Recherche motif
	database.affichageMotCompleted("verbal");

    // Fermeture base de données
    std::cout << "Dechargement de la base de donnees ..." << std::endl;
	return EXIT_SUCCESS;
}