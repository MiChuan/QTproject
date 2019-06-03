#ifndef DIALOGWAREHOUSE_H
#define DIALOGWAREHOUSE_H

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

namespace Ui {
class DialogWarehouse;
}

class DialogWarehouse : public QDialog
{
    Q_OBJECT

public:
    explicit DialogWarehouse(QWidget *parent = 0);
    void showAllFruits();
    ~DialogWarehouse();

private slots:

    void on_btn_del_clicked();

    void on_btn_add_clicked();

    void on_btn_flush_clicked();

    void on_btn_update_clicked();

    void on_btn_select_clicked();

    void on_bit_add_clicked();

private:
    Ui::DialogWarehouse *ui;
    QSqlQueryModel *model;

    DialogDelete *dialogDelete;
    DialogUpdate *dialogUpdate;
    DialogSelect *dialogSelect;
};

#endif // DIALOGWAREHOUSE_H
