#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    //conectarSQLite();

    ui->labelLog->setText("[!]Informe login e senha");
    //myDB.removeDatabase(QSqlDatabase::defaultConnection);
    //stringLogin = log;


    qDebug () << "Inicializando a variavel BDChecado como: " << BDChecado;
    //checarConexao();

}

login::~login()
{
    delete ui;
}

void login::on_limparButton_clicked()
{
    ui->loginTxt->setText("");
    ui->senhaTxt->setText("");
}

void login::on_verificarLog_clicked(){

    //if (!myDB.isOpen()) {
    qDebug () << "BDChecado ao clicar verificar log: " << BDChecado;
    qDebug () << "Status myBD: " << myDB.isOpen();
   if ((myDB.isOpen()!=false) && (BDChecado==false)){
   // if(BDChecado==false){
        qDebug () << "Sem conexao";
        ui->labelLog->setText("[!]Sem conexao");
        ui->labelStatus->setText("[!]BD nao conectado");
        return;
    }
    if (conectarUsuario(testar)==1){
        //stringLogin =log;
        qDebug() << "NOVO USUARIO LOGADO: " << log;
        //MainWindow obj;
        //obj.loginUser=true;
        loginUser=true;
        this->close();
        if (this->close()==1){
            testar=1;
            //obj.loginUser=true;
        }
    } else {
            ui->labelStatus->setText("[+]Banco de dados conectado");
            //stringLogin = log;
        }
}


bool login::conectarUsuario(int testar){
    int count = 0;
    QString senha;
    //aceita input do usuario
    log = ui->loginTxt->text();
    senha = ui->senhaTxt->text();

    /*
    QSqlQuery querylite(myDB);
    QString sql;
    sql = "SELECT count (log) from users WHERE log = 'log' AND senha= 'senha'";
    sql = sql + ui->loginTxt->text() + "'";
    sql = sql + " AND senha = '";
    sql = sql + ui->senhaTxt->text() + "'";

    if (querylite.exec(sql)) //Executed the statement
             {
                 if (querylite.value(0).toInt() > 0) //If the return is bigger that 0
                 {
                     //User and pass was found
                     qDebug () << "Usuario : " << sql + ui->loginTxt->text() << " encontrado!" << querylite.value(0);
                 }
                 else
                 {
                     //No access
                     qDebug () << "Sem acesso a tabela";
                     qDebug () << "Select do usuario" << log << "em 'users' falhou..." << querylite.lastError();
                 }
    }
    */
    QSqlQuery qry;
    QString sql;

    //qry.exec("select * from users where log = (:log) and senha= (:senha)");
    qry.prepare("select * from users where log = (:log) and senha= (:senha)");
    qry.bindValue(":log", log);
    qry.bindValue(":senha", senha);
    qry.exec();
    //qry.exec("select * from users");
    while (qry.next()){
        QString indiceEncontrado = qry.value(0).toString(); //retorna o valor do indice
       // qDebug () << "Query resultante: "  << sql.append(qry.value(0).toString()); //retornando resultado maluco
        qDebug () << "Query resultante: "  << indiceEncontrado;
        if (qry.value(0).toInt() > 0){ //significa que existe pelo menos 1 indice contendo os campos inseridos!
            qDebug () << "USUARIO E SENHA VALIDADO!";
            count = 3;
            qDebug () << "Count : " << count;
        }
    }
    //qDebug () << "Query Value: "  << qry.value(0);
    //if(qry.exec("select * from users where log='"+log+"' and senha='"+senha+"'"))

    //qry.prepare("select * from users where log = (:log) and senha= (:senha)");
    qry.prepare("select count (log) from users where log = (:log) and senha= (:senha)");
    qry.bindValue(":log", log);
    qry.bindValue(":senha", senha);

    //if (qry.exec()) {
    if (qry.value(0).toInt() > 0){
        qDebug () << "USUARIO E SENHA VALIDADO!";
        qDebug () << "Query Value: "  << qry.value(0);

        if (log == ":log" && senha == ":senha"){

            qDebug () << "Usuario : " << log << " encontrado!";
            //count ++;
            count = 3;
            qDebug () << "Count : " << count;

       } else {
            qDebug () << "Select do usuario" << log << "em 'users' falhou..." << qry.lastError();
            count=0;
        }
            //  int count = 0;
        while (qry.next()){
            //count ++;
            sql.append( qry.value ( 0 ).toString() );
            qDebug () << "Query feita: " << sql;
            qDebug () << "Count : " << count;
        }

    }
        if (count == 3) {
            ui->labelLog->setText("[+]Login e senha validos!");
            QMessageBox::information(this, tr("Bem-vindo(a)"),("Login feito com sucesso"));
            boolCheck = true;
            //stringLogin = log;
            //emit stringLogin;
            //return boolCheck;
            loginUser = true;
            qDebug () << "Login validado! " << "Count: " << count;
            testar = 1;
            qDebug () << "Status loginUser: " << loginUser;
            count++;
            return true;
        }
        if ((log == senha && log !=NULL) || (count>1)) {
        //if (count>1) {
            ui->labelLog->setText("[!]Login e senha duplicados!");

            return false;
        } if (count<1) {
            ui->labelLog->setText("[!]Login e senha invalidos!");

            return false;
        } //return false;
     return testar;
}

