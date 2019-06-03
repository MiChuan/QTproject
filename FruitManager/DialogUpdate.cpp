#include "DialogUpdate.h"
#include "ui_DialogUpdate.h"
#include <QMessageBox>
#include "FruitDaoImp.h"
DialogUpdate::DialogUpdate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogUpdate)
{
    ui->setupUi(this);
}

DialogUpdate::~DialogUpdate()
{
    delete ui;
}

void DialogUpdate::on_buttonBox_accepted()
{
    if(ui->le_name_old->text().isEmpty()||
            ui->le_price_new->text().isEmpty()||
            ui->le_num_new->text().isEmpty())
    {
        QMessageBox::critical(this,"警告","不允许为空");
        return;
    }

    QString name_new;
    if(!ui->le_newname->text().isEmpty())
        name_new = ui->le_newname->text();
    else
        name_new = ui->le_name_old->text();
    double price_new = ui->le_price_new->text().toDouble();
    double num_new = ui->le_num_new->text().toDouble();
    double limit_new = ui->le_limited->text().toDouble();
    Fruit fruit(name_new,price_new,num_new,limit_new);
    FruitDao *fd = new FruitDaoImp();
    qDebug() << fruit.getFruitName() << "|"
           << fruit.getFruitPrice() << "|"
           << fruit.getFruitNum() << "|"
           << fruit.getLimitedNum();
    int ret = fd->updateFruit(fruit, ui->le_name_old->text());
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

void DialogUpdate::on_buttonBox_rejected()
{
    this->close();
}
