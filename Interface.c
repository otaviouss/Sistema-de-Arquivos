#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Interface.h"
#include "Particao.h"
#include "GerenciadorDeArquivos.h"

void menu() {
    Particao particao;
    char op, *descricao;
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
            printf("Nome do arquivo real (Com extensao): ");
            scanf("%s", nome);
            lerArquivo(nome, &descricao);
            printf("D: %s\n", descricao);
            criarArquivoParticao(&particao, caminho, nome, descricao);
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
    printf("ca [caminho] [nome arquivo real] - Criar Arquivo\n");
    printf("ra [caminho] [nome atual] [nome novo] - Renomear Arquivo\n");
    printf("aa [caminho] [nome] - Apagar Arquivo\n");
    printf("la [caminho] [nome] - Listar Arquivo\n");
    printf("ma [caminho origem] [nome] [caminho destino] - Mover Arquivo\n");
}

void execucaoAutomatica() {
    Particao particao;
    char *nome, *descricao;
    Instrucao *inst;
    size_t n, i;

    printf("Nome do Arquivo (Com extensao): ");
    scanf("%s", nome);

    nome[strlen(nome)-1] = '\0';

    //lerArquivoInstrucoes(nome, &inst);

    n = sizeof(inst)/sizeof(inst[0]);

    printf("Tam: %d\n", n);

    for(i = 0; i<n; i++) {
        if(strcmp(inst[i].comando, "cd") == 0) {
            criarDiretorioParticao(&particao, inst[i].caminho1, inst[i].nome1);
        }else
        if(strcmp(inst[i].comando, "rd") == 0){
            renomearItemParticao(&particao, inst[i].caminho1, inst[i].nome1, inst[i].nome2);
        }else
        if(strcmp(inst[i].comando, "ad") == 0){
            deletarItemParticao(&particao, inst[i].caminho1, inst[0].nome1);
        }else
        if(strcmp(inst[i].comando, "ld") == 0){
            mostrarDiretorioParticao(&particao, inst[i].caminho1);
        }else
        if(strcmp(inst[i].comando, "ca") == 0){
            lerArquivo(inst[i].nome1, &descricao);
            criarArquivoParticao(&particao, inst[i].caminho1, inst[i].nome1, descricao);
        }else
        if(strcmp(inst[i].comando, "ra") == 0){
            renomearItemParticao(&particao, inst[i].caminho1, inst[i].nome1, inst[i].nome2);
        }else
        if(strcmp(inst[i].comando, "aa") == 0){
            deletarItemParticao(&particao, inst[i].caminho1, inst[i].nome1);
        }else
        if(strcmp(inst[i].comando, "la") == 0){
            mostrarArquivoParticao(&particao, inst[i].caminho1, inst[i].nome1);
        }else
        if(strcmp(inst[i].comando, "ma") == 0){
            moverArquivoParticao(&particao, inst[i].caminho1, inst[i].caminho2, inst[i].nome1);
        }
    }

    

}