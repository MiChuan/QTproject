#ifndef DIALOGPURCHASE_H
#define DIALOGPURCHASE_H

#include <QWidget>
#include <QSqlQueryModel>
#include <dbhelper.h>

namespace Ui {
class DialogPurchase;
}

class DialogPurchase : public QWidget
{
    Q_OBJECT

public:
    explicit DialogPurchase(QWidget *parent = 0);
    ~DialogPurchase();

private slots:
    void on_le_fruit_name_textChanged(const QString &arg1);

    void on_cb_supplier_activated(const QString &arg1);

    void on_le_fruit_name_editingFinished();

    void on_pushButton_clicked();

    void on_btn_commit_clicked();

private:
    Ui::DialogPurchase *ui;
    QSqlQueryModel *model;
    DBHelper *helper;
    bool commit_flag = false;
};

#endif // DIALOGPURCHASE_H
