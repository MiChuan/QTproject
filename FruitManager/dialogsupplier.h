#ifndef DIALOGSUPPLIER_H
#define DIALOGSUPPLIER_H

#include <QWidget>
#include <QStandardItemModel>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QHeaderView>
#include <QThread>
#include <QDateTime>
#include <QTimer>
#include <QSqlTableModel>
#include <dbhelper.h>

namespace Ui {
class DialogSupplier;
}

class DialogSupplier : public QWidget
{
    Q_OBJECT

public:
    explicit DialogSupplier(QWidget *parent = 0);
    void showAllSuppliers();
    ~DialogSupplier();

private slots:
    void on_pushButton_5_clicked();

    void on_btn_flush_clicked();
    
    void on_pushButton_2_clicked();

    void on_pushButton_6_clicked();

    void on_btn_select_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::DialogSupplier *ui;
//    QSqlQueryModel *model;
    QSqlTableModel *model;
    DBHelper *helper = DBHelper::getInstance();
};

#endif // DIALOGSUPPLIER_H
