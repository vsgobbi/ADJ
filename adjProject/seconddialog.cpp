#include "seconddialog.h"
#include "ui_seconddialog.h"
#include "mainwindow.h"

secondDialog::secondDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secondDialog)
{
    ui->setupUi(this);
}

//Contrutor de user interface, limpa espaco para memória
secondDialog::~secondDialog()
{
    delete ui;
}

//Funcao para procurar items...
void secondDialog::on_pushButton_clicked()
{
    ui->textEdit->moveCursor(QTextCursor::Start,QTextCursor::MoveAnchor);
    QString palavra;
    palavra = ui->lineEdit->text(); //recebe input do usuario
    if (!palavra.isNull()){
        ui->textEdit->find(palavra, QTextDocument::FindWholeWords);
        QString palavraSensitive = palavra;
        ui->textEdit->find(palavraSensitive, QTextDocument::FindCaseSensitively);
        }
    //palavra.remove();
    //palavra.detach();
    //palavra.clear();
    //ui->textEdit->clear(); limpa toda tela!

    QTextCursor newTextCursor = ui->textEdit->textCursor();
    newTextCursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor, 1);
    qDebug () << "Palavra a ser procurada: " << palavra;
    //return palavra.clear();
}

void secondDialog::on_abrirText_clicked()
{

//            arquivoText = QFileDialog::getOpenFileName(this,
//                                               tr("Abrir historico"),
//                                               "/",tr("Arquivo tipo (*arqHist.cnh.txt)"));
//            arquivoText.toAscii();
            QString path = QDir::currentPath();
            qDebug () << "Caminho atual: " << path;
            arquivoText = ("arqHistorico.txt");
            path.append(arquivoText);
            QFile meuArquivoHist (arquivoText);
                   // (":/historico.txt");
            meuArquivoHist.open(QIODevice::ReadOnly | QIODevice::Text);
            //QByteArray rawdata = meuArquivoHist.readAll();
            //meuArquivoHist.open(stderr, QIODevice::ReadOnly);
            //QByteArray dadosArq = meuArquivoHist.readAll();
            //qDebug () << "Conteudo do arquivo STDEER: "<< dadosArq;
            //qDebug () << "Conteudo do arquivo: "<< rawdata;

                //QTextStream in(&meuArquivoHist);
                //QString linhas = in.readAll();
                //qDebug () << linhas.toLatin1();
                //qDebug () << dadosArq.toUpper();


            if (arquivoText.isEmpty()) {
                QMessageBox::warning(this, tr("Arquivo invalido"),
                                     tr("Arquivo nulo ou inexistente...\n"
                                        "Verifique se um historico foi salvo anteriormente."));
                this->close();
                return;
            }
            if (meuArquivoHist.isReadable()){
                qDebug () << "Arquivo encontrado";
                QTextStream arquivo (&meuArquivoHist);
                QString line = arquivo.readAll();
                //meuArquivoHist.close();
                ui->textEdit->setPlainText(line);
                ui->textEdit->setReadOnly(1);
                QTextCursor textCursor = ui->textEdit->textCursor();
                textCursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor, 1);
            }
}
