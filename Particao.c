#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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

// Exemplo de caminho: /DIR1/DIR2/DIR3
void percorrerCaminho(Particao* particao, char* caminho, INode** inode, char** nome) {
    char cam[100];
    INode* ajudante;
    int i = 0, j = 0, cont = 0;
    char help[100];

    int flag;

    strcpy(cam, caminho);
    if(caminho[strlen(caminho)-1] != '/') {
        cam[strlen(caminho)] = '/';
        cam[strlen(caminho)+1] = '\0';
    }

    if(caminho[0] != '/') {
        printf("Diretorio raiz é /\n");
        return;
    }

    ajudante = (INode*) malloc(sizeof(INode));

    *ajudante = particao->raiz;

    for(i=1;i<strlen(cam);i++) {
        if(cam[i]!='/') {
            help[cont] = cam[i];
            help[cont+1] = '\0';
            cont++;
            strcpy((*nome), help);
        } else {
            flag = BuscarINode(ajudante, help, ajudante);
            
            if(flag==0 || flag==-1) {
                printf("Diretorio %s nao encontrado.\n", help);
                return;
            }

            cont = 0;
        }
    }

    (*inode) = ajudante;

    // if(ajudante->tipo == 0) printf("Diretorio %s encontrado!\n", ajudante->nome);
    // else                    printf("Arquivo %s encontrado!\n", *nome);
}

void moverArquivoParticao(Particao* particao, char* caminhoOrigem, char* caminhoDestino, char* nome) {
    INode *iNodeOrigem, *iNodeDestino;
    char *n, *conteudo;
    
    n = (char*) malloc(100*sizeof(char));
    conteudo = (char*) malloc(1000*sizeof(char));
    
    percorrerCaminho(particao, caminhoDestino, &iNodeDestino, &n);
    percorrerCaminho(particao, caminhoOrigem, &iNodeOrigem, &n);

    RetornaConteudoArquivo(iNodeOrigem, nome, &conteudo);

    criarArquivo(iNodeDestino, nome, conteudo);

    deletarItem(iNodeOrigem, nome);

    printf("Arquivo Movido com Sucesso!\n");
}

void criarDiretorioParticao(Particao* particao, char* caminho, char* nome) {
    INode* inode;
    char* n;
    char *nome2 = (char*) malloc(sizeof(nome) + 1);
    size_t tam;

    strcpy(nome2, nome);
    
    n = (char*) malloc(100*sizeof(char));

    percorrerCaminho(particao, caminho, &inode, &n);

    criarDiretorio(inode, nome2);

    tam = sizeof(inode);

    tam = (size_t)((float) tam / (float) particao->bloco);
    tam *= particao->bloco;

    // Testando se estourou o espaço livre.
    if(tam+particao->ocupado > particao->particao) {
        deletarItem(inode, nome2);
        printf("Particao Cheia. Impossivel criar o diretorio.");
        return;
    }

    particao->ocupado += tam;

    printf("Diretorio Criado com Sucesso!\n");
}

void criarArquivoParticao(Particao* particao, char* caminho, char* nome, char* conteudo) {
    INode* inode;
    char* n = (char*) malloc(100*sizeof(char));
    size_t tam;

    char *nome2 = (char*) malloc(sizeof(nome) + 1);
    char *conteudo2 = (char*) malloc(sizeof(conteudo) + 1);

    strcpy(nome2, nome);
    strcpy(conteudo2, conteudo);

    printf("Z\n");

    percorrerCaminho(particao, caminho, &inode, &n);

    printf("A\n");

    criarArquivo(inode, nome2, conteudo2);

    printf("B\n");

    tam = sizeof(inode);

    tam = (size_t)((float) tam / (float) particao->bloco);
    tam *= particao->bloco;

    printf("C\n");

    // Testando se estourou o espaço livre.
    if(tam+particao->ocupado > particao->particao) {
        deletarItem(inode, nome2);
        printf("Particao Cheia. Impossivel inserir o arquivo.");
        return;
    }

    printf("D\n");

    particao->ocupado += tam;

    printf("Arquivo Criado com Sucesso!\n");
}

void deletarItemParticao(Particao* particao, char* caminho, char* nome) {
    INode* inode;
    char* n;
    size_t tam;
    
    n = (char*) malloc(100*sizeof(char));

    percorrerCaminho(particao, caminho, &inode, &n);

    tam = sizeof(inode);

    if(deletarItem(inode, nome) == 1) {
        tam = (size_t )((float) tam / (float) particao->bloco);
        tam *= particao->bloco;

        particao->ocupado -= tam;

        printf("Item Deletado com Sucesso!\n");
    } else {
        printf("Nao foi possivel deletar.\n");
    }

    
}

void renomearItemParticao(Particao* particao, char* caminho, char* nomeAtual, char* novoNome) {
    INode* inode;
    char* n;
    size_t tam;

    char *nome = (char*) malloc(sizeof(novoNome) + 1);

    strcpy(nome, novoNome);
    
    n = (char*) malloc(100*sizeof(char));

    percorrerCaminho(particao, caminho, &inode, &n);

    renomearItem(inode, nomeAtual, nome);

}

void mostrarArquivoParticao(Particao* particao, char* caminho, char* nome) {
    INode* inode;
    char* n;
    size_t tam;
    
    n = (char*) malloc(100*sizeof(char));

    percorrerCaminho(particao, caminho, &inode, &n);

    listarArquivo(inode, nome);
}

void mostrarDiretorioParticao(Particao* particao, char* caminho) {
    INode* inode;
    char* n;
    size_t tam;
    
    n = (char*) malloc(100*sizeof(char));

    percorrerCaminho(particao, caminho, &inode, &n);

    listarDiretorio(inode);
}