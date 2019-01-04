#include "mainwindow.h"
#include "login.h"
#include "cadastroUser.h"
#include "ui_mainwindow.h"
#include "seconddialog.h"
#include "procpickinglist.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);

    //atualizarTimer
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(atualizarQtimer()));
    timer->start(1000);

    //checa conexao com banco de dados
    conectarComparar();
    //inicializa sem chamar classe login, porém esta dando segmentation fault
    //loginObj->loginUser = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::atualizarQtimer(){
   ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
}

//Testar conexão com o banco inicialmente
void MainWindow::conectarComparar(){
    login objConec;// = new login (this);
    //intBDChecado = objConec.intBDChecado;
    //objConec.checarConexao();
    if (objConec.myDB.isOpen() && (objConec.BDChecado==true)) {
        ui->labelStatus->setText("[+]Banco de dados conectado");
        return;
    }
    //objConec.checarConexao(objConec.BDChecado);
    if((objConec.BDChecado==false) && (!objConec.myDB.isOpen())){
        ui->labelStatus->setText("[!]BD nao conectado");
        objConec.conectarSQLite();
        if(objConec.BDChecado==true){
            ui->labelStatus->setText("[+]Banco de dados conectado");
            return;
        }
    }
}

void MainWindow::on_actionAbrir_triggered() {
    //login objConec;
    qDebug () << "Status do login: " << loginObj->loginUser;
    //qDebug () << "Status do login: " << objConec.loginUser;
    if (loginObj->loginUser==true) {
        QMessageBox::information(this, tr("Bem-Vindo(a)!"),
                             tr("Pronto para importar planilha Alacioli!"
                                "\n"));
        ui->labelStatus->setText("[+]Usuario conectado");
                procPickingObj= new procPickingList (this);
                procPickingObj->show();
    }
    else
        QMessageBox::warning(this, tr("Usuario nao conectado"),
                            tr("Faca o login primeiramente para utilizar o programa."));
        ui->labelStatus->setText("[!]Usuario nao conectado");
        //procPickingObj->close();
        return;

   /* else
        QMessageBox::warning(this, tr("Usuario nao conectado"),
                            tr("Faca o login primeiramente para utilizar o programa."));
        ui->labelStatus->setText("[!]Usuario nao conectado");
        procPickingObj->close();
   */
}


//Cria mensagem para salvar arquivo
void MainWindow::mensagemSalvar () {
    procPickingList obj;
    if (obj.nomeArq.isEmpty()) {
        QMessageBox::StandardButton msg;
        msg = QMessageBox::warning(this, tr("Arquivo nao salvo..."),
                                   tr("Deseja salvar o arquivo?"),
                                   QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);

        if(msg == QMessageBox::Save) {
            salvarComo();
            QMessageBox::warning(this, tr("Arquivo salvo"),
                                 tr("Saindo do programa..."));
            exit (1);
        } if (msg == QMessageBox::Discard) {
            QMessageBox::warning(this, tr("Arquivo nao salvo"),
                                 tr("Saindo do programa..."));
            exit (1);
        } if (msg == QMessageBox::Cancel) {
            return ;
        }
    }
}

//CRIAR SISTEMA DE SEGURANCA AO SAIR
void MainWindow::on_actionSair_triggered() {


    if (QMessageBox::Yes == QMessageBox::question(this, "Sair do programa",
                                                  "Tem certeza que deseja sair?",
                                                  QMessageBox::Yes|QMessageBox::No)) {
        mensagemSalvar();
    } else {
        return;}
}

//Mensagem sobre utilizacao do software
void MainWindow::on_actionSobre_triggered()
{
    QMessageBox::about(this, tr("Sobre"),
                       tr("Sistema criado para controle de items da empresa CP Harmonia, "
                          "\npara a utilizacao de 'backoffices' e estoquistas ao conferir itens de pedidos."
                          "\nO sistema possui banco de dados atualizavel de acordo com a necessidade do usuario."
                          "\nCriado somente para uso comercial."
                          "\n\nVersao release V1.0."
                          "\npor Vitor Sgobbi (2017)"
                          "\nContato: vitorsgobbi@hotmail.com"));
}



void MainWindow::on_actionProcurar_items_triggered()
{
    //abrir segunda janela de dialogo como ponteiro (evita erro de stack memory)
    second = new secondDialog(this);
    second->show();
    ui->labelStatus->setText("[+]Consultar historico");
}


void MainWindow::salvarComo() {
     procPickingList obj;

    //QString nomeArquivo
    obj.nomeArq = QFileDialog::getSaveFileName(
                this,tr("Salvar arquivo como ..."),".",tr(" (*.txt *.xls);;Todos arquivos(*)"));
    QByteArray file= obj.nomeArq.toUtf8();
    file = file.data();

    if (obj.nomeArq.isNull()) {
        QMessageBox::warning(this, tr("Erro"),
                             tr("Arquivo nao salvo..."));
        ui->labelStatus->setText("[!]Arquivo nao salvo");
        return;
    }
    QMessageBox::information(this, tr ("Arquivo salvo"),
                             tr ("Arquivo salvo com sucesso"), QMessageBox::Ok);
    ui->labelStatus->setText("[+]O arquivo foi salvo");
}

