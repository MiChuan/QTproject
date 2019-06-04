#ifndef DIALOGSELECTLACK_H
#define DIALOGSELECTLACK_H

#include <QDialog>
#include <QSqlQueryModel>
#include <QTimer>

namespace Ui {
class DialogSelectLack;
}

class DialogSelectLack : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSelectLack(QWidget *parent = 0);
    ~DialogSelectLack();

private slots:
    void on_btnselect_clicked();

private:
    Ui::DialogSelectLack *ui;
    QSqlQueryModel *model;
};

#endif // DIALOGSELECTLACK_H
