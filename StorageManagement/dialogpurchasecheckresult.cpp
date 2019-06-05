#include "dialogpurchasecheckresult.h"
#include "ui_dialogpurchasecheckresult.h"
#include "purchasedaoimp.h"
#include <QMessageBox>
#include <QSqlRecord>

DialogPurchaseCheckResult::DialogPurchaseCheckResult(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogPurchaseCheckResult)
{
    ui->setupUi(this);
    this->setWindowTitle("填写审核意见");
}

DialogPurchaseCheckResult::~DialogPurchaseCheckResult()
{
    delete ui;
}

void DialogPurchaseCheckResult::on_buttonBox_accepted()
{
    if(ui->line_pid->text().isEmpty()){
        QMessageBox::critical(this,"警告","进货单号不允许为空");
        return;
    }

    QString id = ui->line_pid->text();
    QString checkresult = ui->co_result->currentText();

    QSqlQuery query;
    query.exec(QString("select * from STOCK where IID = '%1';").arg(ui->line_pid->text()));

    query.first();
    qDebug()<<query.value(0).toString();
    if(query.value(0).toString() != ui->line_pid->text()){
       qDebug()<<"IID : " + ui->line_pid->text() + " is not existed." ;
       QMessageBox::information(this,"警告","进货单号 : "+ui->line_pid->text()+"不存在");
       return;
    }


    PurchaseDao *fd = new PurchaseDaoImp();

    int ret = fd->purcheckresult(id,checkresult);

    if(ret)
    {
        QMessageBox::information(this,"审核","审核成功");
    }
    else
    {
        QMessageBox::critical(this,"审核","审核失败");
    }
    delete(fd);
    fd=NULL;
}

void DialogPurchaseCheckResult::on_buttonBox_rejected()
{
    this->close();
}