void MainWindow::on_actionSalvarComo_triggered() {
    procPickingList obj;
    if (!obj.nomeArq.isEmpty()) {
        return salvarComo();
    } else {
        QMessageBox::warning(this, tr("Erro"),
                             tr("Nenhum arquivo aberto..."));
        ui->labelStatus->setText("[!]Arquivo nao aberto");
        return;
    }
}

void MainWindow::on_actionOpc_es_triggered()
{
    QMessageBox msgBox;
    msgBox.addButton(QMessageBox::Yes);
    //QMessageBox::information(this,"Opcoes", "Opcoes de interface");
    QMessageBox::information(this, tr("Informacoes"),
                       tr("Sistema criado para controle de items da empresa CP Harmonia, "
                          "\nPara utilizar o sistema primeiramente o usuario deve fazer seu login."
                          "\nEm caso de erros ou falhas de funcionalidades,"
                          "\ninformar o problema por telefone ou e-mail."                       
                          "\n\npor Vitor Sgobbi (2017)."
                          "\nContato: vitorsgobbi@hotmail.com, Celular: (12)997507663"));
}

void MainWindow::on_loginButton_clicked()
{
    login obj; //cria o objeto obj da classe login para fazer referencia.
    //obj.conectarSQLite();
    //loginObj->conectarSQLite(); deu runtime error
    loginObj = new login(this);
    loginObj->show();
   /*
    if(obj.checarConexao(obj.intBDChecado)==true){
        ui->labelStatus->setText("[+]Banco de Dados conectado");
        loginObj = new login(this);
        loginObj->show();
        //testar2 = 2;

    } else {
        ui->labelStatus->setText("[!]BD nao conectado");
        testar2 = 0;
        loginUser = false;
        return;
    }
    */
    //login obj;
    //Passa login como string para validar a classe procpickinglist
    //qDebug() << "Login a ser passado: " << loginObj->log;
    //vaiLogo = loginObj->log;
    //qDebug() << vaiLogo;
    //obj.passaUsuario(vaiLogo);
}

//Invoca tela de cadastro
void MainWindow::on_commandLinkButton_clicked()
{
    cadastro = new cadastroUser(this);
    cadastro->show();
}

void MainWindow::on_logoutButton_clicked()
{
    login *myDB = new login();
    //myDB->close(); //neste caso se nao houvesse funcao da classe login.
    //myDB->stringLogin.detach();
    //myDB->log.detach();
    myDB->fecharConexao(); //chama a funcao fecharConexao da classe login, membro é fecharConxao
    QMessageBox::warning(this, tr("Usuario desconectado..."), tr("Voce nao esta mais conectado!"));
    ui->labelStatus->setText("[!]Usuario desconectado");
    //testar2 = 0;
    //loginObj->loginUser = false;
    loginObj->loginUser = false;
   // objConec.loginUser = false;
}

void MainWindow::on_actionDocumentos_triggered()
{
//    QString arquivoDocumento = QFileDialog::getOpenFileName(this,
//                                       tr("Abrir documento"),
//                                       ":/",tr("especificacoesDeSoftwareDocumentacao.txt"));
//    arquivoDocumento.toAscii();
    QString arquivoDocumento = ("especificacoesDeSoftwareDocumentacao.txt");
    QFile meuArquivoDoc (arquivoDocumento);
           // (":/especificacoesDeSoftwareDocumentacao.txt");
    meuArquivoDoc.open(QIODevice::ReadOnly);

    if (arquivoDocumento.isNull()) {
        QMessageBox::warning(this, tr("Arquivo invalido"),
                             tr("Arquivo nulo ou inexistente...\n"
                                "Verifique se os arquivos de documentos existem."));
        return;
    }
    QTextStream arquivo (&meuArquivoDoc);
    QString line = arquivo.readAll();
    meuArquivoDoc.close();

    QDialog *documento = new QDialog (this);
    QTextEdit *textEdit = new QTextEdit;
    QHBoxLayout *layout = new QHBoxLayout;
    documento->setWindowTitle("Texto Documentacao");
    documento->setLayout(layout);
    documento->setFixedSize(800,600);
    documento->show();
    layout->addWidget(textEdit);
    textEdit->setReadOnly(1);
    textEdit->setPlainText(line);
    ui->labelStatus->setText("[+]Documentos");
    QTextCursor textCursor = textEdit->textCursor();
    textCursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor, 1);
    arquivoDocumento.detach();
}

