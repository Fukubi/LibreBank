#ifndef CONTA_H
#define CONTA_H

#define STRING_MAX_SIZE 75

typedef struct Conta{
  char cpf[STRING_MAX_SIZE];
  char nome[STRING_MAX_SIZE];
  char email[STRING_MAX_SIZE];
  float saldo;
  float saldoEmDolar;
  float saldoEmEuro;
  float saldoEmBitcoin;
} conta;

void depositar(conta *contaParaAlterar);
void sacar(conta *contaParaAlterar);

#endif