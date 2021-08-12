#include "conta.h"

#include <stdio.h>

/* Executa um deposito em determinada conta
 *
 * contaParaAlterar - A conta a ser alterada
 * quantidadeDoDeposito - A quantidade a ser depositada
*/
void executarDeposito(conta *contaParaAlterar, float quantidadeDoDeposito){
  contaParaAlterar->saldo = contaParaAlterar->saldo + quantidadeDoDeposito;
}

/* Pergunta para o usuario uma quantidade e executa o deposito\
 *
 * contaParaAlterar - A conta a ser alterada
*/
void depositar(conta *contaParaAlterar){
  float quantidadeParaDeposito;

  printf("Digite a quantidade a depositar: ");
  scanf("%f", &quantidadeParaDeposito);
  setbuf(stdin, NULL);

  executarDeposito(contaParaAlterar, quantidadeParaDeposito);
}

/* Executa um saque em determinada conta
 *
 * contaParaAlterar - A conta a ser alterada
 * quantidadeDoSaque - A quantidade a ser sacada
*/
void executarSaque(conta *contaParaAlterar, float quantidadeDoSaque){
  contaParaAlterar->saldo = contaParaAlterar->saldo - quantidadeDoSaque;
}

/* Pergunta para o usuario uma quantidade e executa saque
 * 
 * contaParaAlterar - A conta a ser alterada
*/
void sacar(conta *contaParaAlterar){
  float quantidadeParaSaque;

  printf("Digite a quantidade a depositar: ");
  scanf("%f", &quantidadeParaSaque);
  getchar();

  executarSaque(contaParaAlterar, quantidadeParaSaque);
}