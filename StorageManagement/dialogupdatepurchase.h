#ifndef DIALOGUPDATEPURCHASE_H
#define DIALOGUPDATEPURCHASE_H

#include <QDialog>
#include "purchase.h"

namespace Ui {
class DialogUpdatePurchase;
}

class DialogUpdatePurchase : public QDialog
{
    Q_OBJECT

public:
    explicit DialogUpdatePurchase(QWidget *parent = 0);
    ~DialogUpdatePurchase();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::DialogUpdatePurchase *ui;
};

#endif // DIALOGUPDATEPURCHASE_H
