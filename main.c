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

#define CHAR_MAX 75

typedef struct Conta{
  char cpf[CHAR_MAX];
  char nome[CHAR_MAX];
  char email[CHAR_MAX];
  float saldo;
  
} conta;

conta contaPrincipal;

void sair(){ //FECHA O CODIGO
  int i;
  for (i = 4; i >=0; i--){
    system("clear");
    printf("Saindo...");
      sleep(1);
    printf("TIMER: %d\n", i);
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
void removerNovaLinhaDoFim(char string[])
{
  if (string[strlen(string) - 1] == '\n')
    string[strlen(string) - 1] = '\0';
}

void Transacao(){
}

void MenuPrincipal(){
  printf("\033[0;32mBem vindo ao melhor banco da historia: LibreBank\033[0m\n\n");
  printf("[1] - Registrar nova conta\n"
  "[2] - Acessar conta\n"
  "[3] - Efetuar depósito\n"
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
    valor2 = 5.23 * valor1;
    printf("Valor total convertido para reais: R$%.2f\n", valor2);
    break;

    case 2:
    printf("Digite o valor em euros a ser trocado para reais: R$ ");
    scanf("%f", &valor1);
    setbuf(stdin, NULL);
    valor2 = 6.15 * valor1;
    printf("Valor total convertido para reais: R$%.2f\n", valor2);
    break;

    case 3:
    printf("Digite o valor em euros a ser trocado para reais: R$ ");
    scanf("&%f", &valor1);
    setbuf(stdin, NULL);
    valor2 = 237566.97 * valor1;
    printf("Valor total convertido para reais: R$%.2f\n", valor2);
    break;
    
    default:
    tratamentoDeErro();
  } 
}while(0);
}

/* Executa um saque em determinada conta
 *
 * quantidadeDoSaque - A quantidade a ser sacada
*/
void executarSaque(float quantidadeDoSaque)
{
  contaPrincipal.saldo -= quantidadeDoSaque;
}

// Pergunta para o usuario uma quantidade e executa saque
void sacar()
{
  float quantidadeParaSaque;

  printf("Digite a quantidade a depositar: ");
  scanf("%f", &quantidadeParaSaque);
  getchar();

  executarSaque(quantidadeParaSaque);
}

/* Executa um deposito em determinada conta
 *
 * quantidadeDoDeposito - A quantidade a ser depositada
*/
void executarDeposito(float quantidadeDoDeposito){
  contaPrincipal.saldo += quantidadeDoDeposito;
}

// Pergunta para o usuario uma quantidade e executa o deposito
void depositar()
{
  float quantidadeParaDeposito;

  printf("Digite a quantidade a depositar: ");
  scanf("%f", &quantidadeParaDeposito);
  setbuf(stdin, NULL);

  executarDeposito(quantidadeParaDeposito);
}

// Mostra os dados da conta cadastradas
void mostrarDadosDaConta()
{
  printf("-\t-\t-\n");
  printf("Dados da conta\n");
  printf("-\t-\t-\n");
  printf("CPF: %s\n", contaPrincipal.cpf);
  printf("Nome: %s\n", contaPrincipal.nome);
  printf("Email: %s\n", contaPrincipal.email);
  printf("Saldo: %.2f\n", contaPrincipal.saldo);
  printf("-\t-\t-\n");
}

// Pergunta para o usuario as informacoes da nova conta e salva ela na struct
void perguntasIniciais(){
    printf("Digite o seu nome: ");
    fgets(contaPrincipal.nome, CHAR_MAX, stdin );
    removerNovaLinhaDoFim(contaPrincipal.nome);

    printf("Digite o seu cpf: ");
    fgets(contaPrincipal.cpf, CHAR_MAX, stdin);
    removerNovaLinhaDoFim(contaPrincipal.cpf);

    printf("Digite seu email: ");
    fgets(contaPrincipal.email, CHAR_MAX, stdin);
    removerNovaLinhaDoFim(contaPrincipal.email);

    printf("Digite seu saldo: ");
    scanf("%f", &contaPrincipal.saldo);
    getchar();
    
    system("clear");
}

int main(void) {
  while(1)
  {
    int opcao;
    MenuPrincipal();
    scanf("%d", &opcao);
    setbuf(stdin, NULL);
    system("clear");
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