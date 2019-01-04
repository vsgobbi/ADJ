#ifndef PROCPICKINGLIST_H
#define PROCPICKINGLIST_H

#include <login.h>
#include <seconddialog.h>
#include <QDialog>
#include <QAxObject>

namespace Ui {
class procPickingList;
}

class procPickingList : public QDialog
{
    Q_OBJECT

public:
    explicit procPickingList(QWidget *parent = 0);
    ~procPickingList();

    void abrirArquivo();

    void keyPressEvent (QKeyEvent *e);

    QString nomeArq;
    QString inputResultStr;
    QString inputIdProd;
    QString qntdProd;
    QString idProd;
    QStringRef inputResult;

    QString idProdProcessado;

    QString dataHistIni;
    QString dataHistProc;

    QAxObject* rows;
    // *excel; //declarar como global para deletar posteriormente

    //MainWindow *loginObj2;
    //secondDialog arquivoText;
    QFile arquivoHist;
    int conversao; //inteiro para armazenar valor de qntd restante

    float percentComissao;
    QString comissao;

    int sheetCount;  //armeza quantidae de folhas de planilhas do excell
    int rowCount; //armazena quantidade de linhas de produtos importados da planilha
    int qntLinhaProc=0; //deve ser inicializada na classe como nulo

    //linha e coluna de ID do produto na planilha
    int pontoIdX= 1; //armazena valor da posicao da linha de ID do Produto da planilha
    int pontoIdY= 0;


    //linha e coluna de Qntd de items na planilha
    int pontoQntX = 4; //armazena posicao da linha de quantidade
    int pontoQntY= 3;

public slots:

    void atualizarInput();

    void atualizarQtimer();

    void valorComissao();


private slots:

    void on_importPickingList_clicked();

    void on_deletaPickingList_clicked();

    void finalizarLista();

    void on_exportarPlanilha_clicked();

private:
    Ui::procPickingList *ui;
};

#endif // PROCPICKINGLIST_H
