#ifndef FRUIT_H
#define FRUIT_H
#include<QString>

class Fruit
{
public:
    Fruit(const QString &fruitName,const double &fruitPrice,const double &fruitNum);
    Fruit(const QString &fruitName, const double &fruitPrice, const double &fruitNum, const double &limitedNum);
    QString getFruitName()const;
    double getFruitPrice()const;
    double getFruitNum()const;
    double getLimitedNum()const;
private:
    QString fruitName;
    double fruitPrice;
    double fruitNum;
    double limitedNum;
};

#endif // FRUIT_H
