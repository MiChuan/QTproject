#include "DialogDelete.h"
#include "ui_DialogDelete.h"
#include <QMessageBox>
#include <FruitDaoImp.h>
DialogDelete::DialogDelete(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogDelete)
{
    ui->setupUi(this);
}

DialogDelete::~DialogDelete()
{
    delete ui;
}

void DialogDelete::on_buttonBox_accepted()
{
    if(ui->le_name->text().isEmpty())
    {
        QMessageBox::critical(this,"警告","不允许为空");
        return;
    }

    FruitDao *fd = new FruitDaoImp();
    bool ret = fd->deleteFruit(ui->le_name->text());
    if(ret)
    {
        QMessageBox::information(this,"删除","删除成功");
    }
    else
    {
        QMessageBox::critical(this,"删除","删除失败！");
    }

}

void DialogDelete::on_buttonBox_rejected()
{
    this->close();
}
