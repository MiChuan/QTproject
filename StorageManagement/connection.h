#ifndef CONNECTION_H
#define CONNECTION_H
#include <QMessageBox>
#include<QSqlError>
#include<QSqlDatabase>
#include<QSqlQuery>

bool OpenDatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");   //数据库驱动类型为SQL Server
    qDebug()<<"ODBC driver?"<<db.isValid();
    QString dsn = QString::fromLocal8Bit("QTDSN");      //数据源名称
    db.setHostName("localhost");                        //选择本地主机，127.0.1.1
    db.setDatabaseName(dsn);                            //设置数据源名称
    db.setUserName("sa");                               //登录用户
    db.setPassword("512013");                              //密码
    if(!db.open())                                      //打开数据库
    {
        qDebug()<<db.lastError().text();
        QMessageBox::critical(0, QObject::tr("Database open fail\n"), db.lastError().text());
        return false;                                   //打开失败
    }
    else
    {
        qDebug()<<"database open success!";
    }

    return true;
}

bool CloseDatabase(){
    if(!db.close()){
        qDebug()<<db.lastError().text();
        QMessageBox::critical(0, QObject::tr("Database close fail!\n"), db.lastError().text());
        return false;                                   //打开失败
    }
    else{
        if(!db.removeDatabase("QTDSN")){
            qDebug()<<db.lastError().text();
            QMessageBox::critical(0, QObject::tr("DSN remove fail!\n"), db.lastError().text());
            return false;
        }
        else{
            qDebug()<<"database open success!";
            return true;
        }
    }

}
#endif // CONNECTION_H
