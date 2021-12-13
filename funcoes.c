// Teste dois: iniciar agenda
Agenda* iniciar_agenda(){
    Agenda *agenda = (Agenda*) malloc(sizeof(Agenda));
    FILE *arq = fopen("testes", "rb");

    if(arq){
        fread(&agenda->num_contatos, sizeof(int), 1, arq);
        agenda->lista = (Contato *) malloc (agenda->num_contatos * sizeof(Contato));
        if(!agenda->lista){
           printf("Nao foi possivel alocar vetor de contatos");
        }else{
            fread(agenda->lista, sizeof(Contato), agenda->num_contatos, arq);
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
        fwrite(agenda->lista, sizeof(Contato), agenda->num_contatos, arq);
    }
    fclose(arq);
}

void insereContato(Agenda *agenda){
    system("clear");

    int resp;
    agenda->lista = (Contato*) realloc(agenda->lista, (agenda->num_contatos + 1) * sizeof(Contato));
    printf("%d", agenda->num_contatos);

    if(!agenda->lista){
        printf("Não foi possivel aumentar o vetor de contatos!");
    }else{
        // Nome, sobrenome e email
        printf("Nome: ");
        scanf("%s", agenda->lista[agenda->num_contatos].nome);

        printf("Sobrenome: ");
        scanf("%s", agenda->lista[agenda->num_contatos].sobrenome);

        printf("Email: ");
        scanf("%s",agenda->lista[agenda->num_contatos].email);

    }
  
    // Endereço
    printf("Endereço\n");

    printf("Nome da rua: ");
    __fpurge(stdin);
    fgets(agenda->lista[agenda->num_contatos].endereco.rua, 100, stdin);

    printf("Numero da casa: ");
    scanf("%d", &agenda->lista[agenda->num_contatos].endereco.numero);

    printf("Complemento: ");
    __fpurge(stdin);
    fgets(agenda->lista[agenda->num_contatos].endereco.complemento, 100, stdin);

    printf("Nome do bairro: ");
     __fpurge(stdin);
    fgets(agenda->lista[agenda->num_contatos].endereco.bairro, 100, stdin);

    printf("Numero do cep: ");
    scanf("%d", &agenda->lista[agenda->num_contatos].endereco.cep);

    printf("Nome da cidade: ");
    __fpurge(stdin);
    fgets(agenda->lista[agenda->num_contatos].endereco.cidade, 100, stdin);

    printf("Nome da estado: ");
    __fpurge(stdin);
    fgets(agenda->lista[agenda->num_contatos].endereco.estado, 100, stdin);

    printf("Pais: ");
    __fpurge(stdin);
    fgets(agenda->lista[agenda->num_contatos].endereco.pais, 100, stdin);

    // Telefone
    printf("Telefone:\n N: %d\n", agenda->num_contatos);
    printf("DD: ");
    scanf("%d", &agenda->lista[agenda->num_contatos].telefone.dd);

    printf("Numero de telefone: ");
    scanf("%d", &agenda->lista[agenda->num_contatos].telefone.numero);

    // Data de nascimento
    printf("Data de nascimento\n");

    printf("Dia: ");
    scanf("%d", &agenda->lista[agenda->num_contatos].data.dia);

    printf("Mes: ");
    scanf("%d", &agenda->lista[agenda->num_contatos].data.mes);

    printf("Ano: ");
    scanf("%d", &agenda->lista[agenda->num_contatos].data.ano);

    printf("\n");
    agenda->num_contatos++;
    
    while (1)
    {
         printf("Deseja registrar um novo contato?\n");
         printf("1 - Sim\n");
         printf("2 - Nao\n");
         scanf("%d", &resp);
         if((resp == 1) || (resp == 2)){
             break;
         }
         
    }
     if(resp == 1){
        insereContato(agenda);
    }
    
}


void mostraContatos(Agenda *agenda){
    
    printf("Contatos na agenda: \n\n");

    int i;
    for(i = 0; i < agenda->num_contatos; i++){
        printf("===================================\n" );
        printf("Nome: %s\n", agenda->lista[i].nome);
        printf("Sobrenome: %s\n", agenda->lista[i].sobrenome);
        printf("Email: %s\n", agenda->lista[i].email);
        printf("Telefone: (%d) %d\n",  agenda->lista[i].telefone.dd, 
         agenda->lista[i].telefone.numero);
        printf("Data de nascimento: %d/%d/%d\n",
        agenda->lista[i].data.dia,
        agenda->lista[i].data.mes,
        agenda->lista[i].data.ano);

        printf("Endereço:\n ");
        printf("Nome da rua: %s\n", agenda->lista[i].endereco.rua);
        printf("Numero da casa: %d\n", agenda->lista[i].endereco.numero);
        printf("Complemento: %s\n", agenda->lista[i].endereco.complemento);
        printf("Bairro: %s\n", agenda->lista[i].endereco.bairro);
        printf("CEP: %d\n", agenda->lista[i].endereco.cep);
        printf("Cidade: %s\n", agenda->lista[i].endereco.cidade);
        printf("Estado: %s\n", agenda->lista[i].endereco.estado);
        printf("Pais: %s\n", agenda->lista[i].endereco.pais);
        printf("===================================\n" );
       
    }
}

void removeContato(Agenda *agenda){
    system("clear");

    int i = 0;
    char nome[100], sobrenome[100];

    printf("Entre com o o nome do contato a ser removido: \n");
    printf("Nome: ");
    scanf("%s", nome);
    printf("Sobrenome: ");
    scanf("%s", sobrenome);

    while (i < agenda->num_contatos){
        if(strcmp(nome, agenda->lista[i].nome) == 0 && strcmp(sobrenome, agenda->lista[i].sobrenome)){
            agenda->lista[i] = agenda->lista[agenda->num_contatos - 1];
            agenda->lista = (Contato*) realloc(agenda->lista, (agenda->num_contatos - 1) * sizeof(Contato));
            agenda->num_contatos--;
            printf("Contato excluido\n");
        }else{
            printf("Contato não encontrado\n");
        }
        i++;
    } 
}

// Menu

void menu(int *opt){
    //system("clear");
    printf("-----------Agenda---------- \n");
    printf("1 - Inserir novos contatos\n");
    printf("2 - Listar todos os contatos\n");
    printf("3 - Excluir contato\n");
    printf("4 - Buscar contato\n");
    printf("5 - Buscar aniversariantes\n");
    printf("0 - Sair\n");
    printf("Entre com um opção: ");
    scanf("%d", opt);
}

// Busca dados de uma pessoa
void buscaNome(Agenda *agenda){
    int i;
    char nome[100];

    system("clear");
    printf("Pesquisar contato pelo nome\n");

    printf("Nome: ");
    scanf("%s", nome);

    printf("\nContatos com o nome %s\n", nome);
    for(i = 0; i < agenda->num_contatos; i++){
        if(strcmp(nome, agenda->lista[i].nome) == 0){
            printf("===================================\n" );
            printf("Nome: %s\n", agenda->lista[i].nome);
            printf("Sobrenome: %s\n", agenda->lista[i].sobrenome);
            printf("Email: %s\n", agenda->lista[i].email);
            printf("Telefone: (%d) %d\n",  agenda->lista[i].telefone.dd, 
            agenda->lista[i].telefone.numero);
            printf("Data de nascimento: %d/%d/%d\n",
            agenda->lista[i].data.dia,
            agenda->lista[i].data.mes,
            agenda->lista[i].data.ano);

            printf("Endereço:\n ");
            printf("Nome da rua: %s\n", agenda->lista[i].endereco.rua);
            printf("Numero da casa: %d\n", agenda->lista[i].endereco.numero);
            printf("Complemento: %s\n", agenda->lista[i].endereco.complemento);
            printf("Bairro: %s\n", agenda->lista[i].endereco.bairro);
            printf("CEP: %d\n", agenda->lista[i].endereco.cep);
            printf("Cidade: %s\n", agenda->lista[i].endereco.cidade);
            printf("Estado: %s\n", agenda->lista[i].endereco.estado);
            printf("Pais: %s\n", agenda->lista[i].endereco.pais);
            printf("\n");
            printf("===================================\n" );
            
        }
    }
}

void aniversariantes(Agenda *agenda){
    int opcao;
    int i, mes, dia;

    system("clear");
    do
    {
         printf("Busca aniversariantes:\n");
         printf("1 - Por mês\n");
         printf("2 - Por dia\n");
         printf("3 - Sair\n");
         printf("Opção: ");
         scanf("%d", &opcao);

         switch (opcao)
         {
         case 1:
            printf("Busca aniversariantes por mes\n");
            printf("Mes: ");
            scanf("%d", &mes);
            for(i = 0; i < agenda->num_contatos; i++){
                if(mes == agenda->lista[i].data.mes){
                    printf("%s\n", agenda->lista[i].nome);
                }
            }
            break;
         case 2:
            printf("Busca aniversariantes por dia\n");
            printf("Dia: ");
            scanf("%d", &dia);
            for(i = 0; i < agenda->num_contatos; i++){
                if(dia == agenda->lista[i].data.dia){
                    printf("%s\n", agenda->lista[i].nome);
                }
            }
            break;
         default:
            printf("Opção invalida\n");
             break;
         }
    }while(opcao != 3);
}

void aniversariantes_mes(Agenda *agenda){
 
}







