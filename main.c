#include "init.h"
#include "funcoes.c"

int main(){
  int opt;
  int nPessoa = 0;
  Pessoa *pessoas;
  int n = 3;

  Agenda *agenda = iniciar_agenda();
   
  do{
    menu(&opt) ;
     switch (opt)
     {
     case 1:
       
       inserePessoa(agenda);
       break;

      case 2:
        mostra_pessoas(agenda);
        break;

      case 3:
        escreverArquivo(agenda);

     default:
       break;
     }
  }while (opt != 3);
  return 0;
}