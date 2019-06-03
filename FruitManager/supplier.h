#ifndef SUPPLIER_H
#define SUPPLIER_H
#include<QString>

class Supplier
{
public:
    Supplier(const QString &supplierName,const QString &fruitName, const double &price, const double &number,
           const QString &address, const QString &telephone);
private:
    QString supplierName;
    QString fruitName;
    double price;
    double number;
    QString address;
    QString telephone;

};

#endif // SUPPLIER_H
