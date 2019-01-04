/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QPushButton *verificarLog;
    QLabel *labelStatus;
    QLabel *labelLog;
    QPushButton *limparButton;
    QFrame *gridFrame;
    QGridLayout *back;
    QLineEdit *loginTxt;
    QLabel *label_3;
    QLabel *label_2;
    QLineEdit *senhaTxt;

    void setupUi(QDialog *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QStringLiteral("login"));
        login->setWindowModality(Qt::WindowModal);
        login->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(login->sizePolicy().hasHeightForWidth());
        login->setSizePolicy(sizePolicy);
        login->setMinimumSize(QSize(400, 300));
        login->setMaximumSize(QSize(400, 300));
        login->setWindowOpacity(20);
        login->setModal(true);
        verificarLog = new QPushButton(login);
        verificarLog->setObjectName(QStringLiteral("verificarLog"));
        verificarLog->setGeometry(QRect(150, 160, 101, 31));
        labelStatus = new QLabel(login);
        labelStatus->setObjectName(QStringLiteral("labelStatus"));
        labelStatus->setGeometry(QRect(130, 250, 191, 31));
        labelLog = new QLabel(login);
        labelLog->setObjectName(QStringLiteral("labelLog"));
        labelLog->setGeometry(QRect(130, 230, 191, 21));
        limparButton = new QPushButton(login);
        limparButton->setObjectName(QStringLiteral("limparButton"));
        limparButton->setGeometry(QRect(150, 200, 101, 23));
        gridFrame = new QFrame(login);
        gridFrame->setObjectName(QStringLiteral("gridFrame"));
        gridFrame->setGeometry(QRect(0, 0, 400, 300));
        gridFrame->setStyleSheet(QStringLiteral("background-image: url(:/newPrefix/icons/backlogin.jpg); "));
        back = new QGridLayout(gridFrame);
        back->setObjectName(QStringLiteral("back"));
        loginTxt = new QLineEdit(login);
        loginTxt->setObjectName(QStringLiteral("loginTxt"));
        loginTxt->setGeometry(QRect(140, 75, 129, 20));
        label_3 = new QLabel(login);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(91, 75, 41, 16));
        label_2 = new QLabel(login);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(91, 109, 41, 16));
        senhaTxt = new QLineEdit(login);
        senhaTxt->setObjectName(QStringLiteral("senhaTxt"));
        senhaTxt->setGeometry(QRect(140, 106, 129, 20));
        senhaTxt->setEchoMode(QLineEdit::Password);
        gridFrame->raise();
        verificarLog->raise();
        labelStatus->raise();
        labelLog->raise();
        limparButton->raise();
        label_3->raise();
        loginTxt->raise();
        label_2->raise();
        senhaTxt->raise();
        QWidget::setTabOrder(loginTxt, senhaTxt);
        QWidget::setTabOrder(senhaTxt, verificarLog);
        QWidget::setTabOrder(verificarLog, limparButton);

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QDialog *login)
    {
        login->setWindowTitle(QApplication::translate("login", "Login", Q_NULLPTR));
        verificarLog->setText(QApplication::translate("login", "Verificar", Q_NULLPTR));
        labelStatus->setText(QString());
        labelLog->setText(QApplication::translate("login", "[+]Status:", Q_NULLPTR));
        limparButton->setText(QApplication::translate("login", "Limpar dados", Q_NULLPTR));
        label_3->setText(QApplication::translate("login", "Login:", Q_NULLPTR));
        label_2->setText(QApplication::translate("login", "Senha:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
