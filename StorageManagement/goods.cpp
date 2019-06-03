#include "goods.h"

Goods::Goods(const QString &goodsId,const QString &goodsName, const QString &goodsStid, const int &goodsNum,const QString &goodsMa)
    :goodsId(goodsId),goodsName(goodsName),goodsStid(goodsStid),goodsNum(goodsNum), goodsMa(goodsMa)
{

}

QString Goods::getGoodsName()const{
    return goodsName;
}
QString Goods::getGoodsId()const{
    return goodsId;
}
QString Goods::getGoodsStid()const{
    return goodsStid;
}
int Goods::getGoodsNum()const{
    return goodsNum;
}
QString Goods::getGoodsMa()const{
    return goodsMa;
}
