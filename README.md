# LibreBank

<p align=center>
 <a href="#"><img alt="GitHub top language" src="https://img.shields.io/github/languages/top/Fukubi/LibreBank"></a>
 <a href="#"><img alt="Lines of code" src="https://img.shields.io/tokei/lines/github/Fukubi/LibreBank"></a>
 <a href="#"><img alt="GitHub repo size" src="https://img.shields.io/github/repo-size/Fukubi/LibreBank"></a>
 <a href="#"><img alt="GitHub Version" src="https://img.shields.io/badge/Version-1.0.0-blue"></a>
</p>

## Index and Languages / Índice e Línguas

* [English](#LibreBank-Project)  
  * [How To Compile and Execute](#How-to-Compile-and-Execute)
  * [Task List](#Task-List)
  * [Participants](#Participants)
* [Português](#Projeto-LibreBank)
  * [Como Compilar e Executar](#Como-compilar-e-executar)
  * [Lista de Tarefas](#Lista-de-Tarefas)
  * [Participantes](#Participantes)

## LibreBank Project

The LibreBank project is a bank simulator that was made with the objective of practice and learn how to use the C Language.

[![Main Screen](https://raw.githubusercontent.com/Fukubi/LibreBank/main/DEMO/tela_principal.PNG)](#)

### How to Compile and Execute

- Linux  
    Make sure that the C compiler (GCC is the recommended) is installed correctly and execute  
    ```gcc -o librebank main.c conta/conta.c conversor/conversor.c menu/menu.c programa/programa.c tratamento_de_erro/tratamento_de_erro.c user_inf/user_inf.c utils/utils.c```  

    After that it will be possible to execute the program using ```./librebank```.

- Windows  
    Install a C compiler (Mingw-w64 is the recommended) and execute  
    ```gcc -o librebank main.c conta/conta.c conversor/conversor.c menu/menu.c programa/programa.c tratamento_de_erro/tratamento_de_erro.c user_inf/user_inf.c utils/utils.c```

    After this it will be created a executable in the same folder that the command above was executed, you can execute the program using ```.\librebank.exe```.
### Task List

- [x] Basic functionalities of the bank.
- [x] Show the balance in different currencies.
- [x] Support for multiple accounts.

## Participants

* [Gabriel Nobrega](https://github.com/NBrcS)
* [Rodrigo Lanes](https://github.com/rodrigolanesm)
* [Deivid Gabriel](https://github.com/Fukubi)

## Projeto LibreBank

O projeto LibreBank é um simulador de banco feito com o objetivo de praticar e aprender a utilizar a linguagem de programação C.

[![Tela Inicial](https://raw.githubusercontent.com/Fukubi/LibreBank/main/DEMO/tela_principal.PNG)](#)

### Como compilar e executar

- Linux  
    Tenha certeza de que o compilador C está instalado corretamente (GCC é o recomendado) e execute  
    ```gcc -o librebank main.c conta/conta.c conversor/conversor.c menu/menu.c programa/programa.c tratamento_de_erro/tratamento_de_erro.c user_inf/user_inf.c utils/utils.c```  

    Após isso será possível executar o programa utilizando ```./librebank```.

- Windows  
    Instale um compilador C (mingw-w64 é o recomendado) e execute  
    ```gcc -o librebank main.c conta/conta.c conversor/conversor.c menu/menu.c programa/programa.c tratamento_de_erro/tratamento_de_erro.c user_inf/user_inf.c utils/utils.c```

    Após isso será criado um executável na pasta onde esse comando foi executado, você poderá executar o programa utilizando ```.\librebank.exe```.
### Lista de Tarefas

- [x] Funcionalidades basicas do banco.
- [x] Mostrar saldo em diferentes moedas.
- [x] Suporte a multiplas contas.

## Participantes

* [Gabriel Nobrega](https://github.com/NBrcS)
* [Rodrigo Lanes](https://github.com/rodrigolanesm)
* [Deivid Gabriel](https://github.com/Fukubi)
