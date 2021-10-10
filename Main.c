#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <Windows.h>

#include "Interface.h"
#include "INode.h"
#include "Data.h"
#include "Particao.h"

void teste(char** str) {
    (*str) = "Qualquer  coisa";

    printf("T: %s\n", (*str));
}

int main() {
    INode* inode, *in;
    char* nome;
    Particao particao;
    //menu();

    teste(&nome);
    printf("T: %s\n", nome);
    
    // Testando Particao

    /*char* c = "/Home/OC/TP3/arquivo.txt";
    char* help = NULL;
    int i, cont=0;

    for(i=0;i<strlen(c);i++) {
        if(c[i]!='/') {
            help = (char*) realloc(help, sizeof(char));
            
            help[cont] = c[i];
            help[cont+1] = '\0';

            cont++;
        } else {
            printf("%s\n", help);
            cont = 0;
            help = NULL;
        }
    }*/
    
    inicializarParticao(&particao, 1000, 20);

    criarDiretorio(&(particao.raiz), "Home");

    criarDiretorio(&particao.raiz, "ICC");

    listarDiretorio(&particao.raiz);

    percorrerCaminho(&particao, "/ICC/", &inode, &nome);

    // listarDiretorio(inode);

    criarDiretorio(inode, "SEINAO");
    
    criarDiretorio(inode, "IC");
    
    criarArquivo(inode, "Teste.txt", "Alguma coisa");

    listarDiretorio(inode);

    percorrerCaminho(&particao, "/ICC/Teste.txt", &in, &nome);

    printf("\n\n");

    printf("A");
    printf("%s", nome);

    // listarDiretorio(inode);

    listarArquivo(in, nome);

    return 0;

}