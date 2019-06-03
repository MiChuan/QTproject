#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "user.h"
#include <QMainWindow>
#include <QDebug>
#include <login.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_login_clicked();
    void onUserLogout();

signals:
    void userLogin(const User &user);

private:
    Ui::MainWindow *ui;
    login *WidgetLogin;
};

#endif // MAINWINDOW_H
