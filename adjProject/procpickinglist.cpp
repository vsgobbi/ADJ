#include "procpickinglist.h"
#include "ui_procpickinglist.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

procPickingList::procPickingList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::procPickingList)
{
    ui->setupUi(this);

    //atualiza Timer
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(atualizarQtimer()));
    timer->start(1000);

    ui->frameCerto->setHidden(1);
    ui->linhaId->setHidden(1);
    ui->linhaQnt->setHidden(1);
    ui->linhaInputId->setHidden(1);
    ui->labelID->setHidden(1);
    ui->labelInputID->setHidden(1);
    ui->labelQnt->setHidden(1);

    ui->labelLog->setText("[+]Pronto para importar...");
}

procPickingList::~procPickingList()
{
    delete ui;
}

void procPickingList::atualizarQtimer(){
   ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
}

void procPickingList::valorComissao() {

    QMessageBox::information(this, tr("Valor de comissão..."),
                         tr("Por favor, insira o valor de comissão do vendedor!"));

    bool ok;
    percentComissao = QInputDialog::getInt(this, tr("Comissão..."),
                                        tr("Insira o percentual de comissão:"), 35, 05, 50, 10, &ok);
    if (ok && !percentComissao==0)
        percentComissao = percentComissao*(0.01);
        comissao = QString::number(percentComissao);
}

