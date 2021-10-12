#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "GerenciadorDeArquivos.h"

//void lerArquivoInstrucoes(char* nome, Instrucao** inst) {
//    FILE *arq;
//    char temp[1000];
//    int count = 0, numLinha = 0, numInst = 0;
//
//    arq = fopen(nome, "r");
//    if(arq == NULL) {
//        printf("Arquivo não encontrado.\n");
//        return;
//    }
//
//    while (!feof(arq)) {
//        fgets(temp, 1000, arq);
//        ++numLinha;
//    }
//
//    rewind(arq);
//
//    (*inst) = (Instrucao*) malloc(numLinha*sizeof(Instrucao));
//
//    while(!feof(arq)) {
//        fscanf(arq, "%s", temp);
//        if(count == 0) {
//            strcpy((*inst)[numInst].comando, temp);
//        } else if(count == 1) {
//            strcpy((*inst)[numInst].caminho1, temp);
//            if(strcmp((*inst)[numInst].comando, "ld") == 0) {
//                count = -1;
//                numInst++;
//            }
//        } else if(count == 2) {
//            strcpy((*inst)[numInst].nome1, temp);
//            if( strcmp((*inst)[numInst].comando, "cd") == 0 ||
//                strcmp((*inst)[numInst].comando, "ad") == 0 ||
//                strcmp((*inst)[numInst].comando, "ca") == 0 ||
//                strcmp((*inst)[numInst].comando, "aa") == 0 ||
//                strcmp((*inst)[numInst].comando, "la") == 0) {
//                    count = -1;
//                    numInst++;
//                }
//        } else if(count == 3) {
//            if(strcmp((*inst)[numInst].comando, "rd") == 0) {
//                strcpy((*inst)[numInst].nome2, temp);
//            } else if(strcmp((*inst)[numInst].comando, "ma") == 0) {
//                strcpy((*inst)[numInst].caminho2, temp);
//            }
//            count = -1;
//            numInst++;
//        }
//        count++;
//    }
//    fclose(arq);
//}

void lerArquivo(char* nome, char descricao[]) {
    FILE *arq;
    char temp[100];
    int cont = 0;
    
    //(*descricao) = (char*) calloc(sizeof(char), 10000);

    arq = fopen(nome, "r");
    if(arq == NULL) {
        printf("Arquivo não encontrado.\n");
        fclose(arq);
        return;
    }

    while(!feof(arq)) {
        fscanf(arq, "%s", temp);
        strcat(descricao, temp);
        strcat(descricao, " ");
    }
    
    /*
    char caracter;
    while(!feof(arq)){

        caracter = fgetc(arq);

        if(caracter == '\0') break;
        descricao[cont] = caracter;
        cont++;
    }
    printf("%d", cont);
    */
    fclose(arq);

}