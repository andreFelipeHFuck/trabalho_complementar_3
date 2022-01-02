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

/*
Escreve os dados no arquivo binário
*/
void escreverArquivo(Agenda *agenda);

/*
Insere os dados de um novo contato
Dados:
+ Nome, sobrenome, email
+ Data de nascimento: dia, mes, ano
+ Endereço: rua, numero, complemento, bairro, cep, cidade, estdo, pais
*/
void insereContato(Agenda *agenda);

/*
Imprime na tela o dados de todos os contatos
*/
void mostrarConstatos(Agenda *agenda);

/*
Revome os dados de um contato
*/
void removerContato(Agenda *agenda);

/*
Menu
*/
void menu(int *opt);

/*
Busca os dados dos contatos a partir do nome
*/
void buscaNome(Agenda *agenda);

/*
Busca os aniversariantes por dia ou por mes
*/
void aniversariantes(Agenda *agenda);