void procPickingList::abrirArquivo()
{

    ui->labelLog->setText("[+]Importanto dados...");

    ui->tableWidget->setHidden(0);
    ui->linhaInputId->clear();
    ui->linhaInputId->insert("Insira Codigo");

    QAxObject *excel = new QAxObject( "Excel.Application", 0 );
    //QAxObject *excel = new QAxObject(EXCEL97, 0 );
    //excel->dynamicCall("SetVisible(bool)",true);
    //qDebug () << excel;
    QAxObject *workbooks = excel->querySubObject( "Workbooks" );
    //qDebug () << workbooks;
    QAxObject *workbook = workbooks->querySubObject( "Open(const QString& )", nomeArq) ;
    QAxObject *sheets = workbook->querySubObject( "Worksheets" );
    QList<QVariantList> data; //Data list from excel, each QVariantList is worksheet row
    QAxObject *cell;

     //worksheets count pega o numero correto de produtos importados na planilha
     sheetCount = sheets->dynamicCall("Count()").toInt();

     //cycle through sheets
     sheetCount = sheets->property("Count").toInt();
     for (int i=1; i<=sheetCount; i++)
      {
         //sheet pointer
         QAxObject* sheet = sheets->querySubObject("Item(int)", i);
         rows = sheet->querySubObject( "Rows" );
         rowCount = rows->dynamicCall( "Count()" ).toInt();
         //unfortunately, always returns 255, so you have to check somehow validity of cell values
         QAxObject* columns = sheet->querySubObject( "Columns" );     
         int columnCount = columns->property("Count").toInt();

         //oq essa funcao estava fazendo?
         //percorrendo outros "sheets"?
         for (int row=1; row <= rowCount; row++)
         {        
             QVariantList dataRow;
             bool isEmpty = true;
             //when all the cells of row are empty, it means that file is at end
             //(of course, it maybe not right for different excel files.
             //it's just criteria to calculate somehow row count for my file)
             for (int column=1; column <= columnCount; column++)
             {
                 //Do something usefule here
             }
             if (isEmpty) //criteria to get out of cycle
                 break;
             data.append(dataRow);
         }
     }
     //valor resultante e 1 pois saindo do loop a variavel row esta zerando!
     //row+1;
     //qDebug() << "Quantidade de produtos encontrados: " << row;
     //qDebug() << "Linhas importadas " << rowCount;
     //qDebug() << "Colunas importadas " << columnCount;
     //valor correto!
     qDebug() << "Quantidade de folhas: " << sheetCount;
     qDebug() << "Var rowsCount: " << rowCount;

    //COMO FAZER RODAR MAIS RAPIDO COM MAIS LINHAS E COLUNAS?
     //Importa todas as celulas para a GUI
    for (int i = 1; i <= 110; i++) {
        for (int j = 1; j <= 7; j++) {
            cell = excel->querySubObject("Cells(Int, Int)", i, j);
            //QString valC = cell->dynamicCall("value").toString();
            //ui->textEdit->append(valC);//-- checa o item?
            QTableWidgetItem *it = new QTableWidgetItem;
            //it->setText(valC);
            //it = new QTableWidgetItem(cell->property("Value()").toString());
            //it = new QTableWidgetItem(QString("%1,%2").arg(i).arg(j));
            // Armazena o valor de cada celula para ser
            // ordenada posteriormente com setItem().
            it->setText(cell->dynamicCall("Value").toString());
            ui->tableWidget->setRowCount(110);
            ui->tableWidget->setColumnCount(7);
            ui->tableWidget->setItem(i-4, j-1, it);
        }
    }

    ui->tableWidget->setItem(0,4,new QTableWidgetItem("VALOR"));
    ui->tableWidget->setItem(0,5,new QTableWidgetItem("VENDIDO"));

    qDebug() << "Quebrei aqui 1";

    ui->importPickingList->setDisabled(1);
    ui->linhaId->setHidden(0);
    ui->linhaQnt->setHidden(0);
    ui->linhaInputId->setHidden(0);
    ui->labelID->setHidden(0);
    ui->labelInputID->setHidden(0);
    ui->labelQnt->setHidden(0);
    ui->frameCerto->setHidden(1);

    qDebug() << "Quebrei aqui 2";

    //libera arquivo da memoria
    //excel->clear();
    //    workbooks->clear();
    //    workbook->clear();
    //    cell->clear();
    //deleta objetos
    //   excel->removeEventFilter(excel);
    //    excel->deleteLater();
    //workbooks->deleteLater();

//    QCursor meuCursor;
//    QPoint pontoCursor (450,540);
//    meuCursor.setPos(pontoCursor);
//    ui->linhaInputId->setCursor(meuCursor);

    //atualiza o produto atual a ser procurado
    QTableWidgetItem *idProduto = ui->tableWidget->item(pontoIdX,pontoIdY); //Cod de prod
    idProd = idProduto->text();
    ui->linhaId->setText(idProd);


    //atualiza o valor de conversao;
    conversao = static_cast<quint16>
            (ui->tableWidget->item(pontoQntX,pontoQntY)->data(Qt::EditRole).toUInt());
    ui->linhaQnt->setText(QString::number(conversao));
    //QTableWidgetItem *idProdutoQnt = ui->tableWidget->item(pontoQntX,pontoIdY); //atualiza quantidade de produto
    //idProd = idProdutoQnt->text();

    ui->linhaInputId->clear();
    ui->labelLog->setText("[+]Planilha importada!");
    ui->linhaInputId->insert("Insira Codigo");
    ui->linhaInputId->selectAll();
    qDebug() << "Parei aqui antes do connect!"<<idProd;


    QObject::connect(ui->exportarPlanilha, SIGNAL(pressed()),this,SLOT(on_exportarPlanilha_clicked()),
                     Qt::UniqueConnection);

    connect(ui->linhaInputId, SIGNAL(returnPressed()),this,SLOT(atualizarInput()),Qt::UniqueConnection);
    //Qt::UniqueConnection faz com que a conexao nao duplique, portanto chama o slot somente uma vez.

    }

