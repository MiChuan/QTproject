#ifndef DIALOGPURCHASECHECKRESULT_H
#define DIALOGPURCHASECHECKRESULT_H

#include <QDialog>
#include "purchase.h"

namespace Ui {
class DialogPurchaseCheckResult;
}

class DialogPurchaseCheckResult : public QDialog
{
    Q_OBJECT

public:
    explicit DialogPurchaseCheckResult(QWidget *parent = 0);
    ~DialogPurchaseCheckResult();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::DialogPurchaseCheckResult *ui;
};

#endif // DIALOGPURCHASECHECKRESULT_H
