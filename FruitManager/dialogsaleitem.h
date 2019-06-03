#ifndef DIALOGSALEITEM_H
#define DIALOGSALEITEM_H

#include <QDialog>
#include "dbhelper.h"
#include <QSqlDatabase>

namespace Ui {
class DialogSaleItem;
}

class DialogSaleItem : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSaleItem(QWidget *parent = nullptr);
    ~DialogSaleItem();

private slots:
    void on_btn_comfirm_clicked();

private:
    Ui::DialogSaleItem *ui;
};

#endif // DIALOGSALEITEM_H
