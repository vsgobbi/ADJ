#ifndef LOGIN_H
#define LOGIN_H

//#include <mainwindow.h>
#include <QDialog>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtSql>
#include <QSqlError>
#include <QtDebug>
#include <QMainWindow>
#include <QDialog>
#include <QWidget>
#include <QMessageBox>
#include <QLabel>
#include <QApplication>
#include <QDesktopServices>
#include <QHBoxLayout>
#include <QTextStream>
#include <QString>
#include <QTextEdit>
#include <QCloseEvent>
#include <QPlainTextEdit>
#include <QMessageBox>
#include <QFileInfo>
#include <QString>

// caminho BD = define o arquivo de extensao .sqlite
#define caminhoBD "C:/SQLite/users.sqlite"


namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();

public:

    Ui::login *ui;
    void conectar();
    bool checarConexao ();
    bool conectarUsuario(int testar);
    void criarConexao();
    void conectarSQLite ();
    bool testarUser();
    bool boolCheck;
   //void checkLog();
    void fecharConexao ();

    QString stringLogin;
    QString log;

    QSqlDatabase myDB;
    //ponteiro checkLog para utilizar como sinal de conectado
    int testar;
    //bool BDChecado = false;
    //Variavel inicializando como false
    //bool BDChecado = new bool (false);
    bool BDChecado = false;

    void passaUsuario(QString &stringLog);

    //Inicializando variavel booleana como true
    //bool *loginUser;
    bool loginUser = new bool (true);

private slots:
    void on_limparButton_clicked();
    void on_verificarLog_clicked();

};



#endif // LOGIN_H



