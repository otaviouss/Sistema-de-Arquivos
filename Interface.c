#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Interface.h"

void menu() {
    char* op;
    op = "start";

    help();

    while (op != "exit") {
        printf("Em caso de duvida digite help\n");
        scanf(" %s", op);

        if(strcmp(op, "help")) {
            help();
        }
        
        if(op[0]=='c' && op[1]=='d') {
            // Criar Diretório
        }

    }

    return 0;

}

void help() {
    printf("Comandos Disponiveis\n");
    printf("cd [caminho] [nome] - Criar Diretorio\n"); // /caminho/home diret
    printf("rd [caminho] [nome novo] - Renomear Diretorio\n");
    printf("ad [caminho] - Apagar Diretorio\n");
    printf("ld [caminho] - Listar Diretorio\n");
    printf("ca [caminho] [nome] - Criar Arquivo\n");
    printf("ra [caminho] [nome novo] - Renomear Arquivo\n");
    printf("aa [caminho] [nome] - Apagar Arquivo\n");
    printf("la [caminho] [nome] - Listar Arquivo\n");
    printf("ma [caminho origem] [nome] [caminho destino] - Mover Arquivo\n");
}