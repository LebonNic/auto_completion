#include <iostream>

#include "AutoCompletionDatabase.h"
#include "Mot.h"

int main(int argc, char**argv)
{
    AutoCompletionDatabase database;
    Mot chien("chien");
    Mot chat("chat");
    Mot chatte("chatte");

    database.insertMot(chatte);
    database.insertMot(chien);
    database.insertMot(chat);
    database.insertMot(chatte);

    std::list<Mot> autoCompletion = database.autoCompletion("ieo");

    return 0;
}