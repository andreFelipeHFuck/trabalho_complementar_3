#include "init.h"
#include "funcoes.c"

int main(){
  int opt;
  int nPessoa = 0;
  Pessoa pessoa[6];

  pegaArquivo(pessoa, &nPessoa);

  do{
    menu(&opt) ;
     switch (opt)
     {
     case 1:
       inserePessoa(pessoa, &nPessoa);
       break;

      case 2:
        mostra_pessoas(pessoa, nPessoa);
        break;

      case 3:
        escreverArquivo(pessoa, &nPessoa);

     default:
       break;
     }
  }while (opt != 3);
  return 0;
}