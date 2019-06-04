#ifndef DIALOGUPDATELACK_H
#define DIALOGUPDATELACK_H

#include <QDialog>
#include "lack.h"

namespace Ui {
class DialogUpdateLack;
}

class DialogUpdateLack : public QDialog
{
    Q_OBJECT

public:
    explicit DialogUpdateLack(QWidget *parent = 0);
    ~DialogUpdateLack();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::DialogUpdateLack *ui;
};

#endif // DIALOGUPDATELACK_H
