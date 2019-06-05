#include "dialogupdatepurchase.h"
#include "ui_dialogupdatepurchase.h"
#include <QMessageBox>
#include "purchasedaoimp.h"

DialogUpdatePurchase::DialogUpdatePurchase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogUpdatePurchase)
{
    ui->setupUi(this);
    this->setWindowTitle("修改进货单信息");
}

DialogUpdatePurchase::~DialogUpdatePurchase()
{
    delete ui;
}

void DialogUpdatePurchase::on_buttonBox_accepted()
{
    if(ui->line_old_pid->text().isEmpty()||
       ui->line_goodsid->text().isEmpty()||
       ui->line_stid->text().isEmpty()||
       ui->line_goodsname->text().isEmpty()||
       ui->line_num->text().isEmpty()||
       ui->line_time->text().isEmpty()||
       ui->line_ma->text().isEmpty()||
            ui->line_new_pid->text().isEmpty())
    {
        QMessageBox::critical(this,"警告","不允许为空");
        return;
    }

    QString id_new;
    if(!ui->line_new_pid->text().isEmpty())
        id_new = ui->line_new_pid->text();
    else
        id_new = ui->line_old_pid->text();
    QString goodsid_new = ui->line_goodsid->text();
    QString stid_new = ui->line_stid->text();
    QString goodsname_new = ui->line_goodsname->text();
    QString num_new = ui->line_num->text();
    QString time_new = ui->line_time->text();
    QString ma_new = ui->line_ma->text();
    QString Check = "?";

    Purchase purch(id_new,goodsid_new,stid_new,goodsname_new,num_new,time_new,ma_new,Check);

    PurchaseDao *fd = new PurchaseDaoImp();

    int ret = fd->updatePurchase(purch, ui->line_old_pid->text());

    if(ret)
    {
        QMessageBox::information(this,"修改","修改成功");
    }
    else
    {
        QMessageBox::critical(this,"修改","修改失败");
    }
    delete(fd);
    fd=NULL;
}

void DialogUpdatePurchase::on_buttonBox_rejected()
{
    this->close();
}
