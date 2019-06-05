#ifndef DIALOGVIEWLACK_H
#define DIALOGVIEWLACK_H

#include <QDialog>
#include <QStandardItemModel>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QHeaderView>
#include <QThread>
#include <QDateTime>
#include <QTimer>

#include "dbhelper.h"
#include "dialogselectlack.h"

namespace Ui {
class DialogViewLack;
}

class DialogViewLack : public QDialog
{
    Q_OBJECT

public:
    explicit DialogViewLack(QWidget *parent = 0);
    ~DialogViewLack();
    void showAllLack();

private slots:
    void on_btnflush_clicked();

    void on_btnsel_clicked();

private:
    Ui::DialogViewLack *ui;

    QSqlQueryModel *model;
    DialogSelectLack *dialogSelectLack;
};

#endif // DIALOGVIEWLACK_H
