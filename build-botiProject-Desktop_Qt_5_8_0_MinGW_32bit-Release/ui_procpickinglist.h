/********************************************************************************
** Form generated from reading UI file 'procpickinglist.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROCPICKINGLIST_H
#define UI_PROCPICKINGLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_procPickingList
{
public:
    QLineEdit *lineEdit;
    QFrame *frameStat;
    QLabel *labelLog;
    QDateTimeEdit *dateTimeEdit;
    QTableWidget *tableWidget;
    QPushButton *importPickingList;
    QPushButton *deletaPickingList;
    QLineEdit *linhaId;
    QLabel *labelQnt;
    QFrame *frameCerto;
    QLabel *labelID;
    QLineEdit *linhaQnt;
    QLineEdit *linhaInputId;
    QLabel *labelInputID;

    void setupUi(QDialog *procPickingList)
    {
        if (procPickingList->objectName().isEmpty())
            procPickingList->setObjectName(QStringLiteral("procPickingList"));
        procPickingList->setWindowModality(Qt::WindowModal);
        procPickingList->resize(1024, 600);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(procPickingList->sizePolicy().hasHeightForWidth());
        procPickingList->setSizePolicy(sizePolicy);
        procPickingList->setMinimumSize(QSize(1024, 600));
        procPickingList->setMaximumSize(QSize(1024, 600));
        QIcon icon;
        icon.addFile(QStringLiteral(":/newPrefix/barReaderIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        procPickingList->setWindowIcon(icon);
        procPickingList->setStyleSheet(QStringLiteral("background-color: rgb(239, 239, 239);"));
        procPickingList->setSizeGripEnabled(false);
        procPickingList->setModal(true);
        lineEdit = new QLineEdit(procPickingList);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setEnabled(true);
        lineEdit->setGeometry(QRect(200, 60, 781, 31));
        lineEdit->setAcceptDrops(false);
        lineEdit->setStyleSheet(QStringLiteral("font: 75 14pt \"MS Shell Dlg 2\";"));
        lineEdit->setReadOnly(true);
        frameStat = new QFrame(procPickingList);
        frameStat->setObjectName(QStringLiteral("frameStat"));
        frameStat->setGeometry(QRect(200, 530, 171, 41));
        frameStat->setAutoFillBackground(false);
        frameStat->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(212, 212, 212, 255));\n"
"background-color: rgb(222, 222, 222);"));
        frameStat->setFrameShape(QFrame::StyledPanel);
        frameStat->setFrameShadow(QFrame::Raised);
        labelLog = new QLabel(frameStat);
        labelLog->setObjectName(QStringLiteral("labelLog"));
        labelLog->setGeometry(QRect(0, 0, 171, 21));
        labelLog->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(212, 212, 212, 255));"));
        dateTimeEdit = new QDateTimeEdit(frameStat);
        dateTimeEdit->setObjectName(QStringLiteral("dateTimeEdit"));
        dateTimeEdit->setEnabled(false);
        dateTimeEdit->setGeometry(QRect(0, 20, 141, 20));
        dateTimeEdit->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(212, 212, 212, 255));"));
        dateTimeEdit->setCurrentSection(QDateTimeEdit::DaySection);
        tableWidget = new QTableWidget(procPickingList);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(200, 110, 781, 291));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        importPickingList = new QPushButton(procPickingList);
        importPickingList->setObjectName(QStringLiteral("importPickingList"));
        importPickingList->setGeometry(QRect(200, 8, 211, 45));
        importPickingList->setLayoutDirection(Qt::LeftToRight);
        importPickingList->setAutoFillBackground(false);
        importPickingList->setStyleSheet(QLatin1String("\n"
"background-image: url(:/newPrefix/excelLogo.png);"));
        deletaPickingList = new QPushButton(procPickingList);
        deletaPickingList->setObjectName(QStringLiteral("deletaPickingList"));
        deletaPickingList->setGeometry(QRect(770, 8, 211, 45));
        deletaPickingList->setLayoutDirection(Qt::LeftToRight);
        deletaPickingList->setAutoFillBackground(false);
        deletaPickingList->setStyleSheet(QStringLiteral("background-image: url(:/newPrefix/deletarButton.png);"));
        linhaId = new QLineEdit(procPickingList);
        linhaId->setObjectName(QStringLiteral("linhaId"));
        linhaId->setGeometry(QRect(670, 420, 131, 41));
        linhaId->setStyleSheet(QLatin1String("font: 75 12pt \"MS Shell Dlg 2\";\n"
"color: rgb(141, 141, 141);"));
        linhaId->setReadOnly(true);
        labelQnt = new QLabel(procPickingList);
        labelQnt->setObjectName(QStringLiteral("labelQnt"));
        labelQnt->setGeometry(QRect(810, 420, 121, 41));
        labelQnt->setStyleSheet(QLatin1String("font: 75 10pt \"MS Shell Dlg 2\";\n"
""));
        frameCerto = new QFrame(procPickingList);
        frameCerto->setObjectName(QStringLiteral("frameCerto"));
        frameCerto->setEnabled(true);
        frameCerto->setGeometry(QRect(860, 420, 161, 181));
        frameCerto->setFocusPolicy(Qt::StrongFocus);
        frameCerto->setAutoFillBackground(false);
        frameCerto->setStyleSheet(QLatin1String("background-image: url(:/newPrefix/frameCorreto.png);\n"
"border-color: rgb(88, 139, 48);\n"
"border-color: qlineargradient(spread:pad, x1:0, y1:0.0454545, x2:1, y2:0, stop:0 rgba(1, 178, 58, 255), stop:0.505682 rgba(78, 235, 61, 255), stop:0.98 rgba(22, 223, 0, 255), stop:1 rgba(0, 0, 0, 0));"));
        frameCerto->setFrameShape(QFrame::NoFrame);
        frameCerto->setFrameShadow(QFrame::Raised);
        frameCerto->setLineWidth(0);
        labelID = new QLabel(procPickingList);
        labelID->setObjectName(QStringLiteral("labelID"));
        labelID->setGeometry(QRect(550, 420, 121, 41));
        labelID->setStyleSheet(QStringLiteral("font: 75 10pt \"MS Shell Dlg 2\";"));
        linhaQnt = new QLineEdit(procPickingList);
        linhaQnt->setObjectName(QStringLiteral("linhaQnt"));
        linhaQnt->setEnabled(true);
        linhaQnt->setGeometry(QRect(940, 420, 41, 41));
        linhaQnt->setStyleSheet(QStringLiteral("font: 75 12pt \"MS Shell Dlg 2\";"));
        linhaQnt->setAlignment(Qt::AlignCenter);
        linhaQnt->setReadOnly(true);
        linhaInputId = new QLineEdit(procPickingList);
        linhaInputId->setObjectName(QStringLiteral("linhaInputId"));
        linhaInputId->setGeometry(QRect(310, 420, 231, 41));
        linhaInputId->setStyleSheet(QStringLiteral("font: 75 12pt \"MS Shell Dlg 2\";"));
        linhaInputId->setMaxLength(13);
        linhaInputId->setFrame(true);
        linhaInputId->setCursorPosition(0);
        labelInputID = new QLabel(procPickingList);
        labelInputID->setObjectName(QStringLiteral("labelInputID"));
        labelInputID->setGeometry(QRect(200, 420, 101, 41));
        labelInputID->setStyleSheet(QStringLiteral("font: 75 10pt \"MS Shell Dlg 2\";"));
        frameCerto->raise();
        lineEdit->raise();
        tableWidget->raise();
        frameStat->raise();
        importPickingList->raise();
        deletaPickingList->raise();
        linhaId->raise();
        labelQnt->raise();
        labelID->raise();
        linhaQnt->raise();
        linhaInputId->raise();
        labelInputID->raise();
        QWidget::setTabOrder(linhaInputId, linhaId);
        QWidget::setTabOrder(linhaId, linhaQnt);
        QWidget::setTabOrder(linhaQnt, lineEdit);
        QWidget::setTabOrder(lineEdit, dateTimeEdit);
        QWidget::setTabOrder(dateTimeEdit, importPickingList);
        QWidget::setTabOrder(importPickingList, deletaPickingList);
        QWidget::setTabOrder(deletaPickingList, tableWidget);
        QWidget::setTabOrder(tableWidget, frameCerto);

        retranslateUi(procPickingList);

        QMetaObject::connectSlotsByName(procPickingList);
    } // setupUi

    void retranslateUi(QDialog *procPickingList)
    {
        procPickingList->setWindowTitle(QApplication::translate("procPickingList", "Processar Picking List", Q_NULLPTR));
        lineEdit->setText(QString());
        labelLog->setText(QApplication::translate("procPickingList", "[+]Status:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        importPickingList->setToolTip(QApplication::translate("procPickingList", "<html><head/><body><p>Abrir uma &quot;Picking List&quot; com extensao .xls</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        importPickingList->setWhatsThis(QApplication::translate("procPickingList", "<html><head/><body><p>Abrir uma &quot;Picking List&quot; com extensao .xls</p></body></html>", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        importPickingList->setText(QString());
#ifndef QT_NO_TOOLTIP
        deletaPickingList->setToolTip(QApplication::translate("procPickingList", "<html><head/><body><p>Descartar uma &quot;Picking List&quot; previamente aberta.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        deletaPickingList->setWhatsThis(QApplication::translate("procPickingList", "<html><head/><body><p>Descartar uma &quot;Picking List&quot; previamente aberta.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        deletaPickingList->setText(QString());
        labelQnt->setText(QApplication::translate("procPickingList", "Quantidade restante:", Q_NULLPTR));
        labelID->setText(QApplication::translate("procPickingList", "C\303\263digo do produto:", Q_NULLPTR));
        labelInputID->setText(QApplication::translate("procPickingList", "Entrada do leitor:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class procPickingList: public Ui_procPickingList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROCPICKINGLIST_H
