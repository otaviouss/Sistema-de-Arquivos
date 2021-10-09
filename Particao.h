#ifndef PARTICAO_H
#define PARTICAO_H

#include <stdio.h>

#include "INode.h"

typedef struct {
    size_t particao; // Intervalo: 100-200
    size_t bloco;
    size_t ocupado;
    INode raiz;
} Particao;

void moverArquivoParticao(Particao* particao, char* caminhoOrigem, char* caminhoDestino);

void percorrerCaminho(Particao* particao, char* caminho, INode* inode);

void setTamanhoParticaoEBloco(Particao *particao, int TamParticao, int TamBloco);

#endif