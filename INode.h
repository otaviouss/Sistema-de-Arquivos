#ifndef I_NODE_H
#define I_NODE_H

#include <stdio.h>

#include "Data.h"

typedef struct INode SINode;
typedef struct INode {
    Data dataCriacao;
    Data dataModificacao;
    Data dataAcesso;
    int tipo;       // Marcador: 0 se diretório, 1 se arquivo, -1 se na lixeira
    size_t tamanho; // Tamanho apenas dos arquivos
    char* nome;     // Chave Primária Local - Pode ser nome do diretório ou nome do arquivo
    char* conteudo; // Conteúdo do Arquivo
    SINode* lista;  // Lista de Arquivos ou Diretórios no Diretorio atual
    int quantidade; // Quantidade de items no Diretório atual
    int lixeira;    // Quantidade de items deletados
} INode;

void criarDiretorioInicial(INode* inode, char* nome);

void criarDiretorio(INode* inode, char* nome);

void renomearDiretorioAtual(INode* inode, char* nome);

void deletarDiretorio(INode* inode, char* nome);

void listarDiretorio(INode* inode);

void criarArquivo(INode* inode, char* nome, char* conteudo);

void renomearItem(INode* inode, char* nomeAtual, char* novoNome);

void deletarArquivo(INode* inode, char* nome);

void listarArquivo(INode* inode, char* nome);

#endif