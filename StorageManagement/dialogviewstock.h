#ifndef DIALOGVIEWSTOCK_H
#define DIALOGVIEWSTOCK_H

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
#include "DialogSelect.h"

namespace Ui {
class DialogViewStock;
}

class DialogViewStock : public QDialog
{
    Q_OBJECT

public:
    explicit DialogViewStock(QWidget *parent = 0);
    ~DialogViewStock();
    void showAllGoods();

private slots:
    void on_btnflush_clicked();

    void on_btnselect_clicked();

private:
    Ui::DialogViewStock *ui;
    QSqlQueryModel *model;

    DialogSelect *dialogSelect;
};

#endif // DIALOGVIEWSTOCK_H
