#include "fruit.h"

Fruit::Fruit(const QString &fruitName, const double &fruitPrice, const double &fruitNum)
    :fruitName(fruitName),fruitPrice(fruitPrice),fruitNum(fruitNum), limitedNum(0.0)
{

}

Fruit::Fruit(const QString &fruitName, const double &fruitPrice, const double &fruitNum, const double &limitedNum)
    :fruitName(fruitName),fruitPrice(fruitPrice),fruitNum(fruitNum), limitedNum(limitedNum)
{

}

QString Fruit::getFruitName() const
{
    return fruitName;
}

double Fruit::getFruitPrice() const
{
    return fruitPrice;
}

double Fruit::getFruitNum() const
{
    return fruitNum;
}

double Fruit::getLimitedNum() const
{
    return limitedNum;
}

