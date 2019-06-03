#include "fruitdaoimp.h"

FruitDaoImp::FruitDaoImp()
{

}

QSqlQuery FruitDaoImp::selectFruits(){
    DBHelper *helper = DBHelper::getInstance();
    helper->connectDatabase();
    QSqlQuery query;
    query.prepare("select * from om_entrepot ");
    query.exec();
    helper->disconnectDatabase();
    return query;
}

QSqlQuery FruitDaoImp::selectFruitByName(QString fruitName){
    DBHelper *helper = DBHelper::getInstance();
    helper->connectDatabase();
    QSqlQuery query;
    query.prepare("select fruitName ,fruitPrice, fruitNum from om_entrepot where fruitName = :fruitName;");
    query.bindValue(":fruitName",fruitName);
    query.exec();
    helper->disconnectDatabase();
    return query;
}

QSqlQuery FruitDaoImp::selectFruitByPrice(double fruitPrice){
    DBHelper *helper = DBHelper::getInstance();
    helper->connectDatabase();
    QSqlQuery query;
    query.prepare("select fruitName ,fruitPrice, fruitNum from fruit_tb where fruitPrice = :fruitPrice;");
    query.bindValue(":fruitPrice",fruitPrice);
    query.exec();
    helper->disconnectDatabase();
    return query;
}

QSqlQuery FruitDaoImp::selectFruitByNum(double fruitNum){
    DBHelper *helper = DBHelper::getInstance();
    helper->connectDatabase();
    QSqlQuery query;
    query.prepare("select fruitName ,fruitPrice, fruitNum from om_entrepot where fruitNum = :fruitNum;");
    query.bindValue(":fruitNum",fruitNum);
    query.exec();
    helper->disconnectDatabase();
    return query;
}

bool FruitDaoImp::insertFruit(const Fruit &fruit) {
    DBHelper *helper = DBHelper::getInstance();
    helper->connectDatabase();
    QSqlQuery query;
    bool ret;
    query.prepare("insert into om_entrepot(fruitName,fruitPrice,fruitNum,limited_number)"
                  "values(:fruitName,:fruitPrice,:fruitNum,:limited_number);");
    query.bindValue(":fruitName",fruit.getFruitName());
    query.bindValue(":fruitPrice",fruit.getFruitPrice());
    query.bindValue(":fruitNum",fruit.getFruitNum());
    query.bindValue(":limited_number",fruit.getLimitedNum());
    ret = query.exec();

    if(ret){qDebug()<<"DaoImp insert success";}
    else{qDebug()<<query.lastError().text();}

    helper->disconnectDatabase();
    return ret;
}

bool FruitDaoImp::deleteFruit(const QString &fruitName) {
    DBHelper *helper = DBHelper::getInstance();
    helper->connectDatabase();
    QSqlQuery query;
    bool ret;
    query.prepare("delete from om_entrepot where fruitName = :fruitName");
    query.bindValue(":fruitName",fruitName);
    ret = query.exec();

    if(ret){qDebug()<<"DaoImp insert success";}
    else{qDebug()<<query.lastError().text();}

    helper->disconnectDatabase();
    return ret;
}

bool FruitDaoImp::updateFruit(const Fruit &fruit, const QString & oldname) {
    DBHelper *helper = DBHelper::getInstance();
    helper->connectDatabase();
    QSqlQuery query;
    bool ret;
    query.prepare("update om_entrepot "
                  "set fruitName = :fruitName, "
                  "fruitPrice = :fruitPrice, "
                  "fruitNum = :fruitNum, "
                  "limited_number = :limitedNum "
                  "where fruitName = :oldname");
    query.bindValue(":fruitName",fruit.getFruitName());
    query.bindValue(":fruitPrice",fruit.getFruitPrice());
    query.bindValue(":fruitNum",fruit.getFruitNum());
    query.bindValue(":limitedNum",fruit.getLimitedNum());
    query.bindValue(":oldname",oldname);
    qDebug() << fruit.getFruitName() << "|"
           << fruit.getFruitPrice() << "|"
           << fruit.getFruitNum() << "|"
           << fruit.getLimitedNum();
    ret = query.exec();

    if(ret){qDebug()<<"修改成功";}
    else{qDebug()<<query.lastError().text();}

    helper->disconnectDatabase();
    return ret;
}
