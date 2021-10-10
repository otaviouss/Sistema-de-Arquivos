#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Particao.h"
#include "INode.h"

void inicializarParticao(Particao *particao, size_t TamParticao, size_t TamBloco){
    INode inode;

    // Define os tamanhos de bloco e partição
    particao->bloco = (size_t)TamBloco;
    particao->particao = (size_t)TamParticao;
    particao->ocupado = 0;

    // Cria diretório raiz (todos os demais diretórios e arquivos deverão estar dentro deste)
    criarDiretorioInicial(&inode, "/");

    particao->raiz = inode;
}

// Exemplo de caminho: /DIR1/DIR2/DIR3/teste.txt
void percorrerCaminho(Particao* particao, char* caminho, INode** inode, char** nome) {
    INode* ajudante;
    int i = 0, j = 0, cont = 0;
    char help[100];
    int flag;

    // strcpy(cam, caminho);
    
    // cam[strlen(caminho)] = '/';
    // cam[strlen(caminho)+1] = '\0';

    // printf("C: %s\n", cam);

    if(caminho[0] != '/') {
        printf("Diretorio raiz é /\n");
        return;
    }

    ajudante = &particao->raiz;

    for(i=1;i<strlen(caminho);i++) {
        if(caminho[i]!='/') {
            help[cont] = caminho[i];
            help[cont+1] = '\0';
            cont++;
            (*nome) = help;
        } else {
            flag = 0;
            for(j = 0; j<ajudante->quantidade; j++) {
                if(strcmp(ajudante->lista[j].nome, help) == 0) {
                    ajudante = &ajudante->lista[j];
                    flag = 1;
                    break;
                }
            }
            
            if(flag==0) {
                printf("Diretorio %s nao encontrado.\n", help);
                return;
            }

            cont = 0;
        }
    }

    (*inode) = ajudante;

    

    printf("N: %s\n", (*nome));

    // (*nome) = "Valor";

    printf("N: %s\n", (*nome));

    printf("Diretorio encontrado!\n");
}

// /Home/Teste.txt -> /Home/ICC
void moverArquivoParticao(Particao* particao, char* caminhoOrigem, char* caminhoDestino) {
    INode *iNodeOrigem, *iNodeDestino;
    //char** nome;

    //percorrerCaminho(particao, caminhoOrigem, &iNodeOrigem, &nome);
    //percorrerCaminho(particao, caminhoDestino, &iNodeDestino, &nome);

    criarArquivo(iNodeDestino, iNodeOrigem->nome, iNodeOrigem->conteudo);


}