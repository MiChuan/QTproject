#include "dialogdeletelack.h"
#include "ui_dialogdeletelack.h"
#include <QMessageBox>
#include "lackdaoimp.h"

DialogDeleteLack::DialogDeleteLack(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogDeleteLack)
{
    ui->setupUi(this);
    this->setWindowTitle("删除缺货记录");
}

DialogDeleteLack::~DialogDeleteLack()
{
    delete ui;
}


void DialogDeleteLack::on_btnOK_accepted()
{
    if(ui->line_lackid->text().isEmpty())
    {
        QMessageBox::critical(this,"警告","不允许为空");
        return;
    }

    LackDao *fd = new LackDaoImp();
    bool ret = fd->deleteLack(ui->line_lackid->text());
    if(ret)
    {
        QMessageBox::information(this,"删除","删除成功");
    }
        else
        {
            QMessageBox::critical(this,"删除","删除失败！");
        }
}


void DialogDeleteLack::on_btnOK_rejected()
{
    this->close();
}
