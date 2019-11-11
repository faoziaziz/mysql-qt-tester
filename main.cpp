#include <QCoreApplication>
#include<QDebug>
#include<QtSql>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QPluginLoader>
#include<QVariant>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qInfo()<<"just for testing";


    return a.exec();
}


/*
 *      retval : void
 *      Description: to check connection with mysql
*/
void tester_db(int i,  QString check){
    qInfo()<<"Function called";
    QString Hostname = "localhost";
    QString Username = "username";
    QString Password = "password";
    QString Database = "database";
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
