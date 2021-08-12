#include "conversor.h"
#include "../conta/conta.h"
#include "../moedas/valor_moedas.h"
#include "../tratamento_de_erro/tratamento_de_erro.h"

#include <stdio.h>

/*
  *Converte as moedas 
  *
*/
void Conversor(conta *contaASerAlterada){
  float valor1, valor2;
  int opcao;
    do{
      printf("Selecione a moeda que deseja trocar\n");
      printf("[1] - Dolar\n"
      "[2] - Euro\n"    
      "[3] - Bitcoin\n");
      scanf("%d", &opcao);
      setbuf(stdin, NULL);
      
      switch(opcao){
      case 1:
      printf("Digite o valor em reais a ser trocado para dolares: R$ ");
      scanf("%f", &valor1);
      setbuf(stdin, NULL);
      valor2 += VALOR_DOLAR * valor1;
      contaASerAlterada->saldo = contaASerAlterada->saldo - valor1;
      contaASerAlterada->saldoEmDolar = contaASerAlterada->saldoEmDolar + valor2;
      printf("Valor total convertido para dolares: U$%.2f\n", valor2);
      break;

      case 2:
      printf("Digite o valor em reais a ser trocado para euros: R$ ");
      scanf("%f", &valor1);
      setbuf(stdin, NULL);
      valor2 += VALOR_EURO * valor1;
      contaASerAlterada->saldo = contaASerAlterada->saldo - valor1;
      contaASerAlterada->saldoEmEuro = contaASerAlterada->saldoEmEuro + valor2;
      printf("Valor total convertido para euros: EU%.2f\n", valor2);
      break;

      case 3:
      printf("Digite o valor em reais a ser trocado para bitcoin: R$ ");
      scanf("&%f", &valor1);
      setbuf(stdin, NULL);
      valor2 += VALOR_BITCOIN * valor1;
      contaASerAlterada->saldo = contaASerAlterada->saldo - valor1;
      contaASerAlterada->saldoEmBitcoin = contaASerAlterada->saldoEmBitcoin + valor2;
      printf("Valor total convertido para bitcoins: ₿%.5f\n", valor2);
      break;
      
      default:
      tratamentoDeErro();
    } 
  }while(0);
}