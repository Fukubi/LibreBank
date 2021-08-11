/*
1. registro de usuários
2. transações
3. depósitos
4. saques
5. conversor
*/

#include <stdio.h>
#include <stdlib.h>

#define CHAR_MAX 75

typedef struct dados{
  char cpf;
  char nome;
  char email;
  float saldo;
  
}cliente;

void perguntasIniciais(){
  struct dados;
  
    printf("Digite o seu nome: ");
    fgets(dados.cliente, CHAR_MAX, stdin );

    printf("Digite o seu cpf: ");
    fgets(dados.cpf, CHAR_MAX, stdin);

    printf("Digite seu email: ");
    fgets("");

}

void Transacao(){
}

void MenuPrincipal(){
  printf("[Bem vindo ao pior banco da historia: ");
}




int main(void) {



  return 0;
}