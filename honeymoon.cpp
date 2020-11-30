#include "honeymoon.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include<QSqlQueryModel>
#include<QSqlQuery>
honeymoon::honeymoon()
{ prix=0; ID=0;
  adresse="";

}

honeymoon:: honeymoon (int ID,QString adresse,int prix)

 {

this->ID=ID;  this->adresse=adresse;this->prix=prix;

 }
   int honeymoon:: getID(){return ID;}

     QString honeymoon:: getadresse(){return adresse;}

     int honeymoon:: getprix(){return prix;}

     void honeymoon:: setID(int ID ){this->ID=ID;}

      void honeymoon:: setadresse(QString adresse ){this->adresse=adresse;}

      void honeymoon:: setprix(int prix){this->prix=prix;}

      bool honeymoon:: ajouter()
      {
           QSqlQuery query;
           QString id_string= QString::number(ID);

                  query.prepare("INSERT INTO honeymoon (id,  adresse,prix) "
                                "VALUES (:id, :place,:price)");
                  query.bindValue(":id",id_string);

                  query.bindValue(":place", adresse);

                  query.bindValue(":price", prix);

                 return query.exec();}

      bool honeymoon::supprimer(int id)
      {
          QSqlQuery query;
          QString res= QString::number(id);
          query.prepare(" Delete from honeymoon where id=:id");
          query.bindValue(":id", res);

              return query.exec();}
      QSqlQueryModel* honeymoon::afficher()
      {
        QSqlQueryModel* model=new QSqlQueryModel();


         model->setQuery("SELECT* FROM honeymoon");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identenfiant"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("adresse"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));


        return  model;
      }
      bool honeymoon::modifier()
      {

              QSqlQuery query;
              QString id_string=QString::number(ID);

             query.prepare(" UPDATE honeymoon SET ID=:ID,adresse=:adresse,prix=:prix WHERE ID=:ID");
                    query.bindValue(":ID", id_string);

                       query.bindValue(":adresse",adresse);

                    query.bindValue(":prix",prix);


                    return query.exec();


      }
