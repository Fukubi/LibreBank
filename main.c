/* [1] - Registrar nova conta
   [2] - Acessar conta
   [3] - Efetuar depósito
   [4] - Efetuar saque
   [5] - Conversor de moedas
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define STRING_MAX_SIZE 75

#if _WIN32
  #define CLEAR "cls"
#elif __linux__
  #define CLEAR "clear"
#endif

#define VALOR_DOLAR 0.19
#define VALOR_EURO 0.16
#define VALOR_BITCOIN 0.0000042

typedef struct Conta{
  char cpf[STRING_MAX_SIZE];
  char nome[STRING_MAX_SIZE];
  char email[STRING_MAX_SIZE];
  float saldo;
  float saldoEmDolar;
  float saldoEmEuro;
  float saldoEmBitcoin;
} conta;

conta contaPrincipal;

void sair(){ //FECHA O CODIGO
  int i;
  for (i = 4; i >=0; i--){
    printf("Saindo...");
    printf("TIMER: %d\n", i);
    sleep(1);
    system(CLEAR);
  }

}

void pausa(){ //DIGITA ENTER PARA VOLTAR

 printf("Digite qualquer tecla para continuar.");
 system("pause");
}

void tratamentoDeErro(){ //TRATA DIGITOS ERRADOS 
 printf("Digite um valor válido: ");
  
}

/* Remove o \n no fim de uma String 
 * string - A string para remover o \n
*/
void removerNovaLinhaDoFim(char string[]){
  if (string[strlen(string) - 1] == '\n')
    string[strlen(string) - 1] = '\0';
}

void Transacao(){
}

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

void Conversor(){
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
    printf("Digite o valor em dolares a ser trocado para reais: R$ ");
    scanf("%f", &valor1);
    setbuf(stdin, NULL);
    valor2 = VALOR_DOLAR * valor1;
    printf("Valor total convertido para reais: R$%.2f\n", valor2);
    break;

    case 2:
    printf("Digite o valor em euros a ser trocado para reais: R$ ");
    scanf("%f", &valor1);
    setbuf(stdin, NULL);
    valor2 = VALOR_EURO * valor1;
    printf("Valor total convertido para reais: R$%.2f\n", valor2);
    break;

    case 3:
    printf("Digite o valor em euros a ser trocado para reais: R$ ");
    scanf("&%f", &valor1);
    setbuf(stdin, NULL);
    valor2 = VALOR_BITCOIN * valor1;
    printf("Valor total convertido para reais: R$%.2f\n", valor2);
    break;
    
    default:
    tratamentoDeErro();
  } 
}while(0);
}

// Converte o saldo atual nas moedas disponiveis
void converterSaldoParaOutrasMoedas()
{
  contaPrincipal.saldoEmDolar = contaPrincipal.saldo * VALOR_DOLAR;

  contaPrincipal.saldoEmEuro = contaPrincipal.saldo * VALOR_EURO;
    
  contaPrincipal.saldoEmBitcoin = contaPrincipal.saldo * VALOR_BITCOIN;
}

/* Executa um saque em determinada conta
 *
 * quantidadeDoSaque - A quantidade a ser sacada
*/
void executarSaque(float quantidadeDoSaque){
  contaPrincipal.saldo -= quantidadeDoSaque;

  converterSaldoParaOutrasMoedas();
}

// Pergunta para o usuario uma quantidade e executa saque
void sacar(){
  float quantidadeParaSaque;

  printf("Digite a quantidade a depositar: ");
  scanf("%f", &quantidadeParaSaque);
  getchar();

  executarSaque(quantidadeParaSaque);

  converterSaldoParaOutrasMoedas();
}

/* Executa um deposito em determinada conta
 *
 * quantidadeDoDeposito - A quantidade a ser depositada
*/
void executarDeposito(float quantidadeDoDeposito){
  contaPrincipal.saldo += quantidadeDoDeposito;
}

// Pergunta para o usuario uma quantidade e executa o deposito
void depositar(){
  float quantidadeParaDeposito;

  printf("Digite a quantidade a depositar: ");
  scanf("%f", &quantidadeParaDeposito);
  setbuf(stdin, NULL);

  executarDeposito(quantidadeParaDeposito);

  converterSaldoParaOutrasMoedas();
}

// Mostra os dados da conta cadastradas
void mostrarDadosDaConta(){
  printf("-\t-\t-\n");
  printf("Dados da conta:\n");
  printf("-\t-\t-\n");
  printf("CPF: %s\n", contaPrincipal.cpf);
  printf("Nome: %s\n", contaPrincipal.nome);
  printf("Email: %s\n", contaPrincipal.email);
  printf("Saldo em reais (BRL): R$ %.2f\n", contaPrincipal.saldo);
  printf("Saldo em dolares (USD): $ %.2f\n", contaPrincipal.saldoEmDolar);
  printf("Saldo em euros (EUR): € %.2f\n", contaPrincipal.saldoEmEuro);
  printf("Saldo em bitcoins (BTC): ₿ %.7f\n", contaPrincipal.saldoEmBitcoin);
  printf("-\t-\t-\n");
}

// Pergunta para o usuario as informacoes da nova conta e salva ela na struct
void perguntasIniciais(){
    printf("Digite o seu nome: ");
    fgets(contaPrincipal.nome, STRING_MAX_SIZE, stdin );
    removerNovaLinhaDoFim(contaPrincipal.nome);

    printf("Digite o seu cpf: ");
    fgets(contaPrincipal.cpf, STRING_MAX_SIZE, stdin);
    removerNovaLinhaDoFim(contaPrincipal.cpf);

    printf("Digite seu email: ");
    fgets(contaPrincipal.email, STRING_MAX_SIZE, stdin);
    removerNovaLinhaDoFim(contaPrincipal.email);

    printf("Digite seu saldo: ");
    scanf("%f", &contaPrincipal.saldo);
    getchar();

    converterSaldoParaOutrasMoedas();
    
    system(CLEAR);
}

int main(void) {
  while(1)
  {
    int opcao;
    MenuPrincipal();
    scanf("%d", &opcao);
    setbuf(stdin, NULL);
    system(CLEAR);
    switch(opcao){
      case 1:
        perguntasIniciais();
        break;
      case 2:
        mostrarDadosDaConta();
        break;
      case 3:
        depositar();
        break;
      case 4:
        sacar();
        break;
      case 5:
        Conversor();
        break;
      case 0:
        sair();
        return 0;
        break;
      default:
        tratamentoDeErro();
        break;
    }
  }

  return 0;
}