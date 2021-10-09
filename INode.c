#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "INode.h"

void criarDiretorio(INode* inode, char* nome){
    // Variáveis necessárias para ver horario atual
    time_t rawtime = time(NULL);
    struct tm *timeinfo = localtime(&rawtime);

    // Definindo o nome do novo diretório
    strcpy(inode->nome, nome);

    // Definindo lista de arquivos do diretório como vazia
    inode->lista = NULL;

    // Definindo tamanho inicial ocupado pelo diretório
    inode->tamanho = 0;
    
    // Definindo data atual
    setData(&(inode->dataCriacao), timeinfo->tm_mday, timeinfo->tm_mon, timeinfo->tm_year, 
                timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
    
    // Definindo data da última modificação (Data atual)
    setData(&(inode->dataModificacao), timeinfo->tm_mday, timeinfo->tm_mon, timeinfo->tm_year, 
                timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
    
    // Definindo data do último acesso (Data Atual)
    setData(&(inode->dataAcesso), timeinfo->tm_mday, timeinfo->tm_mon, timeinfo->tm_year, 
                timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
    
    // Definindo conteúdo como vazio inicialmente
    inode->conteudo = NULL;
}

void renomearDiretorio(INode* inode, char* nome){
    strcpy(inode->nome, nome);
}

void deletarDiretorio(INode* inode, char* nome){

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