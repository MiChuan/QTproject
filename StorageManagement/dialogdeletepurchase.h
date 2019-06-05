#ifndef DIALOGDELETEPURCHASE_H
#define DIALOGDELETEPURCHASE_H

#include <QDialog>
#include <QString>

namespace Ui {
class DialogDeletePurchase;
}

class DialogDeletePurchase : public QDialog
{
    Q_OBJECT

public:
    explicit DialogDeletePurchase(QWidget *parent = 0);
    ~DialogDeletePurchase();

private slots:
    void on_buttonBox_2_accepted();

    void on_buttonBox_2_rejected();

private:
    Ui::DialogDeletePurchase *ui;
};

#endif // DIALOGDELETEPURCHASE_H
