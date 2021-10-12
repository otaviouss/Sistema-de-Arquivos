#ifndef PARTICAO_H
#define PARTICAO_H

#include <stdio.h>

#include "INode.h"

typedef struct {
    size_t particao; // Intervalo: 1000-10000 | Deve estar em bytes
    size_t bloco;    // Deve estar em bytes
    size_t ocupado;  // Deve estar em bytes
    INode raiz;
} Particao;

void inicializarParticao(Particao *particao, size_t TamParticao, size_t TamBloco);

void percorrerCaminho(Particao* particao, char* caminho, INode** inode);

void moverArquivoParticao(Particao* particao, char* caminhoOrigem, char* caminhoDestino, char* nome);

void criarDiretorioParticao(Particao* particao, char* caminho, char* nome);

void criarArquivoParticao(Particao* particao, char* caminho, char* nome, char* conteudo);

void deletarItemParticao(Particao* particao, char* caminho, char* nome);

void renomearItemParticao(Particao* particao, char* caminho, char* nomeAtual, char* novoNome);

void mostrarArquivoParticao(Particao* particao, char* caminho, char* nome);

void mostrarDiretorioParticao(Particao* particao, char* caminho);

#endif