void procPickingList::atualizarInput (){

    //espera pelo input para chamar funcao
    //a partir deste objeto conect percorre e confere a tabela

    ui->linhaInputId->selectAll();

    //QString nulo = ("");

    //atualiza os campos de codigo de barras da entrada do usuario
    inputIdProd = inputIdProd.remove( QRegExp("^[0]*") );
    inputIdProd = ui->linhaInputId->text();

    for (int i = pontoIdX; i <= 99; i++ ) {

        qDebug() << "Entrei no for!";
        qDebug() << "Indice da linha inicial: " << pontoIdX;
        qDebug() << "Meu input: " << inputIdProd.remove( QRegExp("^[0]*") );;
        ui->linhaInputId->setCursorPosition(1);
        ui->linhaInputId->selectAll();

        //atualiza linha atual e produto!
        QTableWidgetItem *idProduto = ui->tableWidget->item(pontoIdX,pontoIdY); //Cod de prod
        ui->tableWidget->selectRow(pontoIdX);
        idProd = idProduto->text();
        ui->linhaId->setText(idProd);

        //atualiza qnt
        //conversao = static_cast<quint16>
        //        (ui->tableWidget->item(pontoQntX,pontoQntY)->data(Qt::EditRole).toUInt());
        //ui->linhaQnt->setText(QString::number(conversao));

        //idProd = idProduto->text();
        //ui->linhaId->setText(idProd);

        qDebug() << "Produto atual: " << idProd; // << "status se foi processado: " << idProdProcessado;

        int j=0;

        while ((j<3) && (qntLinhaProc<=rowCount)){
            qDebug() << "Estou no while, J = " << j;
            //int j=0;
            //QTableWidgetItem *idProduto = ui->tableWidget->item(pontoQntX,pontoIdY); //Cod de prod

            qDebug() << "Meu input dentro do while: " << inputIdProd;

            if (idProd.isEmpty()) {
                qDebug() << "Linha: " << pontoIdX << " Vazia! Produto: " << idProd;
                //i=((pontoIdX)/2)+1; //comeca a percorrer a partir da segunda metade da lista
                pontoIdX=1;
                i=0;
                idProduto = ui->tableWidget->item(pontoIdX,pontoIdY);
                //finalizarLista();
                return;
            }

            /*
            //primeiro confere se produto ja foi processado!  && (idProd==idProdProcessado)
            if ((idProd.at(i)==idProdProcessado.at(i)) && (idProdProcessado.at(pontoIdX)!=1)){
                 qDebug() << "Produto ja processado: " << idProdProcessado;
                 ui->labelLog->setText("[+]Item já conferido!");

                 ui->tableWidget->selectRow(pontoIdX);

                 //comeca a percorrer a partir da segunda metade da lista
                 //pontoIdX=((count)/2)+1;
                 pontoIdX++;

                 //continue; //sair do loop while e conferir o proximo item
                }
            */

            if (inputIdProd == idProd){
                //qDebug() << "Entrei na condicao conversao verdadeira inputResultStr == idProd";
                int qntdMinima = 1;

                qDebug() << "Encontrei produto!";
                qDebug() << "Quantidade do produto encontrada: " << conversao;

                if(conversao >= qntdMinima){

                    qntdProd.toInt();
                    ui->linhaInputId->setStyleSheet("background: green;"
                                                    "font: bold 12px;");

                    ui->tableWidget->selectRow(pontoQntX);

                    conversao--;
                    QString conversaoStr = QString::number(conversao);
                    ui->linhaQnt->setText(conversaoStr); //converte para QString
                    qDebug() << "Quantidade do produto restante: " << conversao;
                    ui->tableWidget->item(pontoIdX,0)->setBackgroundColor(Qt::blue);
                    ui->labelLog->setText("[+]OK! Restam: " + conversaoStr);
                    //ui->linhaInputId->selectAll();
                    //Preenche cor de fundo somente na linha processada

                    if(conversao==0){
                        pontoQntX++;
                        //atualiza o valor de conversao;
                        conversao = static_cast<quint16>
                                (ui->tableWidget->item(pontoQntX,pontoQntY)->data(Qt::EditRole).toUInt());
                        ui->linhaQnt->setText(QString::number(conversao));
                        //atualiza quantidade de produto
                        //QTableWidgetItem *idProdutoQnt = ui->tableWidget->item(pontoQntX,pontoIdY);
                        //idProd = idProdutoQnt->text();
                        //ui->linhaId->setText(idProd);
                        ui->tableWidget->selectRow(pontoIdX);

                        QString conferido;
                        conferido += "[+]Produto ";
                        //conferido += idProduto;
                        conferido += idProd;
                        conferido += " conferido!";
                        ui->labelLog->setText(conferido);
                        //Preenche cor de fundo somente na linha processada
                        ui->tableWidget->item(pontoIdX,0)->setBackgroundColor(Qt::yellow);
                        ui->tableWidget->setItem(pontoIdX,1,new QTableWidgetItem("Conferido!"));
                        ui->frameCerto->setHidden(0);

                        qntLinhaProc++;
                        qDebug() << "Quantidade de linhas processadas: " << qntLinhaProc;
                        idProdProcessado = idProd+"OK";
                        idProd[i] == idProdProcessado[i];
                        //idProdProcessado = idProdProcessado[i];
                        qDebug() << "Produto processado: " << idProd << "na linha: " << idProd[i].toLatin1();
                        //ui->linhaInputId->selectAll();
                        //volta para o inicio e atualiza
                        //pontoIdX++;
                        //atualiza para proximo produto e sai da funcao!
                        ui->tableWidget->selectRow(pontoIdX+1);
                        idProduto = ui->tableWidget->item(pontoIdX+1,pontoIdY);
                        idProd = idProduto->text();
                        ui->linhaId->setText(idProd);
                        pontoIdX++;
                        return; //sai da funcao!
                    }
                }return;
            }

            if (inputIdProd != idProd){
                ui->frameCerto->setHidden(1);
                qDebug() << "Produto nao foi encontrado na tabela";
                ui->linhaInputId->setStyleSheet("background: red;"
                                                "font: bold 12px;");
                ui->labelLog->setText("[!]Produto não encontrado!");
                ui->linhaInputId->selectAll();
                ui->tableWidget->selectRow(pontoIdX);
                //pontoIdX=+1;

                //break; //tbm deve sair do while para que possa procurar na proxima linha
                //return; //utilizar return, break faz percorrer toda tabela sem cair no while!

                //pontoIdX++;
                //return; //quebra o while e volta a buscar novamente!
                j++;
                //pontoIdX=1;
                //return; return esta saindo do while e do for!
            }


            //Condicao de parada onde toda planilha foi processada!
            if ((inputIdProd != idProd) && (idProd.isEmpty())){
                qDebug() << "Produto nao foi encontrado na tabela!: " << inputIdProd ;
                ui->labelLog->setText("[!]Produto invalido!");
                return; //sai do while

                if   ((idProd.isEmpty()) && (qntLinhaProc == rowCount)) {
                    qDebug() << "Linha: " << pontoIdX << " Vazia! Produto: " << idProd;
                    QMessageBox msgBox;
                    msgBox.addButton(QMessageBox::Ok);
                    QMessageBox::information(this,tr("Tabela chegou ao fim!"),
                                             tr("A picking list foi conferida completamente...\n"
                                                "Para abrir outra picking list remova a atual."));
                    ui->labelLog->setText("[!]Fim da Picking list!");

                    //Preenche cor de fundo na tabela toda
                    //ui->tableWidget->setStyleSheet("background: white;"
                    //                            "font: bold 10px;");
                    //ui->tableWidget->item(0,0)->setBackgroundColor(Qt::white);

                    ui->tableWidget->setHidden(true);

                    finalizarLista(); //chega ao fim, sai do loop e salva dados do arquivo
                    return;
                    //break;
                }
            }




            idProd = idProduto->text();
            ui->linhaId->setText(idProd);
            //pontoIdX++;
        } //fim do loop while

        // return;
        //ui->tableWidget->selectRow(pontoIdX);
        //percorrerTabela = false;
        //return;

        pontoIdX++;
        qDebug() << "Posicao final no loop for: " << pontoIdX;
    } //fim do loop foor
}

