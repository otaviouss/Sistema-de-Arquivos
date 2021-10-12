#ifndef GERENCIADOR_H
#define GERENCIADOR_H

typedef struct {
    char comando[3];
    char caminho1[1000];
    char caminho2[1000];
    char nome1[101];
    char nome2[101];
} Instrucao;

void lerArquivoInstrucoes(char* nome, Instrucao** inst);

void lerArquivo(char* nome, char descricao[]);

#endif