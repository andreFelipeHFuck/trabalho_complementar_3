#include "init.h"
#include "funcoes.c"

int main(){
  int opt;
  Agenda *agenda = iniciar_agenda();
   
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
        escreverArquivo(agenda);
        break;

     default:
       break;
     }
  }while (opt != 4);
  free(agenda);
  return 0;
}