

// Abrir arqivos 
void pegaArquivo(){
    FILE *arq = fopen("testes", "rb+");
    char Linha[100];
    char *result;
    int i;

    if(arq == NULL){
        printf("Arquivo da agenda não encontrado. Criando nova agenda\n");
        arq = fopen("testes", "wb+");
    }else{
        printf("Abrindo arquivo: \n");
          for(i = 0; i < sizeof(arq); i++){
            result = fgets(Linha, 100, arq);
            if(result)
            printf("Linha %d: %s", i, Linha);
        }
    }

    fclose(arq);
}

void escreverArquivo(Pessoa *pessoa, int *nPessoa){
    FILE *arq = fopen("testes", "wb+");

    if(arq == NULL){
        printf("Erro ao abrir o arquivo");
    }else{
        printf("Salvando alterações.");
        fwrite(pessoa, sizeof(Pessoa), 1, arq);
    }
    fclose(arq);
}

//


// Menu

void menu(int *opt){
    printf("-----Agenda----- \n");
    printf("1 - Inserir novos contatos\n");
    printf("2 - Listar todos os contatos\n");
    printf("3 - Sair\n");
    printf("Entre com um opção: ");
    scanf("%d", opt);
}

void inserePessoa(Pessoa *pessoa, int *nPessoa){

    int i, n;
    printf("Quantas pessoas deseja inserir: ");
    scanf("%d", &n);

    pessoa = (Pessoa*) malloc(n * sizeof(Pessoa));
    for(i = 0; i < n; i++){
        printf("Pessoa %d\n", i + 1);

        // Nome e email
        printf("Nome: ");
        scanf("%s", pessoa[i].nome);

        printf("Email: ");
        scanf("%s", pessoa[i].email);

        // Endereço
        printf("Endereço\n");

        printf("Nome da rua: ");
         __fpurge(stdin);
         fgets(pessoa[i].endereco.rua, 100, stdin);

         printf("Numero da casa: ");
         scanf("%d", &pessoa[i].endereco.numero);

         printf("Complemento: ");
         __fpurge(stdin);
         fgets(pessoa[i].endereco.complemento, 100, stdin);

         printf("Nome do bairro: ");
         __fpurge(stdin);
         fgets(pessoa[i].endereco.bairro, 100, stdin);

         printf("Numero do cep: ");
         scanf("%d", &pessoa[i].endereco.cep);

         printf("Nome da cidade: ");
         __fpurge(stdin);
         fgets(pessoa[i].endereco.cidade, 100, stdin);

         printf("Nome da estado: ");
         __fpurge(stdin);
         fgets(pessoa[i].endereco.estado, 100, stdin);

         printf("Pais: ");
         __fpurge(stdin);
         fgets(pessoa[i].endereco.pais, 100, stdin);

        // Telefone
        printf("Telefone:\n ");
        printf("DD: ");
        scanf("%d", &pessoa[i].telefone.dd);

        printf("Numero de telefone: ");
        scanf("%d", &pessoa[i].telefone.numero);

        printf("\n");
   }
     //mostra_pessoas(pessoa, n);
}

void mostra_pessoas(Pessoa *pessoa){
    int i;
    for(i = 0; i < 1; i++){
        printf("Nome: %s\n", pessoa[i].nome);
        printf("Email: %s\n", pessoa[i].email);
        printf("Numero de telefone: (%d) %d\n", pessoa[i].telefone.dd, pessoa[i].telefone.numero);
    }
}

