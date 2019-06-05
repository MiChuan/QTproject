#include "purchase.h"

Purchase::Purchase(const QString &PId, const QString &GoodsId, const QString &Stid, const QString &GoodsName, const QString &PNum, const QString &PTime, const QString &PMa, const QString &Check)
        :PId(PId),GoodsId(GoodsId),Stid(Stid), GoodsName(GoodsName),PNum(PNum), PTime(PTime), PMa(PMa), Check(Check)
{

}

QString Purchase:: getPId()const{
    return PId;
}
QString Purchase:: getGoodsId()const{
    return GoodsId;
}
QString Purchase:: getStid()const{
    return Stid;
}
QString Purchase:: getGoodsName()const{
    return GoodsName;
}
QString Purchase:: getPNum()const{
    return PNum;
}
QString Purchase:: getPTime()const{
    return PTime;
}
QString Purchase:: getPMa()const{
    return PMa;
}
QString Purchase:: getCheck()const{
    return Check;
}
