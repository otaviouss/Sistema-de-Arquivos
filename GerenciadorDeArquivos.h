#ifndef GERENCIADOR_H
#define GERENCIADOR_H

#include<stdio.h>

#include "Particao.h"

typedef struct {
    Particao particao;
} GerenciadorDeArquivos;

void lerArquivo(GerenciadorDeArquivos* gArquivo, char* nome, char* caminho);

#endif