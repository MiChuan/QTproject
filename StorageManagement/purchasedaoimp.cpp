#include "purchasedaoimp.h"

PurchaseDaoImp::PurchaseDaoImp()
{

}

bool PurchaseDaoImp:: insertPurchase(const Purchase &Purchases){//不要忘记引用类！
    DBHelper *helper = DBHelper::getInstance();
    helper->openDatabase();
    QSqlQuery query;
    bool ret;
    ret = query.exec(QString("INSERT INTO STOCK VALUES('%1','%2','%3','%4',%5,'%6','%7','%8');").arg(
                         Purchases.getPId(),Purchases.getGoodsId(),Purchases.getStid(),Purchases.getGoodsName(),
                         Purchases.getPNum(),Purchases.getPTime(),Purchases.getPMa(),Purchases.getCheck()));

    if(ret){qDebug()<<"DaoImp insert success";}
    else{qDebug()<<query.lastError().text();}

    helper->closeDatabase();
    return ret;
}

bool PurchaseDaoImp:: deletePurchase(const QString &Purchaseid){
    DBHelper *helper = DBHelper::getInstance();
    helper->openDatabase();
    QSqlQuery query;
    bool ret;
    ret = query.exec(QString("delete from STOCK where IID = '%1';").arg(Purchaseid));

    if(ret){qDebug()<<"DaoImp delete success";}
    else{qDebug()<<query.lastError().text();}

    helper->closeDatabase();
    return ret;
}

bool PurchaseDaoImp:: updatePurchase(const Purchase &Purchases, const QString & oldid){
    DBHelper *helper = DBHelper::getInstance();
    helper->openDatabase();
    QSqlQuery query;
    bool ret;
    ret = query.exec(QString("update STOCK "
                             "set IID = '%1', "
                             "CID = '%2', "
                             "STID = '%3', "
                             "CNAME = '%4', "
                             "SNUM = %5, "
                             "STIME = '%6', "
                             "MANUFACTURER = '%7', "
                             "CHECKRESULT = '%8' "
                             "where IID = '%9'; ").arg(Purchases.getPId(),
                                                      Purchases.getGoodsId(),
                                                      Purchases.getStid(),
                                                      Purchases.getGoodsName(),
                                                      Purchases.getPNum(),
                                                      Purchases.getPTime(),
                                                      Purchases.getPMa(),
                                                      Purchases.getCheck(),
                                                      oldid));


    qDebug() << Purchases.getPId() << "|"
             << Purchases.getGoodsId() << "|"
             << Purchases.getStid() << "|"
             << Purchases.getGoodsName() << "|"
             << Purchases.getPNum() << "|"
             << Purchases.getPTime() << "|"
             << Purchases.getPMa() << "|"
             << Purchases.getCheck();

    if(ret){qDebug()<<"修改成功";}
    else{qDebug()<<query.lastError().text();}

    helper->closeDatabase();
    return ret;
}

bool PurchaseDaoImp::purcheckresult(const QString &id,const QString &checkresult){
    DBHelper *helper = DBHelper::getInstance();
    helper->openDatabase();
    QSqlQuery query;
    bool ret;
    ret = query.exec(QString("update STOCK set CHECKRESULT = '%1' where IID = '%2'; ").arg(checkresult,id));

    if(ret){qDebug()<<"修改成功";}
    else{qDebug()<<query.lastError().text();}

    helper->closeDatabase();
    return ret;
}
