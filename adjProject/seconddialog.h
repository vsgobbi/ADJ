#ifndef SECONDDIALOG_H
#define SECONDDIALOG_H

#include <QDialog>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>

namespace Ui {
class secondDialog;
}

class secondDialog : public QDialog
{
    Q_OBJECT

public:
    explicit secondDialog(QWidget *parent = 0);
    ~secondDialog();

private slots:
    void on_pushButton_clicked();

    void on_abrirText_clicked();

public slots:

public:

    QString arquivoText;

private:
    Ui::secondDialog *ui;

};

#endif // SECONDDIALOG_H
