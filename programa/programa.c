#include "programa.h"

#include "../conta/conta.h"
#include "../clear.h"
#include "../menu/menu.h"
#include "../user_inf/user_inf.h"
#include "../tratamento_de_erro/tratamento_de_erro.h"
#include "../conversor/conversor.h"

#include <stdio.h>
#include <stdlib.h>

int programa(){
  int numContas;
  
    printf("Digite a quantidade de contas que serao registradas: ");
    scanf("%d", &numContas);
    getchar();
    conta contas[numContas];

    system(CLEAR);
    
    while(1)
    {
      int opcao, numeroASerDepositado, numeroASerSacado, numeroDaContaASerConvertido;
      MenuPrincipal();
      scanf("%d", &opcao);
      setbuf(stdin, NULL);
      system(CLEAR);
      switch(opcao){
        case 1:
          perguntasIniciais(contas, numContas);
          break;
        case 2:
          mostrarDadosDaConta(contas, numContas);
          break;
        case 3:
          printf("Digite o numero da conta a ser depositada: ");
          scanf("%d", &numeroASerDepositado);
          getchar();

          numeroASerDepositado--;

          if (numeroASerDepositado > (numContas - 1) && numeroASerSacado < 0)
          {
            tratamentoDeErro();
            break;
          } else
            depositar(&contas[numeroASerDepositado]);
          break;
        case 4:
          printf("Digite o numero da conta a executar o saque: ");
          scanf("%d", &numeroASerSacado);
          getchar();

          numeroASerSacado--;

          if (numeroASerSacado > (numContas - 1) && numeroASerSacado < 0)
          {
            tratamentoDeErro();
            break;
          } else
            sacar(&contas[numeroASerSacado]);
          break;
        case 5:
          printf("Digite o numero da conta a executar a conversao: ");
          scanf("%d", &numeroDaContaASerConvertido);
          getchar();

          numeroDaContaASerConvertido--;
          
          if (numeroDaContaASerConvertido > (numContas - 1) && numeroDaContaASerConvertido < 0)
          {
            tratamentoDeErro();
            break;
          } else
            Conversor(&contas[numeroDaContaASerConvertido]);
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