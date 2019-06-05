#ifndef DIALOGSTOCKMANAGE_H
#define DIALOGSTOCKMANAGE_H

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
#include "DialogDelete.h"
#include "DialogSelect.h"
#include "DialogUpdate.h"
#include "dialoginputstock.h"

namespace Ui {
class DialogStockmanage;
}

class DialogStockmanage : public QDialog
{
    Q_OBJECT

public:
    explicit DialogStockmanage(QWidget *parent = 0);
    void showAllGoods();
    ~DialogStockmanage();

private slots:

    void on_btn_del_clicked();

    void on_btn_flush_clicked();

    void on_btn_update_clicked();

    void on_btn_select_clicked();

    void on_bit_add_clicked();

    void on_bit_input_clicked();

private:
    Ui::DialogStockmanage *ui;
    QSqlQueryModel *model;

    DialogDelete *dialogDelete;
    DialogUpdate *dialogUpdate;
    DialogSelect *dialogSelect;
    DialogInputStock *dialogInputStock;
};

#endif // DIALOGSTOCKMANAGE_H