void login::conectarSQLite() {

    if ((myDB.isOpen()) && BDChecado==true) {
       //qDebug () << "Banco de dados já criado e conectado!";
       qDebug () << "Banco de dados já criado e conectado!";
       ui->labelStatus->setText("[+]Banco de dados conectado");
       return;
       // if (!myDB.isOpen() || (BDChecado==false)) {☺
    } else if (!myDB.isOpen()){
        myDB = QSqlDatabase::addDatabase("QSQLITE");
        myDB.setDatabaseName(caminhoBD);
        myDB.open();
        QFileInfo checkMeuArquivoBD (caminhoBD);

        if (checkMeuArquivoBD.isFile()){
            if(myDB.isOpen()) {
            //qDebug () << "Abrindo nova conexao com SQLite";
            qDebug () << "Novo Banco de Dados conectado";
            ui->labelStatus->setText("[+]Novo BD conectado");
            BDChecado=1;

            QSqlQuery tblQry;
            tblQry.exec("CREATE TABLE IF NOT EXISTS users"
                        "(id integer primary key, nome varchar(50), "
                        "log varchar(20), senha varchar(20), nasc varchar(20), "
                        "cidade varchar(30), funcao varchar(30))");

            if(tblQry.exec()) {
                qDebug () << "Nova tabela 'users' criada...";
                BDChecado = true;
            } else {
                qDebug () << "Tabela 'users' nao foi criada..." << tblQry.lastError();
            }
            //Faz insert teste de administrador
            QSqlQuery qry;
            qry.prepare("INSERT INTO users (nome,log,senha,nasc,cidade,funcao)"
                        " VALUES (:nome,:log,:senha,:nasc,:cidade,:funcao)");
            qry.bindValue(":nome", 'vitao');
            qry.bindValue(":log", 'admin');
            qry.bindValue(":senha", 'senha');
            qry.bindValue(":nasc", '26101990');
            qry.bindValue(":cidade", 'Adamantina');
            qry.bindValue(":funcao", 'Dev');
            qry.exec();
            if(qry.exec()){
                qDebug () << "Nova tabela 'users' pre definida criada...";
            } else {
                qDebug () << "Insert pre definido 'users' falhou..." << qry.lastError();
            }
            }
        }
    } else {
        ui->labelStatus->setText("[!]Banco de dados nao conectado");
        //BDChecado == false;
        return;
    }
}

bool login::checarConexao(){
    qDebug () << "Status ao chechar conexao com banco: " << BDChecado;
    if(myDB.isOpen() && (BDChecado==true)) {
        qDebug () << "Banco de dados OKAY";
        ui->labelStatus->setText("[+]Banco de dados conectado");
        BDChecado = true;
        return true;
    }
    qDebug () << "Status bool BDChecado: " << BDChecado;
    if (BDChecado==false) {
        qDebug () << "Banco de dados NAO OKAY";
        ui->labelStatus->setText("[!]Banco de dados nao conectado");
        //BDChecado = 0;
        qDebug () << "Banco checado? " << BDChecado;
        return false;
    }
    return BDChecado;
}

void login::passaUsuario(QString &stringLog){
    MainWindow obj;
    //obj.vaiLogo;
    obj.vaiLogo = log;
    stringLog = obj.vaiLogo;
    QString tent = log;
    qDebug() << "Variavel: " << stringLog;
    //qDebug() << "Variavel tent = " << tent;
    QString msg;
    msg += "[+]Bem vindo ";
    msg += stringLog;
    msg += " !";
    ui->labelStatus->setText(msg);
    return;
}

void login::fecharConexao () {

    BDChecado = false;
    qDebug()<< "Fechando conexao...";
    //myDB.removeDatabase(QSqlDatabase::defaultConnection);
    //myDB.close();
    delete ui;
}