void procPickingList::finalizarLista() {

            QString path = QDir::currentPath();
            qDebug () << "Caminho atual: " << path;

            QString meuArquivoText = ("arqHistorico.txt");
            path.append(meuArquivoText);
            QFile meuArquivoHist (meuArquivoText);

            meuArquivoHist.open(QIODevice::WriteOnly | QIODevice::Append);

            //cria output ao arquivo de texto historico

            //QString ArqHist = "arqHistorico.txt";
                //arqHist.open(QIODevice::WriteOnly | QIODevice::Append);
                if (!meuArquivoHist.isWritable()){
                    QMessageBox::warning(this,tr("Erro ao abrir arquivo"),
                                         tr("O arquivo de historico nao pode ser aberto\n"
                                            "Cheque se o arquivo realmente existe."));
                    return;
                }

                QTextStream saida (&meuArquivoHist);
                QDateTime salvaData =  QDateTime::currentDateTime();
                dataHistProc = salvaData.toString("dd-MM-yyyy::hh:mm:ss");
                qDebug () << "Data de termino: " << dataHistProc;
               // QDate dataHist = QDate::fromString(dataHist,'YYYY-MM-DD');


                saida << "\n\nArquivo: " << nomeArq << " Planilha importanda em:  " << dataHistIni.toLatin1()  <<
                 " Planilha processada em: " << dataHistProc.toLatin1() << " Quantidade de items processados: " << qntLinhaProc;
                        //Calcular diferenca de tempo ao abrir arquivo e processa-lo todo!

                QMessageBox msgBox;
                msgBox.addButton(QMessageBox::Ok);
                QMessageBox::information(this,tr("Dados salvos no histórico!"),
                                         tr("A lista foi salva no arquivo de históricos com sucesso...\n"
                                            "Para abrir outra picking list remova a atual."));
                ui->labelLog->setText("[+]Planilha Finalizada!");
                //Apaga e libera geral da memoria!
                nomeArq.clear();
                meuArquivoHist.close();
                nomeArq.detach();
                nomeArq.clear();

                ui->frameCerto->setVisible(1);
                ui->tableWidget->clear();
                ui->tableWidget->clearContents();
                ui->linhaInputId->clear();
                ui->linhaId->setHidden(1);
                ui->linhaQnt->setHidden(1);
                ui->linhaInputId->setHidden(1);
                ui->labelID->setHidden(1);
                ui->labelInputID->setHidden(1);
                ui->labelQnt->setHidden(1);
                ui->labelInputID->setVisible(0);
}

