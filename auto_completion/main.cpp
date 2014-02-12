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

    return 0;
}