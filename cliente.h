
void getDataCliente(char cli_nome[], char cli_email[], char *cli_sexo){
    bool val = true;
    bool *ptr_val = &val;

    do{
        printf("Nome: ");
        scanf("%s", cli_nome);
        limpaBuf();
        if(cli_nome[0] == ' '){
            *ptr_val = true;
        }else {
            *ptr_val = false;
        }
    }while(*ptr_val);

    /** Volta a true para poder fazer a proxima validação **/
    *ptr_val = true;

    do{
        printf("Email: ");
        scanf("%s", cli_email);
        limpaBuf();
        if(cli_email[0] == ' '){
            *ptr_val = true;
        }else {
            *ptr_val = false;
        }
    }while(*ptr_val);

    *ptr_val = true;

    do{
        printf("Sexo: ");
        fflush(stdin);
        scanf("%c", cli_sexo);
        limpaBuf();
        if(cli_sexo == NULL){
            *ptr_val = true;
        }else {
            *ptr_val = false;
        }
    }while(*ptr_val);


    //cout<<cli_nome<<endl<<cli_email<<endl<<cli_sexo<<endl;
}

void addCliente(cliente ** db_cli, char cli_nome[], char cli_email[], char *cli_sexo){
    cliente * db_cliente;
    FILE * arq_cli;

    db_cliente = (cliente *) malloc(sizeof(cliente)); // aloca memoria para o apontador de estrutura
    db_cliente->id = ct_cli;
    db_cliente->cargo = 1;
    strcpy(db_cliente->nome, cli_nome);
    strcpy(db_cliente->email, cli_email);
    db_cliente->sexo = *cli_sexo;
    db_cliente->estado = 1;
    db_cliente->next=*db_cli;
    *db_cli=db_cliente;

    if((arq_cli = fopen("db_cliente.bin", "ab+")) != NULL) {
        printf("\n Aguarda...");
        fwrite(&db_cliente, sizeof(db_cliente), 1, arq_cli);
        fclose(arq_cli);
        printf("\nCliente inserido!\n\n");
    }else {
        printf("O arquivo nao pode ser aberto");
    }

    ct_cli++;
}

void getClienteInfo(cliente ** db_cli){

    cliente * db_cliente;

    FILE * arq_cli;

    fflush(stdin);

    arq_cli = fopen("db_cliente.bin", "rb+");
    if(arq_cli == NULL) {
        printf("Erro ao abrir o arquivo!");
        getch();
        return;
    }else{
        rewind(arq_cli);
        db_cliente = (cliente *) malloc(sizeof(cliente));
        fread(&db_cliente, sizeof(db_cliente), 1, arq_cli);
        while(!feof(arq_cli)){
            printf("ID: %d", db_cliente->id);
            fread(&db_cliente, sizeof(db_cliente), 1, arq_cli);
            db_cliente->next = *db_cli;
            *db_cli = db_cliente;
        }
        fclose(arq_cli);
    }

}

/** Este getClienteInfo mostra apenas o que a struct contem
void getClienteInfo(cliente * db_cli){
    cliente * db_cliente;
    db_cliente = db_cli;

    if(db_cliente == NULL){
        printf("Nao existem clientes!");
    }else{
        while(db_cliente != NULL){
            printf("\nID %d\n", db_cliente->id);
            printf("\nCargo %d\n", db_cliente->cargo);
            printf("\nNome %s\n", db_cliente->nome);
            printf("\nEmail %s\n", db_cliente->email);
            printf("\nSexo %c\n", db_cliente->sexo);
            printf("\nEstado %d\n", db_cliente->estado);
            db_cliente = db_cliente->next;
        }
    }
}
**/

void removeCliente(cliente ** db_cli){
    cliente * anterior = NULL;
    cliente * db_cliente;
    db_cliente = *db_cli;

    int cod;

    printf("Digite o codigo:");
    scanf("%d", &cod);
    if(db_cliente == NULL) {
        printf("Nao existem clientes!");
    } else {
        while(db_cliente != NULL) {
            if(cod == db_cliente->id){
                if (anterior==NULL){
                    *db_cli = db_cliente->next;
                    free(db_cliente);
                }else{
                    anterior->next=db_cliente->next;
                    free(db_cliente);
                }
                ct_cli--;
                return;
            }else{
                anterior=db_cliente;
                db_cliente=db_cliente->next;
            }
        }
    }

}
