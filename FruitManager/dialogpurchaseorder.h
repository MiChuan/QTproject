#ifndef DIALOGPURCHASEORDER_H
#define DIALOGPURCHASEORDER_H

#include <QDialog>
#include <QSqlQueryModel>

namespace Ui {
class DialogPurchaseOrder;
}

class DialogPurchaseOrder : public QDialog
{
    Q_OBJECT

public:
    explicit DialogPurchaseOrder(QWidget *parent = 0);
    void showAllPurchaseOrder();
    ~DialogPurchaseOrder();

private slots:
    void on_btn_flush_clicked();

private:
    Ui::DialogPurchaseOrder *ui;
    QSqlQueryModel *model;
};

#endif // DIALOGPURCHASEORDER_H
