#ifndef DIALOGUPDATE_H
#define DIALOGUPDATE_H

#include <QDialog>
#include "Fruit.h"
namespace Ui {
class DialogUpdate;
}

class DialogUpdate : public QDialog
{
    Q_OBJECT

public:
    explicit DialogUpdate(QWidget *parent = 0);
    ~DialogUpdate();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();


private:
    Ui::DialogUpdate *ui;
};

#endif // DIALOGUPDATE_H
