#-------------------------------------------------
#
# Project created by QtCreator 2014-04-27T21:04:48
# By: Vitor Sgobbi
# E-mail: vitorsgobbi@hotmail.com
#
#** $QT_LICENSA:BSD$
#** ESTE SOFTWARE FOI CRIADO COM A FERRAMENTA QT GPL SOB A LICENSA PUBLICA GERAL
#** E FERRAMENTAS 'OPEN SOURCE'. A REDISTRIBUICAO DESTE SISTEMA E PROIBIDA E DE SOMENTE
#** PARA USO DE SEUS CLIENTES AUTORIZADOS. PROIBIDA A COPIA TOTAL OU PARCIAL DESTE PROJETO,
#** EM CASO DE DUVIDAS CONTATAR O CRIADOR POR E-MAIL: VITORSGOBBI@HOTMAIL.COM. TODO O SISTEMA
#** FOI CRIADO EM LINGUAGEM C++, QT CREATOR VERSAO 4.8.6. SUA DOCUMENTACAO BASICA SE ENCONTRA
#** JUNTO COM O SOFTWARE, COMO DIAGRAMAS DE CASO DE USO, DIAGRAMAS DE CLASSES E SEUS REQUISITOS
#** FUNCIONAIS E NAO FUNCIONAIS. O SISTEMA PODE SER UTILIZADO SOMENTE EM AMBIENTE WINDOWS E EM
#** COMPUTADORES DA EMPRESA O BOTICARIO CP-HARMONIA DE ADAMANTINA E REGIAO. O SISTEMA POSSUI CONTROLE
#** DE VERSAO E PROTOTIPAGEM DE ACORDO COM AS NORMAS DE ENGENHARIA DE SOFTWARE UML (UNIFIED MODELING LANGUAGE).
#** $QT_FIM_LICENSA$
#-------------------------------------------------


QT       += core gui
QT       += sql

#QT  +=  axserver
QT  +=  axcontainer

RC_FILE  = qaxserver.rc
#DEF_FILE = qaxserver.def

#VERSION = 2.5

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = botiProject
TEMPLATE = app

wince*: DEPLOYMENT_PLUGIN += qsqlite

SOURCES += main.cpp\
        mainwindow.cpp \
    seconddialog.cpp \
    login.cpp \
    cadastroUser.cpp \
    procpickinglist.cpp

HEADERS  += mainwindow.h \
    seconddialog.h \
    login.h \
    cadastroUser.h \
    procpickinglist.h


FORMS    += mainwindow.ui \
    seconddialog.ui \
    login.ui \
    cadastroUser.ui \
    procpickinglist.ui

OTHER_FILES += \
    Especif.txt \
    codigosTeste.txt \
    usbDriverInformation.txt

RESOURCES += \
    iconesPrim.qrc \
    procurarTexto.qrc

CONFIG += c++11
CONFIG += static

# install

target.path = $$[QT_INSTALL_EXAMPLES]/sql/querymodel
sources.files = $$SOURCES *.h $$RESOURCES $$FORMS querymodel.pro
sources.path = $$[QT_INSTALL_EXAMPLES]/sql/querymodel
INSTALLS += target sources

DISTFILES += \
    exemploSalvarPlanilhaCSV \
    exemploSalvarPlanilhaCSV.txt
