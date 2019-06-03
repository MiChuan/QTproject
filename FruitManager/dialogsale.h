#ifndef DIALOGSALE_H
#define DIALOGSALE_H

#include <QDialog>
#include <QTableView>
#include <QSqlQueryModel>
#include "dbhelper.h"
#include "dialogsaleitem.h"

namespace Ui {
class DialogSale;
}

class DialogSale : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSale(QWidget *parent = nullptr);
    ~DialogSale();

private slots:

    void on_btn_add_clicked();

    void on_btn_flush_clicked();

private:
    Ui::DialogSale *ui;
    DialogSaleItem *dialogSaleItem;
    QSqlQueryModel *model;
    void flush();
};

#endif // DIALOGSALE_H
