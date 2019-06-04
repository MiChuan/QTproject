#ifndef DIALOGLACKMANAGE_H
#define DIALOGLACKMANAGE_H

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
#include "lackdaoimp.h"
#include "dialogdeletelack.h"
#include "dialogselectlack.h"
#include "dialogupdatelack.h"

namespace Ui {
class DialogLackManage;
}

class DialogLackManage : public QDialog
{
    Q_OBJECT

public:
    explicit DialogLackManage(QWidget *parent = 0);
    void showAllLack();
    ~DialogLackManage();

private slots:
    void on_btndel_clicked();

    void on_btnflush_clicked();

    void on_btnupdate_clicked();

    void on_btnsel_clicked();

    void on_btnadd_clicked();

private:
    Ui::DialogLackManage *ui;
    QSqlQueryModel *model;

    DialogDeleteLack *dialogDeleteLack;
    DialogUpdateLack *dialogUpdateLack;
    DialogSelectLack *dialogSelectLack;
};

#endif // DIALOGLACKMANAGE_H
