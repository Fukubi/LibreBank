#include "utils.h"
#include <string.h>

/* Remove o \n no fim de uma String 
 * string - A string para remover o \n
*/
void removerNovaLinhaDoFim(char string[]){
  if (string[strlen(string) - 1] == '\n')
    string[strlen(string) - 1] = '\0';
}