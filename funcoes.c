
// Teste
// Alocação dinâmica

Pessoa* alocarMemoria(){
    Pessoa *p = (Pessoa*) malloc(1 * sizeof(Pessoa));
    if(p = NULL){
        printf("\nMEMORIA INSUFICIENTE\n");
    }else{
        return p;
    }
}

// Realocação

int realocarMemoria(Pessoa *pessoa, int i){
    //printf("%d * %ld = %ld\n", (i + 1) , sizeof(Pessoa), (i + 1) * sizeof(Pessoa));
    pessoa = (Pessoa*) realloc(pessoa, i * sizeof(Pessoa));
    if(pessoa == NULL){
        printf("\nNao foi possivel realocar!");
    }else{
        printf("\nRealocação feita com sucesso!");
    }
}



// Abrir arqivos 
void pegaArquivo(Pessoa *pessoa, int *nPessoa){
    FILE *arq = fopen("testes", "rb+");
    int i;

    if(arq == NULL){
        printf("Arquivo da agenda não encontrado. Criando nova agenda\n");
        arq = fopen("testes", "wb+");
        pessoa = alocarMemoria();
    }else{
        printf("Abrindo arquivo: \n");
        fread(nPessoa, sizeof(int), 1, arq);
        fread(pessoa, sizeof(Pessoa), *nPessoa, arq);
    }

    fclose(arq);
}

void escreverArquivo(Pessoa *pessoa, int *nPessoa){
    FILE *arq = fopen("testes", "wb+");

    if(arq == NULL){
        printf("Erro ao abrir o arquivo");
    }else{
        printf("Salvando alterações.");
        fwrite(nPessoa, sizeof(int), 1, arq);
        fwrite(pessoa, sizeof(Pessoa), *nPessoa, arq);
    }
    fclose(arq);
}

//


// Menu

void menu(int *opt){
    //system("clear");
    printf("-----------Agenda---------- \n");
    printf("1 - Inserir novos contatos\n");
    printf("2 - Listar todos os contatos\n");
    printf("3 - Sair\n");
    printf("Entre com um opção: ");
    scanf("%d", opt);
}

void inserePessoa(Pessoa *pessoa, int *nPessoa){
   

    int resp;
    //int j = *nPessoa;


    pessoa = (Pessoa*) realloc(pessoa, (*nPessoa + 1) * sizeof(Pessoa));

    // Nome e email
    printf("Nome: ");
    scanf("%s", pessoa[*nPessoa].nome);

    printf("Email: ");
    scanf("%s", pessoa[*nPessoa].email);

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
    *nPessoa +=  1;
    
    // while (1)
    // {
    //     printf("Deseja registrar um nova pessoa?\n");
    //     printf("1 - Sim\n");
    //     printf("2 - Nao\n");
    //     scanf("%d", &resp);

    //     if((resp == 1) || (resp == 2)){
    //         break;
    //     }

    //     if(resp == 1){
    //         inserePessoa(pessoa, nPessoa);
    //     }

    // }
    
}

void mostra_pessoas(Pessoa *pessoa, int nPessoa){
    
    printf("Contatos na agenda: \n\n");
    int i;
    for(i = 0; i < nPessoa; i++){
        printf("===================================\n" );
        printf("Nome: %s\n", pessoa[i].nome);
        printf("Email: %s\n", pessoa[i].email);
        printf("===================================\n" );
        //printf("Numero de telefone: (%d) %d\n", pessoa[i].telefone.dd, pessoa[i].telefone.numero);
    }
}



Pessoa pessoa_vazia(){
    Pessoa pessoa;
    strcpy(pessoa.nome, "\0");
    strcpy(pessoa.email, "\0");
    strcpy(pessoa.endereco.rua, "\0");
    strcpy(pessoa.endereco.complemento, "\0");
    strcpy(pessoa.endereco.bairro, "\0");
    strcpy(pessoa.endereco.cidade, "\0");
    strcpy(pessoa.endereco.pais, "\0");
    pessoa.endereco.numero = 0;
    pessoa.endereco.cep = 0;
    pessoa.telefone.dd = 0;
    pessoa.telefone.numero = 0;
    pessoa.data.dia = 0;
    pessoa.data.mes = 0;
    pessoa.data.ano = 0;

    return pessoa;
}
