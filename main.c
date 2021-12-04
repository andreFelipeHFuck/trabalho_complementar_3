#include "init.h"
#include "funcoes.c"

int main(){
  int opt;
  int nPessoa = 0;
  Pessoa pessoa[6];

//  pegaArquivo();
//  inserePessoa(pessoa, &nPessoa);
//  pegaArquivo();

//  menu(&opt);
//  printf("%d", opt);
  do{
    menu(&opt) ;
     switch (opt)
     {
     case 1:
       inserePessoa(pessoa, &nPessoa);
       break;

      case 2:
        mostra_pessoas(pessoa);
        break;

     default:
       break;
     }
  }while (opt != 3);
  return 0;
}