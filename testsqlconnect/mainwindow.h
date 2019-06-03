#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QSql>
#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include<QSqlError>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<dbhelper.h>
#include <QSqlQueryModel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void showAll();
    ~MainWindow();

private slots:

    void on_btnCnt_clicked();

    void on_btnDcnt_clicked();

    void on_btnAdd_clicked();

    void on_btnDel_clicked();

    void on_btnUpdate_clicked();

    void on_btnSelByname_clicked();

    void on_btnSel_clicked();

private:
    Ui::MainWindow *ui;
    QSqlQueryModel *model;
};

#endif // MAINWINDOW_H
