#include "init.h"
#include "funcoes.c"

int main(){
  int opt;
  int nPessoa = 0;
  Pessoa *pessoas;
  int n = 3;

  
   
  pegaArquivo(pessoas, &nPessoa);

  do{
    menu(&opt) ;
     switch (opt)
     {
     case 1:
       
       inserePessoa(pessoas, &nPessoa);
       break;

      case 2:
        mostra_pessoas(pessoas, nPessoa);
        break;

      case 3:
        escreverArquivo(pessoas, &nPessoa);

     default:
       break;
     }
  }while (opt != 3);
  return 0;
}