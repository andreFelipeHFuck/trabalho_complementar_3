

// Abrir arqivos 
void pegaArquivo(Pessoa *pessoa, int *nPessoa){
    FILE *arq = fopen("testes", "rb+");
    int i;

    if(arq == NULL){
        printf("Arquivo da agenda não encontrado. Criando nova agenda\n");
        arq = fopen("testes", "wb+");
        for(i = 0; i < 6; i++){
            pessoa[i] = pessoa_vazia();
        }
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
    printf("-----Agenda----- \n");
    printf("1 - Inserir novos contatos\n");
    printf("2 - Listar todos os contatos\n");
    printf("3 - Sair\n");
    printf("Entre com um opção: ");
    scanf("%d", opt);
}

void inserePessoa(Pessoa *pessoa, int *nPessoa){

     int i, n;
    // printf("Quantas pessoas deseja inserir: ");
    // scanf("%d", &n);

    // pessoa = (Pessoa*) malloc(n * sizeof(Pessoa));
    for(i = 0; i < 1; i++){
        printf("Pessoa %d\n", i + 1);

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
        *nPessoa = *nPessoa + 1;
   }
     //mostra_pessoas(pessoa, n);
}

void mostra_pessoas(Pessoa *pessoa, int nPessoa){
    printf("Dados da pessoa\n");
    int i;
    for(i = 0; i < nPessoa; i++){
        printf("Nome: %s\n", pessoa[i].nome);
        printf("Email: %s\n", pessoa[i].email);
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
