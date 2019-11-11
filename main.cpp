#include <QCoreApplication>
#include<QDebug>
#include<QtSql>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QPluginLoader>
#include<QVariant>

/* Kamu croot banget deh */
void tester_db(int i, QString check);
/* for tutorial testing database */
void tester_db_1();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qInfo()<<"just for testing";

    tester_db_1();
    return a.exec();
}



void tester_db_1(){
    qInfo()<<"menjadi sampah";

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("trumon");
    db.setPassword("tappingbox123");
    db.setDatabaseName("Trumon");
    db.setPort(3306);

    /* try to connection */

    if(!db.open())
    {
        qInfo() << "Could not open connection!";
        qInfo() << db.lastError().text();
    }
    else
    {
        /* Try to command line simple */
        QString cmd;
        /* command prepare for execute */
        cmd = "select * from NeiraIklanVer3 where id = :id";
        QSqlQuery query;
        query.prepare(cmd);
        query.bindValue(":id", 1);
        query.exec();
        /* reading from variable */
        QString value0 = query.value(0).toString();
        qInfo()<<"Value 0 : "<<value0;
        qInfo() << "Connected, lets make a query...";


        db.close();
        qInfo() << "Disconnected";

    }
}
/*
 *      retval : void
 *      Description: to check connection with mysql
*/
void tester_db(int i,  QString check){
    qInfo()<<"index : "<<i;
    qInfo()<<"Check string : "<<check;
    qInfo()<<"Function called";
    QString Hostname = "localhost";
    QString Username = "trumon";
    QString Password = "tappingbox123";
    QString Database = "Trumon";
    int port = 3306;

    /* Standard call for mysql database */
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName(Hostname);
    db.setUserName(Username);
    db.setPassword(Password);
    db.setDatabaseName(Database);
    db.setPort(port);
    if(!db.open())
    {
        qInfo() << "Could not open connection!";
        qInfo() << db.lastError().text();
    }
    else
    {
        qInfo() << "Connected, lets make a query...";
        /*
        QSqlQuery query;
        query.prepare( "INSERT INTO NeiraRecv (data) VALUES (:captureData);" );
        query.bindValue( ":captureData", data );

        if(!query.exec())
        {
            qInfo() << db.lastError().text();
            qInfo() << query.lastError().text();
        }
        else
        {
            qInfo() << "Sukses write, Tan . . ! ! " ;
        }
        */

        db.close();
        qInfo() << "Disconnected";

    }

}
