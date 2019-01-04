#ifndef CADASTROUSER_H
#define CADASTROUSER_H

//#include "mainwindow.h"
#include "login.h"
#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QSqlQuery>

namespace Ui {
class cadastroUser;
}

class cadastroUser : public QDialog
{
    Q_OBJECT

public:
    explicit cadastroUser(QWidget *parent = 0);
    ~cadastroUser();

private slots:
    void on_limparButton_clicked();

    void on_cadastrarButton_clicked();

public:
    login *myDB;
    void conectarComparar();
    void conectarSQLite();

private:

    Ui::cadastroUser *ui;


};

#endif // CADASTROUSER_H
