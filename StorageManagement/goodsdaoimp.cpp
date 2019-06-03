#include "goodsdaoimp.h"

GoodsDaoImp::GoodsDaoImp()
{

}

QSqlQuery GoodsDaoImp::selectGoods(){
    DBHelper *helper = DBHelper::getInstance();
    helper->openDatabase();
    QSqlQuery query;
    query.prepare("select * from COMMODITY");
    query.exec();
    helper->closeDatabase();
    return query;
}

QSqlQuery GoodsDaoImp::selectGoodsByName(QString GoodsName){
    DBHelper *helper = DBHelper::getInstance();
    helper->openDatabase();
    QSqlQuery query;
    query.prepare("select * from COMMODITY where CNAME = :CNAME;");
    query.bindValue(":CNAME",GoodsName);
    query.exec();
    helper->closeDatabase();
    return query;
}

QSqlQuery GoodsDaoImp:: selectGoodsById(QString goodsId){
    DBHelper *helper = DBHelper::getInstance();
    helper->openDatabase();
    QSqlQuery query;
    query.prepare("select * from COMMODITY where CID = :CID;");
    query.bindValue(":CID",goodsId);
    query.exec();
    helper->closeDatabase();
    return query;
}

QSqlQuery GoodsDaoImp:: selectGoodsByStid(QString goodsStid){
    DBHelper *helper = DBHelper::getInstance();
    helper->openDatabase();
    QSqlQuery query;
    query.prepare("select * from COMMODITY where STID = :STID;");
    query.bindValue(":STID",goodsStid);
    query.exec();
    helper->closeDatabase();
    return query;
}

QSqlQuery GoodsDaoImp:: selectGoodsByMa(QString goodsMa){
    DBHelper *helper = DBHelper::getInstance();
    helper->openDatabase();
    QSqlQuery query;
    query.prepare("select * from COMMODITY where MANUFACTURER = :MANUFACTURER;");
    query.bindValue(":MANUFACTURER",goodsMa);
    query.exec();
    helper->closeDatabase();
    return query;
}

QSqlQuery GoodsDaoImp::selectGoodsByNum(int GoodsNum){
    DBHelper *helper = DBHelper::getInstance();
    helper->openDatabase();
    QSqlQuery query;
    query.prepare("select * from COMMODITY where STORE = :STORE;");
    query.bindValue(":STORE",GoodsNum);
    query.exec();
    helper->closeDatabase();
    return query;
}

bool GoodsDaoImp::insertGoods(const Goods &Goods) {
    DBHelper *helper = DBHelper::getInstance();
    helper->openDatabase();
    QSqlQuery query;
    bool ret;
    query.prepare("insert into COMMODITY(CID, CNAME, STID,STORE,MANUFACTURER)"
                  "values(:CID,:CNAME,:STID,:STORE,:MANUFACTURER);");
    query.bindValue(":CID",Goods.getGoodsId());
    query.bindValue(":CNAME",Goods.getGoodsName());
    query.bindValue(":STID",Goods.getGoodsStid());
    query.bindValue(":STORE",Goods.getGoodsNum());
    query.bindValue(":MANUFACTURER",Goods.getGoodsMa());
    ret = query.exec();

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
    query.prepare("delete from COMMODITY where CID = :CID");
    query.bindValue(":CID",GoodsId);
    ret = query.exec();

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
    query.prepare("update COMMODITY"
                  "set CID = :CID, "
                  "CNAME = :CNAME, "
                  "STID = :STID, "
                  "STORE = :STORE, "
                  "MANUFACTURER = :MANUFACTURER "
                  "where CID = :oldid");

    query.bindValue(":CID",Goods.getGoodsId());
    query.bindValue(":CNAME",Goods.getGoodsName());
    query.bindValue(":STID",Goods.getGoodsStid());
    query.bindValue(":STORE",Goods.getGoodsNum());
    query.bindValue(":MANUFACTURER",Goods.getGoodsMa());
    query.bindValue(":oldid",oldid);
    qDebug() << Goods.getGoodsId() << "|"
           << Goods.getGoodsName() << "|"
           << Goods.getGoodsStid() << "|"
           << Goods.getGoodsNum() << "|"
           << Goods.getGoodsMa();
    ret = query.exec();

    if(ret){qDebug()<<"修改成功";}
    else{qDebug()<<query.lastError().text();}

    helper->closeDatabase();
    return ret;
}
