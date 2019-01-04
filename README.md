# Project created by QtCreator 2014-04-27T21:04:48

# Desenvolvido por: Vitor Gabriel Sgobbi

# E-mail: vitorsgobbi@hotmail.com



LICENSA:LGPL

### ESTE SOFTWARE FOI CRIADO COM A FERRAMENTA QT GPL SOB A LICENSA PUBLICA GERAL
E FERRAMENTAS 'OPEN SOURCE'. A REDISTRIBUICAO DESTE SISTEMA E PROIBIDA E DE SOMENTE
PARA USO DE SEUS CLIENTES AUTORIZADOS. PROIBIDA A COPIA TOTAL OU PARCIAL DESTE PROJETO,
VERIFIQUE LGPLv3.0 (https://www.gnu.org/licenses/lgpl-3.0.pt-br.html)
EM CASO DE DUVIDAS CONTATAR O CRIADOR POR E-MAIL: VITORSGOBBI@HOTMAIL.COM.
O SISTEMA FOI CRIADO EM LINGUAGEM C++, QT CREATOR VERSAO 4.8.6. SUA DOCUMENTACAO BASICA SE ENCONTRA
JUNTO COM O SOFTWARE, COMO DIAGRAMAS DE CASO DE USO, DIAGRAMAS DE CLASSES E SEUS REQUISITOS
FUNCIONAIS E NAO FUNCIONAIS. O SISTEMA PODE SER UTILIZADO SOMENTE EM AMBIENTE WINDOWS E EM
COMPUTADORES DA EMPRESA O BOTICARIO CP-HARMONIA DE ADAMANTINA E REGIAO. O SISTEMA POSSUI CONTROLE
DE VERSAO E PROTOTIPAGEM DE ACORDO COM AS NORMAS DE ENGENHARIA DE SOFTWARE UML (UNIFIED MODELING LANGUAGE).
### 

CARACTERÍSTCIAS PRINCIPAIS


    1. O atendente é quem faz um pedido. (A lista é gerada no sistema "GERA", sistema online) com (login e senha).

    2. Estoquista separa os produtos, pré-seleciona os produtos da "Picking List" gerada pelo sistema "GERA".

    3. Atendente (Back Office) faz a conferencia (Deve fazer o faturamento correto), 
       para isso possui a funcão de gerar relatórios com dados citados e data de processamento concluído.

    4. O nível de conhecimento tecnológico ou computacional do "Bakoffice" pode e deve ser baixíssimo.
       (Sistema deve ter interface gráfica intuitiva).

    5. O sistema deve suportar diferentes drivers de leitores de código de barra.


    1. Capturar banco de dados já existentes

    2. Fazer login ou cadastro do usuário

    3. Importar uma "Picking List" 

    4. Processar toda a tabela importada por inteiro

    5. Gerenciar relatórios de modo automático

    6. Emitir mensagem ao "Back Office" de que a tabela foi processada (Funcao de "Packing" com 100% de acurácia) 

    7. Impressão de tabelas ou Arquivo de Histórico

    8. Fazer logout e encerrar sistema para que possa ser utilizado por outro funcionário do mesmo departamento


REQUISITOS FUNCIONAIS E NÃO FUNCIONAIS:


    1. Deve possuir sistema de segurança com banco de dados SQLite.
    
    2. Deve identificar o usuário que está utilizando o sistema.

    3. Pedido no sistema (Gera) deve criar arquivo de controle para o estoquista.

    4. Desempenho do software em linguagem de alto nível C++, os arquivos de extensão ".xls" e variáveis 

       devem ser liberados da memória e tabelas 'in cache' do computador que está utilizando o sistema, obtendo um processamento

       rápido e eficaz. 


VALIDAÇÃO:


    1. Versão de controle atual: V.1.0

    2. Data de release: 29/05/2014

    3. Número de patente: inexistente

    4. Licensa: LGPL

    5. Ambiente ou plataforma: Win 32

    6. SDK (Kits de desenvolvimento): Qt Creator 4.8, Inno Setup, CMake 2.8, MingW
