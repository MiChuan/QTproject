#include "lack.h"

Lack::Lack(const QString &LackId,const QString &outId, const QString &goodsId, const QString &stid,const QString &Lacktime,const QString &Lacknum)
    :LackId(LackId),outId(outId),goodsId(goodsId),stid(stid),Lacktime(Lacktime),Lacknum(Lacknum)
{

}

QString Lack:: getLackId()const{
    return LackId;
}
QString Lack:: getoutId()const{
    return outId;
}
QString Lack:: getgoodsId()const{
    return goodsId;
}
QString Lack:: getstid()const{
    return stid;
}
QString Lack:: getLacktime()const{
    return Lacktime;
}
QString Lack:: getLacknum()const{
    return Lacknum;
}
