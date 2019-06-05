#include "dialogdeletepurchase.h"
#include "ui_dialogdeletepurchase.h"
#include <QMessageBox>
#include "purchasedaoimp.h"

DialogDeletePurchase::DialogDeletePurchase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogDeletePurchase)
{
    ui->setupUi(this);
    this->setWindowTitle("删除进货单记录");
}

DialogDeletePurchase::~DialogDeletePurchase()
{
    delete ui;
}

void DialogDeletePurchase::on_buttonBox_2_accepted()
{
    if(ui->line_pid->text().isEmpty()){
        QMessageBox::critical(this,"警告","不允许为空");
        return;
    }

    PurchaseDao *fd = new PurchaseDaoImp();
    bool ret = fd->deletePurchase(ui->line_pid->text());
    if(ret)
    {
        QMessageBox::information(this,"删除","删除成功");
    }
    else
    {
        QMessageBox::critical(this,"删除","删除失败！");
    }
}

void DialogDeletePurchase::on_buttonBox_2_rejected()
{
    this->close();
}
