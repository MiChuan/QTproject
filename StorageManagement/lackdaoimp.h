#ifndef LACKDAOIMP_H
#define LACKDAOIMP_H
#include "lackdao.h"
#include <QString>
#include <QSqlQuery>
#include <dbhelper.h>
#include <QSqlError>
#include <QDebug>

class LackDaoImp:public LackDao
{
public:
    LackDaoImp();

    bool insertLack(const Lack &lacks);
    bool deleteLack(const QString &lackid);
    bool updateLack(const Lack &lacks, const QString & oldid);
};

#endif // LACKDAOIMP_H
