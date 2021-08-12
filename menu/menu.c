#include "menu.h"
#include "../clear.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
  *FECHA O CODIGO
*/
void sair(){ //
  int i;
  for (i = 4; i >=0; i--){
    printf("Saindo...\n");
    printf("TIMER: %d\n", i);
    sleep(1);
    system(CLEAR);
  }

}

/*
  * Menu Principal com as opcoes
  *
*/
void MenuPrincipal(){
  printf("\033[0;32mBem vindo ao melhor banco da historia: LibreBank\033[0m\n\n");
  printf("[1] - Registrar nova conta\n"
  "[2] - Acessar conta\n"
  "[3] - Efetuar deposito\n"
  "[4] - Efetuar saque\n"
  "[5] - Conversor de moedas\n"
  "[0] - Sair\n\n"
  "Digite uma opcao: ");

}