void procPickingList::on_importPickingList_clicked() {

    ui->labelLog->setText("[+]Abrindo arquivo...");

    QString excelFilter = tr("Planilha excel (*.xls *.xlsx)");
    nomeArq = QFileDialog::getOpenFileName(this,
                                           tr("Abrir 'Picking List'"),
                                           "/",excelFilter);
                                           //"/",tr("Arquivo excel (*.xls *.xlsx )"));                                           );

    QFile arquivo (nomeArq);
    if (!arquivo.open(QIODevice::ReadOnly)) {
        QMessageBox::information(this, tr("Impossivel abrir arquivo"),
                                 tr("Abra um tipo de arquivo suportavel"));
        return;
    }
    if (nomeArq.isEmpty()) {
        QMessageBox::warning(this, tr("Arquivo invalido"),
                             tr("Abra um tipo de arquivo suportavel"));
        ui->labelLog->setText("[!]Arquivo invalido");
        return;
    } else
        ui->labelLog->setText("[+]Abrindo arquivo...");
        ui->lineEdit->setHidden(0);
        ui->lineEdit->setAlignment(Qt::AlignCenter);
        ui->lineEdit->setText("Arquivo aberto: " + nomeArq);
        ui->labelLog->setText("[+]Abrindo arquivo...");
        QDateTime salvaData =  QDateTime::currentDateTime();
        dataHistIni = salvaData.toString("dd-MM-yyyy::hh:mm:ss");
        qDebug () << "Data ao abrir arquivo" << dataHistIni;


        procPickingList::abrirArquivo();

        //arquivo.deleteLater();
        //arquivo.close();
}

