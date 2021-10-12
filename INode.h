#ifndef I_NODE_H
#define I_NODE_H

#include <stdio.h>

#include "Data.h"

typedef struct Celula* Apontador;
typedef struct INode SINode;

typedef struct INode {
    Data dataCriacao;
    Data dataModificacao;
    Data dataAcesso;
    int tipo;       // Marcador: 0 se diretório, 1 se arquivo
    size_t tamanho; // Tamanho apenas dos arquivos
    char* nome;     // Chave Primária Local - Pode ser nome do diretório ou nome do arquivo
    char* conteudo; // Conteúdo do Arquivo
    Apontador pPrimeiro; // Lista de Arquivos ou Diretórios no Diretorio atual
    int quantidade; // Quantidade de items no Diretório atual
} INode;

typedef struct Celula {
    SINode inode;
    struct Celula* pProx;
} Celula;

void criarDiretorioInicial(INode* inode, char* nome);

void criarDiretorio(INode* inode, char* nome);

void renomearDiretorioAtual(INode* inode, char* nome);

void listarDiretorio(INode* inode);

void criarArquivo(INode* inode, char* nome, char* conteudo);

void renomearItem(INode* inode, char* nomeAtual, char* novoNome);

int deletarItem(INode* inode, char* nome);

void deletarArquivoINode(INode* inode);

void listarArquivo(INode* inode, char* nome);

void listarArquivoINode(INode* inode);

// Operações para lidar com a lista de arquivos

void FLVazia(INode* lista);

int LehVazia(INode* lista);

void InsereINode(INode* lista, INode inode);

int RetiraINode(INode* lista, char* nome);

int BuscarINode(INode* lista, char* nome, INode* inode);

int RenomearINode(INode* lista, char* nomeAntigo, char* nomeNovo);

int ImprimeArquivo(INode* lista, char* nome);

int RetornaConteudoArquivo(INode* lista, char* nome, char** conteudo);

void ImprimeLista(INode* lista);

#endif