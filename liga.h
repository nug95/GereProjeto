
#ifndef LIGA
#define LIGA
#define VERSION 0.1

using namespace std;

int ct_cli = 0; //Contador de Clientes Global
int ct_pro = 0; //Contador de Projetos Global

typedef struct cliente {
    int     id;
    int     cargo; //1- cliente, 2 - tem alguns direitos, 3 - administrador total
    char    nome[101];
    char    email[255];
    char    sexo;
    int     estado; //1- desativado , 2 - activado
    struct  cliente * next;
} cliente;

typedef struct projeto {
    int     id;
    int     aprovado; //1- nao aprovado , 2 - aprovado
    char    nome[101];
    char    data_comeco[101];
    char    data_final[101];
    struct  projeto * next;
    struct  cliente db_cliente;
} projeto;

void removeCliente(cliente ** db_cli);
void getClienteInfo(cliente * db_cli);
void addCliente(cliente ** db_cli, char cli_nome[], char cli_email[], char *cli_sexo);
void getDataCliente(char cli_nome[], char cli_email[], char *cli_sexo);
void limpaBuf();

/** Bibliotecas **/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdio.h>
/** Headers **/
#include "cliente.h"

#endif // LIGA
