#ifndef DIALOGINPUTSTOCK_H
#define DIALOGINPUTSTOCK_H

#include <QDialog>
#include <QStandardItemModel>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QHeaderView>
#include <QThread>
#include <QDateTime>
#include <QTimer>

#include "dbhelper.h"
#include "purchasedaoimp.h"
#include "dialogdeletepurchase.h"
#include "dialogselectpurchase.h"

namespace Ui {
class DialogInputStock;
}

class DialogInputStock : public QDialog
{
    Q_OBJECT

public:
    explicit DialogInputStock(QWidget *parent = 0);
    ~DialogInputStock();
    void showAllPurchase();

private slots:
    void on_btnflush_clicked();

    void on_btnsel_clicked();

    void on_btndel_clicked();

private:
    Ui::DialogInputStock *ui;
    QSqlQueryModel *model;

    DialogDeletePurchase *dialogDeletePurchase;
    DialogSelectPurchase *dialogSelectPurchase;
};

#endif // DIALOGINPUTSTOCK_H
