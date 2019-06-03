#include "supplierdaoimp.h"

SupplierDaoImp::SupplierDaoImp()
{

}
QSqlQuery SupplierDaoImp::selectSuppliers(){
    DBHelper *helper = DBHelper::getInstance();
    helper->connectDatabase();
    QSqlQuery query;
    query.prepare("select * from om_supplier ");
    query.exec();
    helper->disconnectDatabase();
    return query;
}
QSqlQuery SupplierDaoImp::selectSupplierByFruitName(QString fruitName){
    DBHelper *helper = DBHelper::getInstance();
    helper->connectDatabase();
    QSqlQuery query;
    query.prepare("select * from om_supplier where fruitName = :fruitName;");
    query.bindValue(":fruitName",fruitName);
    query.exec();
    helper->disconnectDatabase();
    return query;
}
