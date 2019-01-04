/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbrir;
    QAction *actionSalvarComo;
    QAction *actionImprimir;
    QAction *actionSair;
    QAction *actionDocumentos;
    QAction *actionBanco_de_dados;
    QAction *actionSobre;
    QAction *actionProcurar_items;
    QAction *actionHist_rico;
    QAction *actionOpc_es;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QFrame *verticalFrame;
    QGridLayout *gridLayout;
    QPushButton *loginButton;
    QCommandLinkButton *commandLinkButton;
    QPushButton *logoutButton;
    QSpacerItem *verticalSpacer;
    QFrame *frameStat;
    QGridLayout *gridLayout_3;
    QLabel *labelStatus;
    QDateTimeEdit *dateTimeEdit;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QMenu *menuOpcoes;
    QMenu *menuAjuda;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::WindowModal);
        MainWindow->resize(838, 768);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setMaximumSize(QSize(1024, 768));
        MainWindow->setSizeIncrement(QSize(0, 0));
        QPalette palette;
        QBrush brush(QColor(204, 203, 201, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(91, 91, 91, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::HighlightedText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush1);
        MainWindow->setPalette(palette);
        QIcon icon;
        icon.addFile(QStringLiteral(":/newPrefix/icons/anel_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QLatin1String("border-color: rgb(91, 91, 91);\n"
"\n"
"font: 75 10pt \"MS Shell Dlg 2\";\n"
"\n"
"gridline-color: rgb(91, 91, 91);\n"
"\n"
"selection-color: rgb(91, 91, 91);\n"
"\n"
"border-color: rgb(91, 91, 91);"));
        actionAbrir = new QAction(MainWindow);
        actionAbrir->setObjectName(QStringLiteral("actionAbrir"));
        actionAbrir->setEnabled(true);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/newPrefix/icons/abrir_preto.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbrir->setIcon(icon1);
        actionAbrir->setVisible(true);
        actionSalvarComo = new QAction(MainWindow);
        actionSalvarComo->setObjectName(QStringLiteral("actionSalvarComo"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/newPrefix/icons/saveIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSalvarComo->setIcon(icon2);
        actionImprimir = new QAction(MainWindow);
        actionImprimir->setObjectName(QStringLiteral("actionImprimir"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/newPrefix/icons/printIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionImprimir->setIcon(icon3);
        actionSair = new QAction(MainWindow);
        actionSair->setObjectName(QStringLiteral("actionSair"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/newPrefix/icons/sair.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSair->setIcon(icon4);
        actionDocumentos = new QAction(MainWindow);
        actionDocumentos->setObjectName(QStringLiteral("actionDocumentos"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/newPrefix/icons/docIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDocumentos->setIcon(icon5);
        actionBanco_de_dados = new QAction(MainWindow);
        actionBanco_de_dados->setObjectName(QStringLiteral("actionBanco_de_dados"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/newPrefix/icons/dbOptionIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBanco_de_dados->setIcon(icon6);
        actionSobre = new QAction(MainWindow);
        actionSobre->setObjectName(QStringLiteral("actionSobre"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/newPrefix/icons/sobreIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSobre->setIcon(icon7);
        actionProcurar_items = new QAction(MainWindow);
        actionProcurar_items->setObjectName(QStringLiteral("actionProcurar_items"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/newPrefix/icons/searchIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionProcurar_items->setIcon(icon8);
        actionHist_rico = new QAction(MainWindow);
        actionHist_rico->setObjectName(QStringLiteral("actionHist_rico"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/newPrefix/icons/histIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHist_rico->setIcon(icon9);
        actionOpc_es = new QAction(MainWindow);
        actionOpc_es->setObjectName(QStringLiteral("actionOpc_es"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/newPrefix/icons/optionIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpc_es->setIcon(icon10);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy1);
        centralWidget->setMinimumSize(QSize(0, 0));
        centralWidget->setMaximumSize(QSize(1024, 768));
        centralWidget->setSizeIncrement(QSize(2, 2));
        centralWidget->setAutoFillBackground(false);
        centralWidget->setStyleSheet(QLatin1String("background-image: url(:/newPrefix/icons/background1200.jpg); background-position: center;\n"
"\n"
"background-color: rgb(91, 91, 91);\n"
"\n"
"color: rgb(91, 91, 91);"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalFrame = new QFrame(centralWidget);
        verticalFrame->setObjectName(QStringLiteral("verticalFrame"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(verticalFrame->sizePolicy().hasHeightForWidth());
        verticalFrame->setSizePolicy(sizePolicy2);
        verticalFrame->setMinimumSize(QSize(0, 0));
        QPalette palette1;
        QBrush brush2(QColor(163, 163, 163, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Active, QPalette::HighlightedText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush1);
        verticalFrame->setPalette(palette1);
        verticalFrame->setLayoutDirection(Qt::LeftToRight);
        verticalFrame->setAutoFillBackground(false);
        verticalFrame->setStyleSheet(QLatin1String("background-color: rgb(163, 163, 163);\n"
"color: rgb(163, 163, 163);\n"
""));
        verticalFrame->setInputMethodHints(Qt::ImhDialableCharactersOnly|Qt::ImhLatinOnly|Qt::ImhLowercaseOnly|Qt::ImhUppercaseOnly|Qt::ImhUrlCharactersOnly);
        verticalFrame->setFrameShape(QFrame::NoFrame);
        verticalFrame->setFrameShadow(QFrame::Sunken);
        verticalFrame->setLineWidth(0);
        gridLayout = new QGridLayout(verticalFrame);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setVerticalSpacing(6);
        gridLayout->setContentsMargins(-1, 8, -1, -1);
        loginButton = new QPushButton(verticalFrame);
        loginButton->setObjectName(QStringLiteral("loginButton"));
        loginButton->setEnabled(true);
        sizePolicy.setHeightForWidth(loginButton->sizePolicy().hasHeightForWidth());
        loginButton->setSizePolicy(sizePolicy);
        loginButton->setMinimumSize(QSize(0, 40));
        QFont font;
        font.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(9);
        font.setStyleStrategy(QFont::PreferAntialias);
        loginButton->setFont(font);
        loginButton->setAutoFillBackground(false);
        loginButton->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(3, 3, 3, 255), stop:0.380682 rgba(164, 163, 151, 255), stop:0.767045 rgba(97, 93, 63, 255), stop:1 rgba(64, 0, 0, 255));\n"
"font: 75 12pt \"MS Shell Dlg 2\";"));

        gridLayout->addWidget(loginButton, 2, 1, 1, 1);

        commandLinkButton = new QCommandLinkButton(verticalFrame);
        commandLinkButton->setObjectName(QStringLiteral("commandLinkButton"));
        commandLinkButton->setEnabled(true);
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(commandLinkButton->sizePolicy().hasHeightForWidth());
        commandLinkButton->setSizePolicy(sizePolicy3);
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        QLinearGradient gradient(0, 0, 0, 1);
        gradient.setSpread(QGradient::PadSpread);
        gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient.setColorAt(0, QColor(3, 3, 3, 255));
        gradient.setColorAt(0.380682, QColor(164, 163, 151, 255));
        gradient.setColorAt(0.767045, QColor(97, 93, 63, 255));
        gradient.setColorAt(1, QColor(64, 0, 0, 255));
        QBrush brush3(gradient);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        QLinearGradient gradient1(0, 0, 0, 1);
        gradient1.setSpread(QGradient::PadSpread);
        gradient1.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient1.setColorAt(0, QColor(3, 3, 3, 255));
        gradient1.setColorAt(0.380682, QColor(164, 163, 151, 255));
        gradient1.setColorAt(0.767045, QColor(97, 93, 63, 255));
        gradient1.setColorAt(1, QColor(64, 0, 0, 255));
        QBrush brush4(gradient1);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush4);
        QLinearGradient gradient2(0, 0, 0, 1);
        gradient2.setSpread(QGradient::PadSpread);
        gradient2.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient2.setColorAt(0, QColor(3, 3, 3, 255));
        gradient2.setColorAt(0.380682, QColor(164, 163, 151, 255));
        gradient2.setColorAt(0.767045, QColor(97, 93, 63, 255));
        gradient2.setColorAt(1, QColor(64, 0, 0, 255));
        QBrush brush5(gradient2);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush5);
        palette2.setBrush(QPalette::Active, QPalette::HighlightedText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        QLinearGradient gradient3(0, 0, 0, 1);
        gradient3.setSpread(QGradient::PadSpread);
        gradient3.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient3.setColorAt(0, QColor(3, 3, 3, 255));
        gradient3.setColorAt(0.380682, QColor(164, 163, 151, 255));
        gradient3.setColorAt(0.767045, QColor(97, 93, 63, 255));
        gradient3.setColorAt(1, QColor(64, 0, 0, 255));
        QBrush brush6(gradient3);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        QLinearGradient gradient4(0, 0, 0, 1);
        gradient4.setSpread(QGradient::PadSpread);
        gradient4.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient4.setColorAt(0, QColor(3, 3, 3, 255));
        gradient4.setColorAt(0.380682, QColor(164, 163, 151, 255));
        gradient4.setColorAt(0.767045, QColor(97, 93, 63, 255));
        gradient4.setColorAt(1, QColor(64, 0, 0, 255));
        QBrush brush7(gradient4);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush7);
        QLinearGradient gradient5(0, 0, 0, 1);
        gradient5.setSpread(QGradient::PadSpread);
        gradient5.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient5.setColorAt(0, QColor(3, 3, 3, 255));
        gradient5.setColorAt(0.380682, QColor(164, 163, 151, 255));
        gradient5.setColorAt(0.767045, QColor(97, 93, 63, 255));
        gradient5.setColorAt(1, QColor(64, 0, 0, 255));
        QBrush brush8(gradient5);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush8);
        palette2.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        QLinearGradient gradient6(0, 0, 0, 1);
        gradient6.setSpread(QGradient::PadSpread);
        gradient6.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient6.setColorAt(0, QColor(3, 3, 3, 255));
        gradient6.setColorAt(0.380682, QColor(164, 163, 151, 255));
        gradient6.setColorAt(0.767045, QColor(97, 93, 63, 255));
        gradient6.setColorAt(1, QColor(64, 0, 0, 255));
        QBrush brush9(gradient6);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        QLinearGradient gradient7(0, 0, 0, 1);
        gradient7.setSpread(QGradient::PadSpread);
        gradient7.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient7.setColorAt(0, QColor(3, 3, 3, 255));
        gradient7.setColorAt(0.380682, QColor(164, 163, 151, 255));
        gradient7.setColorAt(0.767045, QColor(97, 93, 63, 255));
        gradient7.setColorAt(1, QColor(64, 0, 0, 255));
        QBrush brush10(gradient7);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush10);
        QLinearGradient gradient8(0, 0, 0, 1);
        gradient8.setSpread(QGradient::PadSpread);
        gradient8.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient8.setColorAt(0, QColor(3, 3, 3, 255));
        gradient8.setColorAt(0.380682, QColor(164, 163, 151, 255));
        gradient8.setColorAt(0.767045, QColor(97, 93, 63, 255));
        gradient8.setColorAt(1, QColor(64, 0, 0, 255));
        QBrush brush11(gradient8);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush11);
        palette2.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush1);
        commandLinkButton->setPalette(palette2);
        commandLinkButton->setFocusPolicy(Qt::NoFocus);
        commandLinkButton->setAcceptDrops(false);
        commandLinkButton->setAutoFillBackground(false);
        commandLinkButton->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(3, 3, 3, 255), stop:0.380682 rgba(164, 163, 151, 255), stop:0.767045 rgba(97, 93, 63, 255), stop:1 rgba(64, 0, 0, 255));"));
        commandLinkButton->setInputMethodHints(Qt::ImhNone);
        commandLinkButton->setIconSize(QSize(25, 25));
        commandLinkButton->setCheckable(false);
        commandLinkButton->setAutoDefault(false);

        gridLayout->addWidget(commandLinkButton, 0, 1, 1, 1);

        logoutButton = new QPushButton(verticalFrame);
        logoutButton->setObjectName(QStringLiteral("logoutButton"));
        sizePolicy.setHeightForWidth(logoutButton->sizePolicy().hasHeightForWidth());
        logoutButton->setSizePolicy(sizePolicy);
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette3.setBrush(QPalette::Active, QPalette::HighlightedText, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush1);
        logoutButton->setPalette(palette3);
        logoutButton->setAcceptDrops(false);
        logoutButton->setAutoFillBackground(false);
        logoutButton->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(logoutButton, 4, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 220, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 5, 1, 1, 1);

        frameStat = new QFrame(verticalFrame);
        frameStat->setObjectName(QStringLiteral("frameStat"));
        frameStat->setEnabled(true);
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(frameStat->sizePolicy().hasHeightForWidth());
        frameStat->setSizePolicy(sizePolicy4);
        frameStat->setMinimumSize(QSize(200, 0));
        frameStat->setBaseSize(QSize(0, 0));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette4.setBrush(QPalette::Active, QPalette::HighlightedText, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush1);
        frameStat->setPalette(palette4);
        QFont font1;
        font1.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(9);
        frameStat->setFont(font1);
        frameStat->setLayoutDirection(Qt::LeftToRight);
        frameStat->setAutoFillBackground(false);
        frameStat->setStyleSheet(QStringLiteral(""));
        frameStat->setFrameShape(QFrame::StyledPanel);
        frameStat->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frameStat);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        labelStatus = new QLabel(frameStat);
        labelStatus->setObjectName(QStringLiteral("labelStatus"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(labelStatus->sizePolicy().hasHeightForWidth());
        labelStatus->setSizePolicy(sizePolicy5);
        labelStatus->setBaseSize(QSize(0, 0));
        QFont font2;
        font2.setFamily(QStringLiteral("Trebuchet MS"));
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(9);
        labelStatus->setFont(font2);
        labelStatus->setStyleSheet(QStringLiteral("font: 75 10pt \"Trebuchet MS\";"));

        gridLayout_3->addWidget(labelStatus, 1, 0, 1, 1);

        dateTimeEdit = new QDateTimeEdit(frameStat);
        dateTimeEdit->setObjectName(QStringLiteral("dateTimeEdit"));
        dateTimeEdit->setEnabled(false);
        sizePolicy3.setHeightForWidth(dateTimeEdit->sizePolicy().hasHeightForWidth());
        dateTimeEdit->setSizePolicy(sizePolicy3);
        dateTimeEdit->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(212, 212, 212, 255));"));
        dateTimeEdit->setCurrentSection(QDateTimeEdit::DaySection);

        gridLayout_3->addWidget(dateTimeEdit, 2, 0, 1, 1);


        gridLayout->addWidget(frameStat, 6, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 1, 1, 1, 1);


        horizontalLayout->addWidget(verticalFrame);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 838, 22));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QStringLiteral("menuMenu"));
        menuOpcoes = new QMenu(menuBar);
        menuOpcoes->setObjectName(QStringLiteral("menuOpcoes"));
        menuAjuda = new QMenu(menuBar);
        menuAjuda->setObjectName(QStringLiteral("menuAjuda"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuMenu->menuAction());
        menuBar->addAction(menuOpcoes->menuAction());
        menuBar->addAction(menuAjuda->menuAction());
        menuMenu->addAction(actionAbrir);
        menuMenu->addSeparator();
        menuMenu->addAction(actionProcurar_items);
        menuMenu->addSeparator();
        menuMenu->addAction(actionSalvarComo);
        menuMenu->addSeparator();
        menuMenu->addAction(actionImprimir);
        menuMenu->addSeparator();
        menuMenu->addAction(actionSair);
        menuMenu->addSeparator();
        menuOpcoes->addAction(actionBanco_de_dados);
        menuOpcoes->addSeparator();
        menuOpcoes->addAction(actionHist_rico);
        menuOpcoes->addSeparator();
        menuOpcoes->addAction(actionOpc_es);
        menuOpcoes->addSeparator();
        menuAjuda->addAction(actionDocumentos);
        menuAjuda->addSeparator();
        menuAjuda->addAction(actionSobre);
        menuAjuda->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "CP Harmonia", Q_NULLPTR));
        actionAbrir->setText(QApplication::translate("MainWindow", "Abrir", Q_NULLPTR));
        actionAbrir->setShortcut(QApplication::translate("MainWindow", "Ctrl+A", Q_NULLPTR));
        actionSalvarComo->setText(QApplication::translate("MainWindow", "Salvar como...", Q_NULLPTR));
        actionSalvarComo->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", Q_NULLPTR));
        actionImprimir->setText(QApplication::translate("MainWindow", "Imprimir", Q_NULLPTR));
        actionImprimir->setShortcut(QApplication::translate("MainWindow", "Ctrl+P", Q_NULLPTR));
        actionSair->setText(QApplication::translate("MainWindow", "Sair", Q_NULLPTR));
        actionSair->setShortcut(QApplication::translate("MainWindow", "Ctrl+E", Q_NULLPTR));
        actionDocumentos->setText(QApplication::translate("MainWindow", "Documentos", Q_NULLPTR));
        actionDocumentos->setShortcut(QApplication::translate("MainWindow", "Ctrl+D", Q_NULLPTR));
        actionBanco_de_dados->setText(QApplication::translate("MainWindow", "Banco de dados", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionBanco_de_dados->setToolTip(QApplication::translate("MainWindow", "Configuracoes de Banco de dados", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionBanco_de_dados->setShortcut(QApplication::translate("MainWindow", "Ctrl+B", Q_NULLPTR));
        actionSobre->setText(QApplication::translate("MainWindow", "Sobre...", Q_NULLPTR));
        actionSobre->setShortcut(QApplication::translate("MainWindow", "Ctrl+I", Q_NULLPTR));
        actionProcurar_items->setText(QApplication::translate("MainWindow", "Procurar items...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionProcurar_items->setToolTip(QApplication::translate("MainWindow", "Consulta historico de atividades", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        actionProcurar_items->setWhatsThis(QApplication::translate("MainWindow", "Consulta historico de atividades", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        actionProcurar_items->setShortcut(QApplication::translate("MainWindow", "Ctrl+F", Q_NULLPTR));
        actionHist_rico->setText(QApplication::translate("MainWindow", "Hist\303\263rico", Q_NULLPTR));
        actionHist_rico->setShortcut(QApplication::translate("MainWindow", "Ctrl+H", Q_NULLPTR));
        actionOpc_es->setText(QApplication::translate("MainWindow", "Opc\303\265es", Q_NULLPTR));
        actionOpc_es->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", Q_NULLPTR));
        loginButton->setText(QApplication::translate("MainWindow", "Login", Q_NULLPTR));
        commandLinkButton->setText(QApplication::translate("MainWindow", "Cadastrar novo usu\303\241rio", Q_NULLPTR));
        logoutButton->setText(QApplication::translate("MainWindow", "Logout", Q_NULLPTR));
        labelStatus->setText(QApplication::translate("MainWindow", "[+]Status:", Q_NULLPTR));
        menuMenu->setTitle(QApplication::translate("MainWindow", "Menu", Q_NULLPTR));
        menuOpcoes->setTitle(QApplication::translate("MainWindow", "Op\303\247\303\265es", Q_NULLPTR));
        menuAjuda->setTitle(QApplication::translate("MainWindow", "Ajuda", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