void procPickingList::on_deletaPickingList_clicked() {
    //verificar se items e objetos estao realmente sendo deletados da memoria!
    nomeArq.detach();
    nomeArq.clear();
    ui->tableWidget->clear();
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(0);
    ui->tableWidget->close();
    //QTableWidget::~QTableWidget();
    qntLinhaProc=0;
    sheetCount=0;
    //idProd.clear();

    if (nomeArq.isNull()){
        ui->tableWidget->setRowCount(0);
        ui->tableWidget->setColumnCount(0);
        ui->tableWidget->setHidden(1);
        ui->lineEdit->setHidden(1);
        ui->tableWidget->setHidden(1);
        ui->linhaId->setHidden(1);
        ui->linhaInputId->setHidden(1);
        ui->linhaQnt->setHidden(1);
        ui->labelInputID->setHidden(1);
        ui->labelID->setHidden(1);
        ui->labelQnt->setHidden(1);
        ui->frameCerto->setHidden(1);
        ui->importPickingList->setDisabled(0);

        //libera arquivo da memoria //como liberar variavel da outra funcao?
        //book->clear();
        //cell->clear();

        ui->labelLog->setText("[!]Arquivo descartado");
        ui->lineEdit->setText("");

        QMessageBox::warning(this, tr("Arquivo descartado"),
                             tr("O arquivo foi descartado com sucesso, "
                                "pronto para importar outro novamente!"));

    } else
        QMessageBox::warning(this, tr("Arquivo ainda aberto"),
                             tr("O arquivo nao foi descartado"));
    return;
}


void procPickingList::keyPressEvent(QKeyEvent *e) {
    if(e->key() == Qt::Key_Escape) {
        QDialog::showMinimized();
    } else {/* minimiza */}
}

