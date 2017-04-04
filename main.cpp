
#include "liga.h"

void limpaBuf(){
    cin.clear();
    cin.sync();
    fflush(stdin);
}

int main()
{
    bool sair = true;
    int opc = 0;
    int *ptr_menu = &opc;

    /** Struct Cliente **/
    cliente * db_cli;
        int     id_cli;
        int     cargo;
        char    nome_cli[101];
        char    email[255];
        char    sexo;
        int     estado;
    db_cli = NULL;

    /** Struct Projeto **/
    projeto * db_pro;
        int     id_pro;
        int     aprovado;
        char    nome_pro[101];
        char    data_comeco[101];
        char    data_final[101];
    db_pro = NULL;

    char *ptr_sexo = &sexo;

    do{
        switch(*ptr_menu){

            //Gerir Clientes
            case 1:
                *ptr_menu = 0; //Preciso de colocar o *ptr_menu novamente a 0 para ele poder entrar no switch de dentro!
                do{
                    switch(*ptr_menu){
                        case 1: //Adicionar Cliente
                            getDataCliente(nome_cli, email, ptr_sexo);
                            addCliente(&db_cli, nome_cli, email, ptr_sexo);
                            *ptr_menu = 0;
                            break;
                        case 2: //Listar Clientes
                            getClienteInfo(&db_cli);
                            *ptr_menu = 0;
                            break;
                        case 3: //Editar Cliente
                            *ptr_menu = 0;
                            break;
                        case 4: //Remover Cliente
                            removeCliente(&db_cli);
                            *ptr_menu = 0;
                            break;
                        default:
                            printf("\n\t\tGere Clientes %1.1f\n\n", VERSION);
                            printf("\n\tMenu:");
                            printf("\n\t\t1 - Adicionar Cliente");
                            printf("\n\t\t2 - Listar Clientes");
                            printf("\n\t\t3 - Editar Cliente");
                            printf("\n\t\t4 - Remover Cliente");
                            printf("\n\t\t5 - Voltar ao Menu anterior");
                            printf("\n\t-> ");
                            scanf("%d", ptr_menu);
                            limpaBuf();
                    }
                }while(*ptr_menu <= 4);
                *ptr_menu = 0;
                break;

            //Gerir Projetos
            case 2:
                break;
            case 3: //Terminar Programa
                sair = false;
                break;
            default:
                printf("\n\t\tGestor de Projetos %1.1f\n\n", VERSION);
                printf("\n\tMenu:");
                printf("\n\t\t1 - Gerir Clientes");
                printf("\n\t\t2 - Gerir Projetos");
                printf("\n\t\t3 - Terminar Programa");
                printf("\n\t-> ");
                scanf("%d", ptr_menu);
                limpaBuf();
        }
    }while(sair);

    return 0;
}
