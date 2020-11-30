#ifndef HONEYMOON_H
#define HONEYMOON_H
#include"QString"
#include <QSqlQuery>
#include <QSqlQueryModel>

class honeymoon
{
public:
    honeymoon();
     honeymoon(int,QString,int);
       int getID();

         QString getadresse();

          int getprix();

          void setID(int );

          void setadresse(QString );
          void setprix(int);
          bool ajouter();
          QSqlQueryModel * afficher();
          bool supprimer(int);
          bool modifier();


    private:
          QString adresse  ;
          int ID,prix;
};

#endif // HONEYMOON_H
