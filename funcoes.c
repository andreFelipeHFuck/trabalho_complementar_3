// Teste dois: iniciar agenda
Agenda* iniciar_agenda(){
    Agenda *agenda = (Agenda*) malloc(sizeof(Agenda));
    FILE *arq = fopen("testes", "rb");

    if(arq){
        fread(&agenda->num_contatos, sizeof(int), 1, arq);
        agenda->lista = (Pessoa*) malloc (agenda->num_contatos * sizeof(Pessoa));
        if(!agenda->lista){
           printf("Nao foi possivel alocar vetor de contatos");
        }else{
            fread(agenda->lista, sizeof(Pessoa), agenda->num_contatos, arq);
            fclose(arq);
        }
    }else{
        agenda->num_contatos = 0;
        agenda->lista = 0;
    }
    return agenda;
}

void escreverArquivo(Agenda *agenda){
    FILE *arq = fopen("testes", "wb+");

    if(arq == NULL){
        printf("Erro ao abrir o arquivo");
    }else{
        printf("Salvando alterações.");
        fwrite(&agenda->num_contatos, sizeof(int), 1, arq);
        fwrite(agenda->lista, sizeof(Pessoa), agenda->num_contatos, arq);
    }
    fclose(arq);
}

void inserePessoa(Agenda *agenda){
    system("clear");

    int resp;
    agenda->lista = (Pessoa*) realloc(agenda->lista, (agenda->num_contatos + 1) * sizeof(Pessoa));

    if(!agenda->lista){
        printf("Não foi possivel aumentar o vetor de contatos!");
    }else{
        // Nome e email
        printf("Nome: ");
        scanf("%s", agenda->lista[agenda->num_contatos].nome);

        printf("Email: ");
        scanf("%s",agenda->lista[agenda->num_contatos].email);

    }
    agenda->num_contatos++;

    // Endereço
    // printf("Endereço\n");

    // printf("Nome da rua: ");
    //  __fpurge(stdin);
    //  fgets(pessoa[*nPessoa].endereco.rua, 100, stdin);

    //  printf("Numero da casa: ");
    //  scanf("%d", &pessoa[*nPessoa].endereco.numero);

    //  printf("Complemento: ");
    //  __fpurge(stdin);
    //  fgets(pessoa[*nPessoa].endereco.complemento, 100, stdin);

    //  printf("Nome do bairro: ");
    //  __fpurge(stdin);
    //  fgets(pessoa[*nPessoa].endereco.bairro, 100, stdin);

    //  printf("Numero do cep: ");
    //  scanf("%d", &pessoa[*nPessoa].endereco.cep);

    //  printf("Nome da cidade: ");
    //  __fpurge(stdin);
    //  fgets(pessoa[*nPessoa].endereco.cidade, 100, stdin);

    //  printf("Nome da estado: ");
    //  __fpurge(stdin);
    //  fgets(pessoa[*nPessoa].endereco.estado, 100, stdin);

    //  printf("Pais: ");
    //  __fpurge(stdin);
    //  fgets(pessoa[*nPessoa].endereco.pais, 100, stdin);

    // // Telefone
    // printf("Telefone:\n ");
    // printf("DD: ");
    // scanf("%d", &pessoa[*nPessoa].telefone.dd);

    // printf("Numero de telefone: ");
    // scanf("%d", &pessoa[*nPessoa].telefone.numero);

    // // Data de nascimento
    // printf("Data de nascimento\n");

    // printf("Dia: ");
    // scanf("%d", &pessoa[*nPessoa].data.dia);

    // printf("Mes: ");
    // scanf("%d", &pessoa[*nPessoa].data.mes);

    // printf("Ano: ");
    // scanf("%d", &pessoa[*nPessoa].data.ano);

    printf("\n");
    
    while (1)
    {
         printf("Deseja registrar um nova pessoa?\n");
         printf("1 - Sim\n");
         printf("2 - Nao\n");
         scanf("%d", &resp);
         if((resp == 1) || (resp == 2)){
             break;
         }
         
    }
     if(resp == 1){
        inserePessoa(agenda);
    }
    
}


void mostra_pessoas(Agenda *agenda){
    
    printf("Contatos na agenda: \n\n");

    int i;
    for(i = 0; i < agenda->num_contatos; i++){
        printf("===================================\n" );
        printf("Nome: %s\n", agenda->lista[i].nome);
        printf("Email: %s\n", agenda->lista[i].email);
        printf("===================================\n" );
        //printf("Numero de telefone: (%d) %d\n", pessoa[i].telefone.dd, pessoa[i].telefone.numero);
    }
}

void removeContato(Agenda *agenda){
    printf("Entre com o o nome do contato a ser removido: \n");
    char nome[100];
    __fpurge(stdin);
    fgets(nome, sizeof(nome), stdin);
}

// Menu

void menu(int *opt){
    system("clear");
    printf("-----------Agenda---------- \n");
    printf("1 - Inserir novos contatos\n");
    printf("2 - Listar todos os contatos\n");
    printf("3 - Excluir contato\n");
    printf("4 - Sair\n");
    printf("Entre com um opção: ");
    scanf("%d", opt);
}







