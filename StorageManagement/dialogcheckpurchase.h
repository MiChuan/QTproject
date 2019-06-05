#ifndef DIALOGCHECKPURCHASE_H
#define DIALOGCHECKPURCHASE_H

#include <QDialog>
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
#include "dialogselectpurchase.h"
#include "dialogpurchasecheckresult.h"

namespace Ui {
class DialogCheckPurchase;
}

class DialogCheckPurchase : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCheckPurchase(QWidget *parent = 0);
    ~DialogCheckPurchase();
    void showAllPurchase();

private slots:
    void on_btnflush_clicked();

    void on_btnsel_clicked();

    void on_btncheck_clicked();

private:
    Ui::DialogCheckPurchase *ui;
    QSqlQueryModel *model;

    DialogSelectPurchase *dialogSelectPurchase;
    DialogPurchaseCheckResult *dialogPurchaseCheckResult;
};

#endif // DIALOGCHECKPURCHASE_H
