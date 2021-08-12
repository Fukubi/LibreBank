#include "user_inf.h"
#include "../conta/conta.h"
#include "../utils/utils.h"
#include "../tratamento_de_erro/tratamento_de_erro.h"
#include "../clear.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


/* Mostra os dados da conta cadastradas
 *
 * contas - O array que tem as contas guardadas
 * tamanhoArray - O tamanho do array de contas
*/
void mostrarDadosDaConta(conta contas[], int tamanhoArray){
  
  for(int i = 0; i < tamanhoArray; i++)
  {
    printf("-\t-\t-\n");
    printf("Dados da conta:\n");
    printf("-\t-\t-\n");
    printf("CPF: %s\n", contas[i].cpf);
    printf("Nome: %s\n", contas[i].nome);
    printf("Email: %s\n", contas[i].email);
    printf("Saldo em reais (BRL): R$ %.2f\n", contas[i].saldo);
    printf("Saldo em dolares (USD): $ %.2f\n", contas[i].saldoEmDolar);
    printf("Saldo em euros (EUR): € %.2f\n", contas[i].saldoEmEuro);
    printf("Saldo em bitcoins (BTC): ₿ %.7f\n", contas[i].saldoEmBitcoin);
    printf("-\t-\t-\n");
  }
}

/* Pergunta para o usuario as informacoes da nova conta e salva ela na struct
 * 
 * contas - O array que tem as contas guardadas
 * tamanhoArray - O tamanho do array de contas
*/
void perguntasIniciais(conta contas[], int tamanhoArray){
    int numConta;
    printf("Digite o numero da conta que deseja cadastrar: ");
    scanf("%d", &numConta);
    getchar();

    numConta--;

    if (numConta > (tamanhoArray - 1) && numConta < 0)
    {
      tratamentoDeErro();
      return;
    }
    
    printf("Digite o seu nome: ");
    fgets(contas[numConta].nome, STRING_MAX_SIZE, stdin );
    removerNovaLinhaDoFim(contas[numConta].nome);

    printf("Digite o seu cpf: ");
    fgets(contas[numConta].cpf, STRING_MAX_SIZE, stdin);
    removerNovaLinhaDoFim(contas[numConta].cpf);

    printf("Digite seu email: ");
    fgets(contas[numConta].email, STRING_MAX_SIZE, stdin);
    removerNovaLinhaDoFim(contas[numConta].email);

    printf("Digite seu saldo: ");
    scanf("%f", &contas[numConta].saldo);
    getchar();

    contas[numConta].saldoEmDolar = 0;
    contas[numConta].saldoEmEuro = 0;
    contas[numConta].saldoEmBitcoin = 0;
  
    system(CLEAR);
}