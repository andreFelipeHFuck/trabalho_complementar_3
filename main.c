#include "init.h"
#include "funcoes.c"

int main(){
  int opt;
  Agenda *agenda = iniciarAgenda();
   
  do{
    menu(&opt) ;
     switch (opt)
     {
     case 1:
       insereContato(agenda);
       break;

      case 2:
        mostraContatos(agenda);
        break;

      case 3:
        removeContato(agenda);
        break;

      case 4:
        buscaNome(agenda);
        break;
      
      case 5:
        aniversariantes(agenda);
        break;

      case 0:
        escreverArquivo(agenda);
        break;

     default:
       break;
     }
  }while (opt != 0);
  free(agenda);
  return 0;
}