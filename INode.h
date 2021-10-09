#ifndef I_NODE_H
#define I_NODE_H

#include <stdio.h>

typedef struct INode {
    char dataCriacao[11];
    char horaCricacao[6];
    char dataModificacao[11];
    char horaModificacao[6];
    char dataUAcesso[11];
    char horaUAcesso[6];
    size_t tamanho; // Tamanho apenas dos arquivos
    char* nome; // Chave Primária Local - Pode ser nome do diretório ou nome do arquivo
    char* conteudo; // Conteúdo do Arquivo
    struct Inode* lista; // Lista de Arquivos no Diretorio
} INode;

void criarDiretorio(INode* inode, char* nome);

void renomearDiretorio(INode* inode, char* nome);

void deletarDiretorio(INode* inode, char* nome);

void listarDiretorio(INode* inode);

void criarArquivo(INode* inode, char* nome, char* conteudo);

void renomearArquivo(INode* inode, char* nome);

void deletarArquivo(INode* inode, char* nome);

void listarArquivo(INode* inode);

void moverArquivo(INode* inode, char* caminho);

void getDataAtual(char data[]);

#endif