void procPickingList::on_exportarPlanilha_clicked()
{
    //Receber INPUT de comissão do vendedor primeiramente...
    valorComissao();

    QMessageBox msgBox(
                QMessageBox::Question,
                trUtf8("O valor de comissão é"),
                comissao,
                QMessageBox::Yes | QMessageBox::No);

    msgBox.setButtonText(QMessageBox::Yes, trUtf8("Sim"));
    msgBox.setButtonText(QMessageBox::No, trUtf8("Não"));

    if (msgBox.exec() == QMessageBox::No) {
        valorComissao();
    }

    //Abrir caixa de diáogo para salvar arquivo como .ods ou .xls
    nomeArq = QFileDialog::getSaveFileName(
                this,tr("Salvar arquivo como ..."),".",tr(" (*.ods *.xls);;Todos arquivos(*)"));
    QByteArray nomeArqUtf8= nomeArq.toUtf8();
    nomeArq = nomeArqUtf8.data();

    if (nomeArq.isNull() || (nomeArq.isEmpty())){
        QMessageBox::warning(this, tr("Erro"),
                             tr("Arquivo nao pode ser salvo..."));
        ui->labelLog->setText("[!]Arquivo nao salvo");
        return;
    }
    if (nomeArq==""){
        QMessageBox::warning(this, tr("Erro, Arquivo nulo"),
                             tr("Nenhum arquivo foi aberto para ser salvo..."));
        ui->labelLog->setText("[!]Arquivo nao salvo");
        return;
    } else

        QMessageBox::information(this, tr ("Arquivo salvo"),
                                 tr ("Arquivo foi salvo com sucesso..."), QMessageBox::Ok);
    ui->labelLog->setText("[+]Arquivo salvo!");

    QFile f(nomeArq);
    QTextStream ts( &f );
    QStringList strList;
    QDataStream data ( &f ) ;

    QTableWidgetItem *valorVendido = ui->tableWidget->item(pontoIdX, 4);
    QString itemConferido;
    QString strDescProduto;
    QString itemValorVendido;
    int countQntVendida = 0;

    strList.clear();
    pontoIdX=1;
    //abre arquivo para leitura e escrita, truncate indica que é cortado antes de abrir, tudo feito anteriormente
    //é perdido, QIODevice::Text faz o "append" de "\n" no final de cada linha
    // Desabilitado: | QFile::Truncate | QIODevice::Text
    if( f.open( QIODevice::ReadWrite | QIODevice::Text) )
    {

        qDebug() << "Travei aqui 4";
        strList.clear();
        pontoIdX=1;
        for (int i=pontoIdX; i<90; i++){

            strList << ui->tableWidget->item(i,4)->data(Qt::ImCurrentSelection).toString();

            QTableWidgetItem *cellConferido = ui->tableWidget->item(pontoIdX, 1);
            QTableWidgetItem *descProduto = ui->tableWidget->item(pontoIdX, 2);
            cellConferido->text();
            strDescProduto = descProduto->text();
            itemConferido = cellConferido->text();
            if ((itemConferido!="Conferido!") && (strDescProduto!="")) {
                //cellConferido->setText(itemVendido);
                cellConferido = ui->tableWidget->item(pontoIdX,4);
                //ui->tableWidget->setItem(pontoIdX,5, cellConferido);
                //armazena a celular de valor do item
                //QTableWidgetItem* item = ui->tableWidget->item(pontoIdX-7,4);
                //item = new QTableWidgetItem();
                //item->text();
                //qDebug() << "Valor do item vendido: " << item->text();
                //qDebug() << "Valor do item vendido: " << item << ui->tableWidget->item(pontoIdX,4)->text();
                // item->setText(cellVendido.toString());

                valorVendido = ui->tableWidget->item(pontoIdX,4);
                //ui->tableWidget->setItem(pontoIdX,5,valorVendido);

                itemValorVendido = valorVendido->text();
                QTableWidgetItem *cellVendido = ui->tableWidget->item(pontoIdX, 4);
                cellVendido = new QTableWidgetItem;
                cellVendido->text();
                ui->tableWidget->setItem(pontoIdX, 5, cellVendido);
                cellVendido->setText(itemValorVendido);
                //strList << ui->tableWidget->item(pontoIdX,5)->text();
                countQntVendida++;
            }
            else if ((itemConferido=="Conferido!") && (strDescProduto!="")) {

                    ui->tableWidget->setItem(pontoIdX,5,new QTableWidgetItem(""));
            }

            pontoIdX++;

            //ts << strList.join(';') + "\n";
        }
        //qDebug() << "Valor textStream strList: " << strList;

        QString strCountQntVendida = QString::number(countQntVendida);
        qDebug() << "Quantidade de items vendidos: " << strCountQntVendida;

        //Calculo total de items vendidos:
        ui->tableWidget->setItem(92,4,new QTableWidgetItem("TOTAL VENDIDO"));
        ui->tableWidget->setItem(92,5,new QTableWidgetItem("=SUM(F3:F91)"));
        ui->tableWidget->setItem(93,4,new QTableWidgetItem("CUSTO 33%"));
        ui->tableWidget->setItem(93,5,new QTableWidgetItem("=(F100*0.33)"));

        //Calculo de Comissão:
        ui->tableWidget->setItem(94,3,new QTableWidgetItem("COMISSAO "));
        QTableWidgetItem *pCell = ui->tableWidget->item(94, 4);
        pCell = new QTableWidgetItem;
        pCell->setText(comissao);
        ui->tableWidget->setItem(94, 4, pCell);
        ui->tableWidget->setItem(94,5,new QTableWidgetItem("=(F100*E102)"));

        //Calculo Qntd de Items vendidos e Ticket Medio
        ui->tableWidget->setItem(95,4,new QTableWidgetItem("QNTD ITEMS VENDIDOS"));
        QTableWidgetItem *qntVendida = ui->tableWidget->item(95, 5);
        qntVendida = new QTableWidgetItem;

        qntVendida->setText(strCountQntVendida);
        ui->tableWidget->setItem(95, 5, qntVendida);

        ui->tableWidget->setItem(96,4,new QTableWidgetItem("TICKET MEDIO"));
        QTableWidgetItem *ticketMedio = ui->tableWidget->item(96, 4);
        ticketMedio = new QTableWidgetItem;

        QString strTicketMedio = "=ROUND(F100)/"+strCountQntVendida;
        ticketMedio->setText(strTicketMedio);
        ui->tableWidget->setItem(96, 5, ticketMedio);

        //Funcionando, porém armazena " " em espaco extra e não armazena célula colorida

        //strList << "\" " + ui->tableWidget->item( i, j )->text()+"\" ";
        //strList << (ui->tableWidget->item(i,j)).toString();

        //strList << ui->tableWidget->data(ui->tableWidget->index(i,j)).toString();

        }
        strList.clear();
        //coluna = i linha = j
        for (int i=0; i<ui->tableWidget->columnCount(); ++i)
        {

            /*
                            * Travando com funcao horizontalHeaderItem pois cria header?
                            strList <<
                                       "\" " +
                                       ui->tableWidget->horizontalHeaderItem(i)->data(Qt::DisplayRole).toString() +
                                       "\" ";


                            //Testados: Background, BackgroundColorRole, DisplayRole
                            strList <<
                                       "" +
                                       ui->tableWidget->item(i,0)->data(Qt::ImCurrentSelection).toString() +
                                       "\" ";

                            Tentativa de salvar sem espaco!
                            */

            strList << ui->tableWidget->item(i,0)->data(Qt::ImCurrentSelection).toString();

            //strList.append('utf8');

            //mimeData->setData("text/csv", strList);
            //mimeData->setData(strList);
            //strList << ts.append(strList.toStdList());
            ts.autoDetectUnicode();

            //ts << mimeData;
            //ui->tableWidget->setItem(100,4,new QTableWidgetItem("TOTAL"));
            //ui->tableWidget->setItem(100,5,new QTableWidgetItem("=SUM(F3:F99)"));
            ts << strList.join("\t") + "\n";
        }
        qDebug() << "Lista sendo salva 1: " << strList;


        for (int j=0; j<ui->tableWidget->rowCount(); ++j){
            strList.clear();

            for( int i = 0; i < ui->tableWidget->columnCount(); ++i ) {
                //strList = strList.replace(i,QRegExp("'\\s+"));
                QTableWidgetItem* item = ui->tableWidget->item(j,i);        //Load items

                //Se a celular estiver vazia preenche com zeros
                if (!item || item->text().isEmpty())
                {
                    ui->tableWidget->setItem(j,i,new QTableWidgetItem(""));//IF there is nothing write 0
                }

                //Esta adicionando espaco antes de iniciar celula!
                //strList << "\" " + ui->tableWidget->item(j,i)->text() + "\" ";
                strList << ui->tableWidget->item(j,i)->text();
                //1 teste = somente "\"" no final
                //2 teste = somente "\" " no final
                //3 teste = somente "\ " no final
                //4 teste = somente "" no final -- mudando a coluna de items
                //5 teste = somente "" no INICIO e FINAL -- OK! Porem no calc separar somente por Semmicolon!
                //6 teste = sem nada! armazenando ' antes do valor do item!
                //7 teste = append \r\t
            }

            ts << strList.join(";") + "\n";
        }
        qDebug() << "Lista sendo salva 2: " << strList;
        qDebug() << "Travei aqui 3 ";

        //Habilita permissão para editar arquivo salvo...
        extern Q_CORE_EXPORT int qt_ntfs_permission_lookup;
        qt_ntfs_permission_lookup--;


        //Tentativa de habilitar a copia de toda tabela no clipboard
        //QClipboard *clipboard = QApplication::clipboard();
        //strList << ui->tableWidget->item(i,4)->data(Qt::ImCurrentSelection).toString();
        //clipboard->setText(ts);
        QList<QTableWidgetItem *> selected(ui->tableWidget->selectedItems());
        QTableWidgetItem *item;
        QByteArray mByteArray;
        mByteArray.clear();

        foreach(item, selected)
           {
              mByteArray.append(item->text());
              mByteArray.append("\t");
           }

           mByteArray.append("\r\n");
           qDebug() << "mByteArray " << mByteArray.size();


        f.close(); qDebug() << "To travando aqui!";


}
