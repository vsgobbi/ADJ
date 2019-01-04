#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <login.h>
#include <cadastroUser.h>
#include <seconddialog.h>
#include <procpickinglist.h>
#include <QMainWindow>
#include <QDialog>
#include <QWidget>
#include <QMessageBox>
#include <QLabel>
#include <QApplication>
#include <QFileDialog>
#include <QFileInfo>
#include <QDesktopServices>
#include <QHBoxLayout>
#include <QTextStream>
#include <QString>
#include <QTextEdit>
#include <QCloseEvent>
#include <QPlainTextEdit>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtSql>
#include <QUrl>
#include <QtDebug>
#include <QSqlDatabase>
#include <QAxObject>
#include <ActiveQt>
#include <QAxFactory>
#include <QDesktopServices>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0); // construtor sem pai
    ~MainWindow();

private slots:

    void on_actionAbrir_triggered();

    void on_actionSair_triggered();

    void on_actionSobre_triggered();

    void on_actionProcurar_items_triggered();

    void on_actionSalvarComo_triggered();

    void on_actionOpc_es_triggered();

    void on_loginButton_clicked();

    void on_commandLinkButton_clicked();

    void on_logoutButton_clicked();

    void on_actionDocumentos_triggered();

    void on_actionBanco_de_dados_triggered();

    void on_actionHist_rico_triggered();

public slots:
    void atualizarQtimer();
    void conectarComparar();

public:
    Ui::MainWindow *ui;
    secondDialog *second;

    void salvarComo ();
    void mensagemSalvar ();
    void fecharConexao();
    bool checarLogin();

    QString vaiLogo;
    //QString curFile;
    QPlainTextEdit *textEdit;
    login *loginObj;
    login *myBD;
    login *boolCheck;
    login BD;

    procPickingList *procPickingObj;
    cadastroUser *cadastro;

};



#endif // MAINWINDOW_H
