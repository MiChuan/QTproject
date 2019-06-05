#ifndef DIALOGSELECTPURCHASE_H
#define DIALOGSELECTPURCHASE_H

#include <QDialog>
#include <QSqlQueryModel>
#include <QTimer>

namespace Ui {
class DialogSelectPurchase;
}

class DialogSelectPurchase : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSelectPurchase(QWidget *parent = 0);
    ~DialogSelectPurchase();

private slots:
    void on_btnsel_clicked();

private:
    Ui::DialogSelectPurchase *ui;
    QSqlQueryModel *model;
};

#endif // DIALOGSELECTPURCHASE_H
