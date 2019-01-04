/********************************************************************************
** Form generated from reading UI file 'seconddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECONDDIALOG_H
#define UI_SECONDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_secondDialog
{
public:
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QTextEdit *textEdit;
    QLabel *label;
    QLineEdit *lineEdit;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton;
    QPushButton *abrirText;

    void setupUi(QDialog *secondDialog)
    {
        if (secondDialog->objectName().isEmpty())
            secondDialog->setObjectName(QStringLiteral("secondDialog"));
        secondDialog->resize(483, 399);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(secondDialog->sizePolicy().hasHeightForWidth());
        secondDialog->setSizePolicy(sizePolicy);
        secondDialog->setStyleSheet(QLatin1String("selection-background-color: rgb(212, 212, 212);\n"
""));
        secondDialog->setModal(true);
        gridLayout_3 = new QGridLayout(secondDialog);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setHorizontalSpacing(0);
        gridLayout->setVerticalSpacing(2);
        gridLayout->setContentsMargins(-1, 1, -1, 0);
        textEdit = new QTextEdit(secondDialog);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        sizePolicy.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy);
        textEdit->setMinimumSize(QSize(0, 300));
        textEdit->setLayoutDirection(Qt::LeftToRight);
        textEdit->setMidLineWidth(1);
        textEdit->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        textEdit->setAutoFormatting(QTextEdit::AutoBulletList);

        gridLayout->addWidget(textEdit, 0, 0, 1, 1);

        label = new QLabel(secondDialog);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(0, 14));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        lineEdit = new QLineEdit(secondDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(lineEdit, 2, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        pushButton = new QPushButton(secondDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(pushButton, 0, 0, 1, 1);

        abrirText = new QPushButton(secondDialog);
        abrirText->setObjectName(QStringLiteral("abrirText"));
        sizePolicy1.setHeightForWidth(abrirText->sizePolicy().hasHeightForWidth());
        abrirText->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(abrirText, 0, 1, 1, 1);


        gridLayout->addLayout(gridLayout_2, 3, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(secondDialog);

        QMetaObject::connectSlotsByName(secondDialog);
    } // setupUi

    void retranslateUi(QDialog *secondDialog)
    {
        secondDialog->setWindowTitle(QApplication::translate("secondDialog", "Procurar items...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        textEdit->setToolTip(QApplication::translate("secondDialog", "<html><head/><body><p><br/></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("secondDialog", "<html><head/><body><p><span style=\" font-size:9pt; font-weight:600;\">Procurar:</span></p></body></html>", Q_NULLPTR));
        pushButton->setText(QApplication::translate("secondDialog", "Ir!", Q_NULLPTR));
        abrirText->setText(QApplication::translate("secondDialog", "Importar arquivo", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class secondDialog: public Ui_secondDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECONDDIALOG_H
