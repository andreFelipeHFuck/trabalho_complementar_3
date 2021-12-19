#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>


/*
Trabalho complementar 3
Arquivo com as estruturas de dados e com o cabeçalho das funções
*/

/*
Structs 
*/

// Endereço
typedef struct 
{
    char rua[100];
    int numero;
    char complemento[100];
    char bairro[100];
    int cep;
    char cidade[100];
    char estado[100];
    char pais[100];
}Endereco;

// Telefone
typedef struct 
{
    int dd, numero;
}Telefone;

// Data de aniversário
typedef struct 
{
    int dia, mes, ano;
}Data;

// Contato 
typedef struct 
{
    char nome[100];
    char sobrenome[100];
    char email[100];
    Endereco endereco;
    Telefone telefone;
    Data data;
}Contato;

// Estrutura de dados que contem o número de contatos da agenda e a
// lista de contendo todos os contatos
typedef struct 
{
    int num_contatos;
    Contato *lista;
}Agenda;

// Fuções

/*
Função que inicializa a agenda
*/
Agenda* iniciarAgenda();