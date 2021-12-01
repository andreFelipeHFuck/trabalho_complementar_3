#include "init.h"

Pessoa *p;

void le_pessoa(int n){
    int i;
    p = (Pessoa*) malloc(n * sizeof(Pessoa));
    for(i = 0; i < n; i++){
        printf("Digite o nome: ");
        scanf("%s", p[i].nome);
        printf("Digite o email: ");
        scanf("%s", p[i].email);

        // Endereço
        printf("Digite o endereço\n");
        printf("Digite o nome da rua: ");
        __fpurge(stdin);
        fgets(p[i].endereco.rua, 100, stdin);
        // printf("Digite o numero da casa: ");
        // scanf("%d", &p[i].endereco.numero);

   }
 
}

void mostra_pessoa(Pessoa p){
    printf("Nome: %s\n", p.nome);
    printf("Email: %s\n", p.email);
}

int main(){
   int  i, n;
   scanf("%d", &n);
   
   le_pessoa(n);

   printf("\n");
   for(i = 0; i <= n; i++){
       printf("%s\n", p[i].endereco.rua);
   }
}