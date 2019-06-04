#ifndef DIALOGDELETELACK_H
#define DIALOGDELETELACK_H

#include <QDialog>
#include <QString>

namespace Ui {
class DialogDeleteLack;
}

class DialogDeleteLack : public QDialog
{
    Q_OBJECT

public:
    explicit DialogDeleteLack(QWidget *parent = 0);
    ~DialogDeleteLack();

private slots:
    void on_btnOK_accepted();

    void on_btnOK_rejected();

private:
    Ui::DialogDeleteLack *ui;
};

#endif // DIALOGDELETELACK_H
