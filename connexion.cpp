#include "connexion.h"

Connexion::Connexion()
{}

bool Connexion::ouvrirConnexion()
{

    db=QSqlDatabase::addDatabase("QODBC");

db.setDatabaseName("projet_2a");
db.setUserName("anis");//inserer nom de l'utilisateur
db.setPassword("0000");//inserer mot de passe de cet utilisateur


if (db.open())
return true;
    return  false;
}
void Connexion::fermerConnexion()
{db.close();}
