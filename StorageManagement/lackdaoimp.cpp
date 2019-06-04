#include "lackdaoimp.h"

LackDaoImp::LackDaoImp()
{

}

bool LackDaoImp:: insertLack(const Lack &lacks){//不要忘记引用类！
    DBHelper *helper = DBHelper::getInstance();
    helper->openDatabase();
    QSqlQuery query;
    bool ret;
    ret = query.exec(QString("INSERT INTO STOCKOUT(SOID,DID,CID,STID,SOTIME,SONUM) VALUES('%1','%2','%3','%4','%5',%6);").arg(lacks.getLackId(),lacks.getoutId(),lacks.getgoodsId(),lacks.getstid(),lacks.getLacktime(),lacks.getLacknum()));

    if(ret){qDebug()<<"DaoImp insert success";}
    else{qDebug()<<query.lastError().text();}

    helper->closeDatabase();
    return ret;
}

bool LackDaoImp:: deleteLack(const QString &lackid){
    DBHelper *helper = DBHelper::getInstance();
    helper->openDatabase();
    QSqlQuery query;
    bool ret;
    ret = query.exec(QString("delete from STOCKOUT where SOID = '%1';").arg(lackid));

    if(ret){qDebug()<<"DaoImp delete success";}
    else{qDebug()<<query.lastError().text();}

    helper->closeDatabase();
    return ret;
}

bool LackDaoImp:: updateLack(const Lack &lacks, const QString & oldid){
    DBHelper *helper = DBHelper::getInstance();
    helper->openDatabase();
    QSqlQuery query;
    bool ret;
    ret = query.exec(QString("update STOCKOUT "
                             "set SOID = '%1', "
                             "DID = '%2', "
                             "CID = '%3', "
                             "STID = '%4', "
                             "SOTIME = '%5', "
                             "SONUM = %6 "
                             "where SOID = '%7';").arg(lacks.getLackId(),
                                                      lacks.getoutId(),
                                                      lacks.getgoodsId(),
                                                      lacks.getstid(),
                                                      lacks.getLacktime(),
                                                      lacks.getLacknum(),
                                                      oldid));


    qDebug() << lacks.getLackId() << "|"
             << lacks.getoutId() << "|"
             << lacks.getgoodsId() << "|"
             << lacks.getstid() << "|"
             << lacks.getLacktime() << "|"
             << lacks.getLacknum();

    if(ret){qDebug()<<"修改成功";}
    else{qDebug()<<query.lastError().text();}

    helper->closeDatabase();
    return ret;
}
