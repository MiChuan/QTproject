#include "goodsdaoimp.h"

GoodsDaoImp::GoodsDaoImp()
{

}

bool GoodsDaoImp::insertGoods(const Goods &Goods) {
    DBHelper *helper = DBHelper::getInstance();
    helper->openDatabase();
    QSqlQuery query;
    bool ret;
    ret = query.exec(QString("INSERT INTO COMMODITY(CID, CNAME, STID,STORE,MANUFACTURER) VALUES('%1','%2','%3',%4,'%5');").arg(Goods.getGoodsId(),Goods.getGoodsName(),Goods.getGoodsStid(),Goods.getGoodsNum(),Goods.getGoodsMa()));//绑定方式1

    if(ret){qDebug()<<"DaoImp insert success";}
    else{qDebug()<<query.lastError().text();}

    helper->closeDatabase();
    return ret;
}

bool GoodsDaoImp::deleteGoods(const QString &GoodsId) {
    DBHelper *helper = DBHelper::getInstance();
    helper->openDatabase();
    QSqlQuery query;
    bool ret;
    ret = query.exec(QString("delete from COMMODITY where CID = '%1';").arg(GoodsId));//绑定方式

    if(ret){qDebug()<<"DaoImp delete success";}
    else{qDebug()<<query.lastError().text();}

    helper->closeDatabase();
    return ret;
}

bool GoodsDaoImp::updateGoods(const Goods &Goods, const QString & oldid) {
    DBHelper *helper = DBHelper::getInstance();
    helper->openDatabase();
    QSqlQuery query;
    bool ret;
    ret = query.exec(QString("update COMMODITY "
                             "set CID = '%1', "
                             "CNAME = '%2', "
                             "STID = '%3', "
                             "STORE = %4, "
                             "MANUFACTURER = '%5' "
                             "where CID = '%6';").arg(Goods.getGoodsId(),
                                                      Goods.getGoodsName(),
                                                      Goods.getGoodsStid(),
                                                      Goods.getGoodsNum(),
                                                      Goods.getGoodsMa(),
                                                      oldid));//绑定方式

    qDebug() << Goods.getGoodsId() << "|"
           << Goods.getGoodsName() << "|"
           << Goods.getGoodsStid() << "|"
           << Goods.getGoodsNum() << "|"
           << Goods.getGoodsMa();

    if(ret){qDebug()<<"修改成功";}
    else{qDebug()<<query.lastError().text();}

    helper->closeDatabase();
    return ret;
}
