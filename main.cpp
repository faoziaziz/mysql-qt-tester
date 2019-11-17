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
/* for tester_db_1 akan menjadi setting database */
void tester_db_2();
/* for testring update status */
void tester_db_3();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qInfo()<<"just for testing";

   // tester_db_1();
    tester_db_3();
    //tester_db_2();
    return a.exec();
}
void tester_db_2(){
    qInfo()<<"Database testing for second";

}
/*
 * retval nya void
 * descriptionnya untuk testing dengan database yang pertama.
*/

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
        cmd = "SELECT * FROM `Trumon`.`NeiraIklanVer3` WHERE MemberID=:flag ORDER BY `NO` DESC LIMIT 1;";
        QSqlQuery query;
        query.prepare(cmd);
        query.bindValue(":flag", "TEST1_LOL");
        query.exec();

        /* reading from variable */
        while(query.next()){
            QString value0 = query.value(0).toString();
            qInfo()<<"Value 0 : "<<value0;
            qInfo() << "Connected, lets make a query...";

        }


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

void tester_db_3(){
    
    /* QSql database to setting connection */
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
        qInfo()<<"Tester db3 ";
        QString cmd;
        QSqlQuery query;
        int idtanggal=1573727630;

        cmd = "Update NeiraIklanVer3 set Flag=1 where ID_TGL=:IdTanggal";
        query.prepare(cmd);
        query.bindValue(":idTanggal", idtanggal);
        if(!query.exec()){
            qInfo()<<"tidak tereksekusi";
        }
        else{
            qInfo()<<"tereksekusi";

        }
    }



}
