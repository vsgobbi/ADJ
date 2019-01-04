/********************************************************************************
** Form generated from reading UI file 'cadastroUser.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CADASTROUSER_H
#define UI_CADASTROUSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_cadastroUser
{
public:
    QPushButton *cadastrarButton;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineNome;
    QLineEdit *lineLogin;
    QLineEdit *lineSenha;
    QLineEdit *lineNasc;
    QLineEdit *lineCidade;
    QLabel *label_6;
    QFrame *gridFrame;
    QLabel *labelStatus;
    QPushButton *limparButton;
    QLabel *label_7;
    QLineEdit *lineFunc;
    QLabel *label;

    void setupUi(QDialog *cadastroUser)
    {
        if (cadastroUser->objectName().isEmpty())
            cadastroUser->setObjectName(QStringLiteral("cadastroUser"));
        cadastroUser->setWindowModality(Qt::WindowModal);
        cadastroUser->setEnabled(true);
        cadastroUser->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cadastroUser->sizePolicy().hasHeightForWidth());
        cadastroUser->setSizePolicy(sizePolicy);
        cadastroUser->setMinimumSize(QSize(400, 300));
        cadastroUser->setMaximumSize(QSize(400, 300));
        cadastroUser->setStyleSheet(QStringLiteral(""));
        cadastroUser->setModal(true);
        cadastrarButton = new QPushButton(cadastroUser);
        cadastrarButton->setObjectName(QStringLiteral("cadastrarButton"));
        cadastrarButton->setGeometry(QRect(150, 250, 91, 27));
        cadastrarButton->setStyleSheet(QStringLiteral("font: 75 9pt \"MS Shell Dlg 2\";"));
        label_2 = new QLabel(cadastroUser);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 70, 51, 21));
        label_3 = new QLabel(cadastroUser);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 100, 51, 21));
        label_4 = new QLabel(cadastroUser);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 130, 101, 21));
        label_5 = new QLabel(cadastroUser);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 160, 51, 21));
        lineNome = new QLineEdit(cadastroUser);
        lineNome->setObjectName(QStringLiteral("lineNome"));
        lineNome->setGeometry(QRect(140, 40, 113, 20));
        lineLogin = new QLineEdit(cadastroUser);
        lineLogin->setObjectName(QStringLiteral("lineLogin"));
        lineLogin->setGeometry(QRect(140, 70, 113, 20));
        lineSenha = new QLineEdit(cadastroUser);
        lineSenha->setObjectName(QStringLiteral("lineSenha"));
        lineSenha->setGeometry(QRect(140, 100, 113, 20));
        lineSenha->setEchoMode(QLineEdit::Password);
        lineNasc = new QLineEdit(cadastroUser);
        lineNasc->setObjectName(QStringLiteral("lineNasc"));
        lineNasc->setGeometry(QRect(140, 130, 113, 20));
        lineCidade = new QLineEdit(cadastroUser);
        lineCidade->setObjectName(QStringLiteral("lineCidade"));
        lineCidade->setGeometry(QRect(140, 160, 113, 20));
        label_6 = new QLabel(cadastroUser);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(100, 10, 211, 21));
        gridFrame = new QFrame(cadastroUser);
        gridFrame->setObjectName(QStringLiteral("gridFrame"));
        gridFrame->setGeometry(QRect(0, 0, 401, 301));
        gridFrame->setStyleSheet(QStringLiteral("background-image: url(:/newPrefix/icons/backCadastro.jpg);"));
        label_6->raise();
        labelStatus = new QLabel(cadastroUser);
        labelStatus->setObjectName(QStringLiteral("labelStatus"));
        labelStatus->setEnabled(true);
        labelStatus->setGeometry(QRect(110, 270, 361, 31));
        limparButton = new QPushButton(cadastroUser);
        limparButton->setObjectName(QStringLiteral("limparButton"));
        limparButton->setGeometry(QRect(140, 220, 111, 25));
        label_7 = new QLabel(cadastroUser);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 190, 111, 21));
        lineFunc = new QLineEdit(cadastroUser);
        lineFunc->setObjectName(QStringLiteral("lineFunc"));
        lineFunc->setGeometry(QRect(140, 190, 113, 20));
        label = new QLabel(cadastroUser);
        label->setObjectName(QStringLiteral("label"));
        label->setEnabled(true);
        label->setGeometry(QRect(20, 40, 41, 16));
        gridFrame->raise();
        cadastrarButton->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        label_5->raise();
        lineNome->raise();
        lineLogin->raise();
        lineSenha->raise();
        lineNasc->raise();
        lineCidade->raise();
        label_6->raise();
        labelStatus->raise();
        limparButton->raise();
        label_7->raise();
        lineFunc->raise();
        label->raise();
        QWidget::setTabOrder(lineNome, lineLogin);
        QWidget::setTabOrder(lineLogin, lineSenha);
        QWidget::setTabOrder(lineSenha, lineNasc);
        QWidget::setTabOrder(lineNasc, lineCidade);
        QWidget::setTabOrder(lineCidade, lineFunc);
        QWidget::setTabOrder(lineFunc, limparButton);
        QWidget::setTabOrder(limparButton, cadastrarButton);

        retranslateUi(cadastroUser);

        QMetaObject::connectSlotsByName(cadastroUser);
    } // setupUi

    void retranslateUi(QDialog *cadastroUser)
    {
        cadastroUser->setWindowTitle(QApplication::translate("cadastroUser", "Cadastrar Usuario", Q_NULLPTR));
        cadastrarButton->setText(QApplication::translate("cadastroUser", "Cadastrar", Q_NULLPTR));
        label_2->setText(QApplication::translate("cadastroUser", "Login:", Q_NULLPTR));
        label_3->setText(QApplication::translate("cadastroUser", "Senha:", Q_NULLPTR));
        label_4->setText(QApplication::translate("cadastroUser", "Data nascimento:", Q_NULLPTR));
        label_5->setText(QApplication::translate("cadastroUser", "Cidade:", Q_NULLPTR));
        lineSenha->setText(QString());
        lineCidade->setText(QString());
        label_6->setText(QApplication::translate("cadastroUser", "Preencha todos os campos abaixo:", Q_NULLPTR));
        labelStatus->setText(QApplication::translate("cadastroUser", "[+]Banco de dados:", Q_NULLPTR));
        limparButton->setText(QApplication::translate("cadastroUser", "Limpar campos", Q_NULLPTR));
        label_7->setText(QApplication::translate("cadastroUser", "Cargo ou Func\303\243o:", Q_NULLPTR));
        lineFunc->setText(QString());
        label->setText(QApplication::translate("cadastroUser", "Nome:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class cadastroUser: public Ui_cadastroUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CADASTROUSER_H
