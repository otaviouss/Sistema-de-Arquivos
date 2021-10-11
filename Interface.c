#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Interface.h"
#include "Particao.h"

void menu() {
    Particao particao;
    char op;
    char caminho[1000];

    char *nomeNovo = (char *) malloc(sizeof(char)*100);
    char *caminhoDestino = (char *) malloc(sizeof(char)*100);
    char conteudo;
    char *nome;

    size_t tamPart;
    size_t tamBloco;

    help();

    printf("Inicializando partição. \n");
    printf("Tamanho da partição: ");
    scanf("%lu", &tamPart);
    printf("Tamanho do bloco: ");
    scanf("%lu", &tamBloco);
    printf("\n\n\n-----------------\n\n\n");

    inicializarParticao(&particao, tamPart, tamBloco);

    printf("Em caso de duvida digite help\n");

    printf("Comando: ");
    scanf("%s", &op);


    while (strcmp(&op, "exit") != 0) {
         nome = (char *) malloc(sizeof(char)*100);

        if(strcmp(&op, "help") == 0) {
            help();
        }else
        if(strcmp(&op, "cd") == 0) {
            printf("Caminho: ");
            scanf("%s", caminho);
            printf("Nome: ");
            scanf("%s", nome);
            criarDiretorioParticao(&particao, caminho, nome);
            mostrarDiretorioParticao(&particao, caminho);
        }else
        if(strcmp(&op, "rd") == 0){
            printf("Caminho: ");
            scanf("%s", caminho);
            printf("Nome: ");
            scanf("%s", nome);
            printf("Nome novo: ");
            scanf("%s", nome);
            renomearItemParticao(&particao,caminho,nome,nomeNovo);
        }else
        if(strcmp(&op, "ad") == 0){
            printf("Caminho: ");
            scanf("%s", caminho);
            printf("Nome: ");
            scanf("%s", nome);
            deletarItemParticao(&particao, caminho, nome);
        }else
        if(strcmp(&op, "ld") == 0){
            printf("Caminho: ");
            scanf("%s", caminho);
            mostrarDiretorioParticao(&particao, caminho);
        }else
        if(strcmp(&op, "ca") == 0){
            printf("Caminho: ");
            scanf("%s", caminho);
            printf("Nome: ");
            scanf("%s", nome);
            printf("Conteudo: ");
            scanf("%s", &conteudo);
            mostrarDiretorioParticao(&particao, caminho);
            mostrarDiretorioParticao(&particao, "/");
            criarArquivoParticao(&particao, caminho, nome, &conteudo);
        }else
        if(strcmp(&op, "ra") == 0){
            printf("Caminho: ");
            scanf("%s", caminho);
            printf("Nome atual: ");
            scanf("%s", nome);
            printf("Nome novo: ");
            scanf("%s", nomeNovo);
            renomearItemParticao(&particao,caminho,nome,nomeNovo);
        }else
        if(strcmp(&op, "aa") == 0){
            printf("Caminho: ");
            scanf("%s", caminho);
            printf("Nome: ");
            scanf("%s", nome);
            deletarItemParticao(&particao, caminho, nome);
        }else
        if(strcmp(&op, "la") == 0){
            printf("Caminho: ");
            scanf("%s", caminho);
            printf("Nome: ");
            scanf("%s", nome);
            mostrarArquivoParticao(&particao, caminho, nome);
        }else
        if(strcmp(&op, "ma") == 0){
            printf("Caminho de Origem: ");
            scanf("%s", caminho);
            printf("Nome: ");
            scanf("%s", nome);
            printf("Caminho de Destino: ");
            scanf("%s", caminhoDestino);
            moverArquivoParticao(&particao, caminho, caminhoDestino, nome);
        }
        free(nome);
        mostrarDiretorioParticao(&particao, caminho);
        printf("Comando: ");
        scanf("%s", &op);


    }



}

void help() {
    printf("Comandos Disponiveis\n");
    printf("cd [caminho] [nome] - Criar Diretorio\n"); // /caminho/home diret
    printf("rd [caminho] [nome atual] [nome novo] - Renomear Diretorio\n");
    printf("ad [caminho] [nome] - Apagar Diretorio\n");
    printf("ld [caminho] - Listar Diretorio\n");
    printf("ca [caminho] [nome] - Criar Arquivo\n");
    printf("ra [caminho] [nome atual] [nome novo] - Renomear Arquivo\n");
    printf("aa [caminho] [nome] - Apagar Arquivo\n");
    printf("la [caminho] [nome] - Listar Arquivo\n");
    printf("ma [caminho origem] [nome] [caminho destino] - Mover Arquivo\n");
}
