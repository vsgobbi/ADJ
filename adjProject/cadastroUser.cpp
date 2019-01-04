#include "cadastroUser.h"
#include "ui_cadastroUser.h"
#include "login.h"
#include "mainwindow.h"

cadastroUser::cadastroUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cadastroUser)
{
    ui->setupUi(this);

    //Chamar função inicialmente para testar conexão com banco de dados
    //MainWindow::conectarComparar();
    //MainWindow objConec;


    //objConec.conectarSQLite();
    //objConec.checarConexao();
}
cadastroUser::~cadastroUser()
{
    delete ui;
}


void cadastroUser::on_limparButton_clicked()
{
    ui->lineNome->setText("");
    ui->lineLogin->setText("");
    ui->lineSenha->setText("");
    ui->lineNasc->setText("");
    ui->lineCidade->setText("");
    ui->lineFunc->setText("");
}

void cadastroUser::on_cadastrarButton_clicked()
{
    //login objConec;// = new login (this);
    //objConec.conectarSQLite();

    QString nome, log, senha, nasc, cidade, funcao;
    QString nulo = ("");
    nome = ui->lineNome->text();
    log = ui->lineLogin->text();
    senha = ui->lineSenha->text();
    nasc = ui->lineNasc->text();
    cidade = ui->lineCidade->text();
    funcao = ui->lineFunc->text();

    login obj;

    if ((nome == nulo)||(log == nulo)||(senha == nulo)||(nasc == nulo)||(cidade == nulo)
            ||(funcao == nulo)){
        QMessageBox::warning(this, tr ("Campos incorretos!"),
                             tr ("Por favor, preencha todos os campos corretamente."),
                             QMessageBox::Ok);

        ui->labelStatus->setText("[!]Complete os campos");
        return;
    }
    if (log==senha){
        QMessageBox::warning(this, tr ("A senha deve ser diferente de login!"),
                             tr ("Login e senha duplicados."), QMessageBox::Ok);

        ui->labelStatus->setText("[!]Insira senha diferente do login");
        return;
    }
    QSqlQuery qry;
     /*
        qry.prepare("INSERT INTO users(nome, log, senha, nasc, cidade, funcao) values"
                    "('"+nome+"','"+log+"','"+senha+"','"+nasc+"','"+cidade+"','"+funcao+"')");
     */
        qry.prepare("INSERT INTO users(nome, log, senha, nasc, cidade, funcao) values(:nome,:log,:senha,:nasc,:cidade,:funcao)");
    qry.bindValue(":nome", nome);
    qry.bindValue(":log", log);
    qry.bindValue(":senha", senha);
    qry.bindValue(":nasc", nasc);
    qry.bindValue(":cidade", cidade);
    qry.bindValue(":funcao", funcao);
    qry.exec();
    if (qry.exec()){
        qDebug () << "Insert de novo usuario feito com sucesso! " << qry.lastQuery();
        QMessageBox::information(this, tr ("Usuario cadastrado"),
                                 tr ("Bem-Vindo(a)."
                                     "\nFaca o login para utilzar o programa."),
                                 QMessageBox::Ok);
    //obj.myDB.close();
    this->close();
    } else {
        QMessageBox::warning(this, tr ("Usuario nao cadastrado"),
                             tr ("Nao foi possivel cadastrar usuario."), QMessageBox::Ok);
        qDebug () << "SQLite: " << qry.lastError();
        ui->labelStatus->setText("[!]Cadastro incompleto");
    }
}
