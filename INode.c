#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "INode.h"

void criarDiretorio(INode* inode, char* nome){
    time_t rawtime;
    struct tm *timeinfo = localtime(&rawtime);

    inode = (INode*)malloc(sizeof(INode));
    strcpy(inode->nome, nome);
    inode->lista = NULL;
    inode->tamanho = 0;
    //data
    inode->conteudo = null;
    //inode->dataModificacao
    //inode->dataUAcesso
    //inode->horaCricacao;
    //inode->horaModificacao
    //inode->horaUAcesso
}

void renomearDiretorio(INode* inode, char* nome){
    strcpy(inode->nome, nome);
}

void deletarDiretorio(INode* inode, char* nome){
    if()
}

void listarDiretorio(INode* inode){

}

void criarArquivo(INode* inode, char* nome, char* conteudo){

}

void renomearArquivo(INode* inode, char* nome){

}

void deletarArquivo(INode* inode, char* nome){

}

void listarArquivo(INode* inode){

}

void moverArquivo(INode* inode, char* caminho){

}

void getDataAtual(char data[11]){
    time_t rawtime = time(NULL);
    char result[5];
    struct tm *timeinfo = localtime(&rawtime);

    for(int i = 0; i < 11; i++){
        data[i] = '\0';
    }

    sprintf(result, "%d", timeinfo->tm_mday);

    strcpy(data, result);
    data[2] = '/';

    sprintf(result, "%d", timeinfo->tm_mon+1);
    data[3] = result[0];
    data[4] = result[1];
    data[5] = '/';
    sprintf(result, "%d", timeinfo->tm_year+1900);
    data[6] = result[0];
    data[7] = result[1];
    data[8] = result[2];
    data[9] = result[3];

}