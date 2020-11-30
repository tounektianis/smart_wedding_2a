#ifndef VOITURE_H
#define VOITURE_H
#include"QString"
#include <QSqlQuery>
#include <QSqlQueryModel>

class voiture
{
public:
    voiture();
     voiture(int,QString,int);
       int getID();
        QString getmodel();
          int getprix();

          void setID(int );
          void setmodel(QString );
          void setprix(int);
          bool ajouter();
          QSqlQueryModel * afficher();
          bool supprimer(int);
          bool modifier();


    private:
          QString model ;
          int ID,prix;
};

#endif // VOITURE_H
