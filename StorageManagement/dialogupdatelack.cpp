#include "dialogupdatelack.h"
#include "ui_dialogupdatelack.h"
#include "lackdaoimp.h"
#include <QMessageBox>

DialogUpdateLack::DialogUpdateLack(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogUpdateLack)
{
    ui->setupUi(this);
    this->setWindowTitle("修改缺货信息");
}

DialogUpdateLack::~DialogUpdateLack()
{
    delete ui;
}

void DialogUpdateLack::on_buttonBox_accepted()
{
    if(ui->line_old_id->text().isEmpty()||
            ui->line_new_id->text().isEmpty()||
            ui->line_outid->text().isEmpty()||
            ui->line_goodsid->text().isEmpty()||
            ui->line_stid->text().isEmpty()||
            ui->line_time->text().isEmpty()||
            ui->line_num->text().isEmpty())
    {
        QMessageBox::critical(this,"警告","不允许为空");
        return;
    }

    QString id_new;
    if(!ui->line_new_id->text().isEmpty())
            id_new = ui->line_new_id->text();
        else
            id_new = ui->line_old_id->text();
        QString outid_new = ui->line_outid->text();
        QString goodsid_new = ui->line_goodsid->text();
        QString stid_new =  ui->line_stid->text();
        QString time_new = ui->line_time->text();
        QString num_new = ui->line_num->text();

        Lack lack(id_new,outid_new,goodsid_new,stid_new,time_new,num_new);

        LackDao *fd = new LackDaoImp();
        qDebug() << lack.getLackId() << "|"
                 << lack.getoutId() << "|"
                 << lack.getgoodsId() << "|"
                 << lack.getstid() << "|"
                 << lack.getLacktime() << "|"
                 << lack.getLacknum();

        int ret = fd->updateLack(lack, ui->line_old_id->text());
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


void DialogUpdateLack::on_buttonBox_rejected()
{
    this->close();
}
