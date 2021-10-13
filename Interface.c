#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Interface.h"
#include "Particao.h"
#include "GerenciadorDeArquivos.h"

void menu() {
    Particao particao;
    size_t tamPart, tamBloco;
    int exe;

    printf("\n\n--- Configuracoes Iniciais ---\n\n");
    printf("Inicializando particao \n");
    printf("Tamanho da particao: ");
    scanf("%lu", &tamPart);
    printf("Tamanho do bloco: ");
    scanf("%lu", &tamBloco);
    printf("\n--------------------------------\n");

    inicializarParticao(&particao, tamPart, tamBloco);

    printf("\n\n--- Forma de Execucao ---\n\n");
    printf("1. Execucao Manual\n");
    printf("2. Execucao por Arquivo\n");
    scanf("%d", &exe);
    printf("\n----------------------------\n\n");
    
    if(exe == 1) {
        execucaoManual(particao);
    } else if(exe == 2) {
        execucaoAutomatica(particao);
    }
    printf("\nFinalizar!\n\n");

}

void help() {
    printf("\nComandos Disponiveis\n");
    printf("---------------------------------------------------------------------\n");
    printf("|      Operacao      |                   Comando                    |\n");
    printf("|--------------------|----------------------------------------------|\n");
    printf("|    Criar Diretorio | cd [caminho] [nome]                          |\n");
    printf("| Renomear Diretorio | rd [caminho] [nome atual] [nome novo]        |\n");
    printf("|   Apagar Diretorio | ad [caminho] [nome]                          |\n");
    printf("|   Listar Diretorio | ld [caminho]                                 |\n");
    printf("|      Criar Arquivo | ca [caminho] [nome arquivo real]             |\n");
    printf("|   Renomear Arquivo | ra [caminho] [nome atual] [nome novo]        |\n");
    printf("|     Apagar Arquivo | aa [caminho] [nome]                          |\n");
    printf("|     Listar Arquivo | la [caminho] [nome]                          |\n");
    printf("|      Mover Arquivo | ma [caminho origem] [nome] [caminho destino] |\n");
    printf("|              Ajuda | help                                         |\n");
    printf("|               Sair | exit                                         |\n");
    printf("---------------------------------------------------------------------\n");
}

void execucaoManual(Particao particao) {
    char *descricao, *nome, *nomeNovo;
    char op[10], caminho[100], caminhoDestino[100];

    help();

    printf("Comando: ");
    scanf("%s", op);

    while (strcmp(op, "exit") != 0) {
         nome = (char *) malloc(sizeof(char)*100);

        if(strcmp(op, "help") == 0) {
            help();
        }else
        if(strcmp(op, "cd") == 0) {
            printf("Caminho: ");
            scanf("%s", caminho);
            printf("Nome: ");
            scanf("%s", nome);
            printf("\n");
            criarDiretorioParticao(&particao, caminho, nome);
        }else
        if(strcmp(op, "rd") == 0 || strcmp(op, "ra") == 0){
            nomeNovo = (char *) malloc(sizeof(char)*100);
            printf("Caminho: ");
            scanf("%s", caminho);
            printf("Nome: ");
            scanf("%s", nome);
            printf("Nome novo: ");
            scanf("%s", nomeNovo);
            printf("\n");
            renomearItemParticao(&particao, caminho, nome, nomeNovo);
            free(nomeNovo);
        }else
        if(strcmp(op, "ad") == 0){
            printf("Caminho: ");
            scanf("%s", caminho);
            printf("Nome: ");
            scanf("%s", nome);
            printf("\n");
            deletarItemParticao(&particao, caminho, nome);
        }else
        if(strcmp(op, "ld") == 0){
            printf("Caminho: ");
            scanf("%s", caminho);
            printf("\n");
            mostrarDiretorioParticao(&particao, caminho);
        }else
        if(strcmp(op, "ca") == 0){
            descricao = (char*) calloc(10000, sizeof(char));
            printf("Caminho: ");
            scanf("%s", caminho);
            printf("Nome do arquivo real (Com extensao): ");
            scanf("%s", nome);
            //printf("Descricao: ");
            //scanf("%s", descricao);
            lerArquivo(nome, descricao);
            printf("D: %s\n", descricao);
            printf("\n");
            criarArquivoParticao(&particao, caminho, nome, descricao);
            free(descricao);
        }else
        if(strcmp(op, "aa") == 0){
            printf("Caminho: ");
            scanf("%s", caminho);
            printf("Nome: ");
            scanf("%s", nome);
            printf("\n");
            deletarItemParticao(&particao, caminho, nome);
        }else
        if(strcmp(op, "la") == 0){
            printf("Caminho: ");
            scanf("%s", caminho);
            printf("Nome: ");
            scanf("%s", nome);
            printf("\n");
            mostrarArquivoParticao(&particao, caminho, nome);
        }else
        if(strcmp(op, "ma") == 0){
            printf("Caminho de Origem: ");
            scanf("%s", caminho);
            printf("Nome: ");
            scanf("%s", nome);
            printf("Caminho de Destino: ");
            scanf("%s", caminhoDestino);
            printf("\n");
            moverArquivoParticao(&particao, caminho, caminhoDestino, nome);
        }else
        if(strcmp(op, "exit") == 0) {
            free(nome);
            return;
        } else {
            printf("Comando inexistente! Veja os comandos Disponiveis:\n");
            help();
        }

        free(nome);
        printf("\nComando: ");
        scanf("%s", op);

    }
}

void execucaoAutomatica(Particao particao) {
    char *nome, *descricao;
    Instrucao *inst;
    int n, i;
    
    nome = (char *) malloc(sizeof(char)*100);

    printf("Nome do Arquivo (Com extensao): ");
    scanf("%s", nome);

    lerArquivoInstrucoes(nome, &inst, &n);

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
            descricao = (char*) malloc(10000 * sizeof(char));
            lerArquivo(inst[i].nome1, descricao);
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