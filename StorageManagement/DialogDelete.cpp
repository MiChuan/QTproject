#include "DialogDelete.h"
#include "ui_DialogDelete.h"
#include <QMessageBox>
#include "goodsdaoimp.h"
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
    if(ui->le_id->text().isEmpty())
    {
        QMessageBox::critical(this,"警告","不允许为空");
        return;
    }

    GoodsDao *fd = new GoodsDaoImp();
    bool ret = fd->deleteGoods(ui->le_id->text());
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
