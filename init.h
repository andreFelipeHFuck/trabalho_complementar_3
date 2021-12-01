#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdio_ext.h>

/*
Trabalho complementar 3
Arquivo com as estruturas de dados e com as funções
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

// Pessoa 
typedef struct 
{
    char nome[100];
    char email[100];
    Endereco endereco;
    Telefone telefone;
    Data data;
}Pessoa;