//verifica arquivos de banco de dados
void MainWindow::on_actionBanco_de_dados_triggered()
{
    QFile meuArquivoBD ("C:/SQLite/users.sqlite");
    QString caminhoArquivoBD ("C:/SQLite/users.sqlite");
    //meuArquivoBD.open(QIODevice::ReadWrite);

    /*
    //Confere primeiramente se o arquivo users.sqlite já existe
    //Senao, cria novo arquivo users.sqlite, ja com a extensao correta
    */
    QFileInfo meuArquivoBDInfo (meuArquivoBD);
    if(!meuArquivoBDInfo.isReadable()) {
        qDebug () << "Arquivo users.sqlite não encontrado!";
        if(!meuArquivoBDInfo.exists()) {
            meuArquivoBD.close();
            if(!meuArquivoBD.open(QIODevice::ReadWrite)){
                qDebug () << "Arquivo users.sqlite não pode ser criado...";
          } else {
            QTextStream init(&meuArquivoBD);
            // init << ""; //Nao inserir texto pois conflita com driver SQLite3
            qDebug () << "users.sqlite inicializado com sucesso.";
            meuArquivoBD.close();
            //meuArquivoBD.remove();
                }
            }
    }

    QString dirArquivoSQLite ("C:/SQLite/sqlite3.exe");
    QFile arquivoSQL(dirArquivoSQLite);

    //verifica se arquivo 'SQLite3.exe' existe como caminho para o arquivo em QString
    QFileInfo checkFile (dirArquivoSQLite);

    if ((!checkFile.exists()) && (!checkFile.isExecutable())){
        qDebug () << "Arquivo 'SQLite3.exe' nao existe ou nao pode ser executado...!";
        ui->labelStatus->setText("[!]Arquivo SQLite3 inexistentes");
    }

    if ((!meuArquivoBDInfo.isReadable()) || (!checkFile.exists())){
        int arquivoSQLopen;
        //login * BDChecado = false;
        arquivoSQLopen = (QDesktopServices::openUrl(QUrl("file:///C:/SQLite/sqlite3.exe", QUrl::TolerantMode)));
        arquivoSQLopen = (QDesktopServices::openUrl(QUrl("file:///C:/SQLite/users.sqlite", QUrl::TolerantMode)));
        ui->labelStatus->setText("[!]Arquivos BD inexistentes");
        qDebug () << "Console SQLite3 aberto..." << arquivoSQLopen;
        QMessageBox::warning(this, tr("Caminho nao encontrado!"),
                             tr("Os arquivos necessários de banco de dados nao foram encontrados,"
                                " por favor verifique se os arquivos 'users.sqlite' e 'C:/SQLite/sqlite3.exe'"
                                " foram instalados corretamente"
                                " ou instale-os novamente."));
        return;
    } else {
        ui->labelStatus->setText("[+]Arquivos BD verificados");
        QMessageBox::information(this, tr("Arquivos encontrados!"),
                             tr("Os arquivos necessários de banco de dados foram verificados com sucesso,"
                                " por favor, faca o login ou novo cadastro para continuar"
                                " utilizando o programa, se erros persistirem,"
                                " contate o desenvolvedor."));
    }

    login obj;

    if((obj.checarConexao() == true) && (meuArquivoBD.isReadable())){
        ui->labelStatus->setText("[+]BD conectado");
        QMessageBox::information(this, tr("Caminho encontrado!"),
                                 tr("O arquivo de banco de dados foi encontrado.\n"
                                    "Caso a conexao ainda nao esteja funcionando verifique"
                                    " o arquivo 'C:/SQLite/users.sqlite' ou contate"
                                    " o administrador."));
    }

    //abre o arquivo sql3.exe (executavel)
    //QDesktopServices::openUrl(QUrl("file:///C:/SQLite/sqlite3.exe",QUrl::TolerantMode));
    meuArquivoBD.close();
    //meuArquivoBD.remove();
}

//Verifica o arquivo de texto de historico
void MainWindow::on_actionHist_rico_triggered()
{
    QString path = QDir::currentPath();
    qDebug () << "Caminho atual: " << path;
    QString ArqHist = "arqHistorico.txt";
    QFile meuArqHist ("arqHistorico.txt");
    meuArqHist.open(QIODevice::ReadOnly | QIODevice::Text);
    //if(!meuArqHist.isOpen()){
    if(ArqHist.isNull()) {
        ui->labelStatus->setText("[!]Historico inexistente");
        QMessageBox::warning(this, tr("Caminho nao encontrado!"),
                             tr("O arquivo de historico nao foi encontrado,"
                                " por favor verifique se o arquivo esta na pasta do programa"
                                " ou instale novamente."));
    }
    //if(meuArqHist.isReadable()){
    if(!ArqHist.isNull()){
        ui->labelStatus->setText("[+]Historico OK");
        //QDesktopServices::openUrl(QUrl("file://arqHistorico.txt",QUrl::TolerantMode));
        QDesktopServices::openUrl(QUrl::fromLocalFile(ArqHist));
        QMessageBox::information(this, tr("Caminho encontrado!"),
                                 tr("O arquivo de historico foi encontrado.\n"
                                    "O historico de processamento pode ser consultado."));
    }
}
