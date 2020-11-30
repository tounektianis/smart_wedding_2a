#include "voiture.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include<QSqlQueryModel>
#include<QSqlQuery>
voiture::voiture()
{ prix=0; ID=0;
    model ="";

}

 voiture::voiture(int ID,QString model,int prix)
 {

this->ID=ID; this->model=model; this->prix=prix;

 }
   int voiture:: getID(){return ID;}
    QString  voiture::getmodel(){return model;}
     int voiture:: getprix(){return prix;}

     void voiture:: setID(int ID ){this->ID=ID;}
      void voiture:: setmodel(QString model ){this->model=model;}

      void voiture:: setprix(int prix){this->prix=prix;}

      bool voiture:: ajouter()
      {
           QSqlQuery query;
           QString id_string= QString::number(ID);

                  query.prepare("INSERT INTO boudinar (id, model,prix) "
                                "VALUES (:id, :name, :place, :typechant,:price)");
                  query.bindValue(":id",id_string);
                  query.bindValue(":name", model);

                  query.bindValue(":price", prix);

                 return query.exec();}

      bool voiture::supprimer(int id)
      {
          QSqlQuery query;
          QString res= QString::number(id);
          query.prepare(" Delete from voiture where id=:id");
          query.bindValue(":id", res);

              return query.exec();}
      QSqlQueryModel* voiture::afficher()
      {
        QSqlQueryModel* model=new QSqlQueryModel();


         model->setQuery("SELECT* FROM voiture");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identenfiant"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));


        return  model;
      }
      bool voiture::modifier()
      {

              QSqlQuery query;
              QString id_string=QString::number(ID);

             query.prepare(" UPDATE voiture SET ID=:ID,model=:model,prix=:prix WHERE ID=:ID");
                    query.bindValue(":ID", id_string);
                    query.bindValue(":model",model);
                    query.bindValue(":soum",prix);


                    return query.exec();


      }
