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

// Exemplo de caminho: /DIR1/DIR2/DIR3/teste.txt
void percorrerCaminho(Particao* particao, char* caminho, INode** inode, char** nome) {
    INode* ajudante;
    int i = 0, j = 0, cont = 0;
    char help[100], *cam;
    int flag;

    
    if(caminho[strlen(caminho)-1] != '/') {
        strcpy(cam, caminho);
        
        cam[strlen(caminho)] = '/';
        cam[strlen(caminho)+1] = '\0';

        printf("C: %s\n", cam);
    }

    printf("OI\n");

    if(caminho[0] != '/') {
        printf("Diretorio raiz é /\n");
        return;
    }

    printf("OIs\n");

    ajudante = (INode*) malloc(sizeof(INode));

    printf("OIss\n");

    *ajudante = particao->raiz;

    printf("OI\n");

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

    if(ajudante->tipo == 0) printf("Diretorio %s encontrado!\n", ajudante->nome);
    else                    printf("Arquivo %s encontrado!\n", *nome);
}

// /Home/Teste.txt -> /Home/ICC
void moverArquivoParticao(Particao* particao, char* caminhoOrigem, char* caminhoDestino) {
    INode *iNodeOrigem, *iNodeDestino;
    char *nomeOrigem, *conteudo;
    
    nomeOrigem = (char*) malloc(100*sizeof(char));
    conteudo = (char*) malloc(1000*sizeof(char));
    
    percorrerCaminho(particao, caminhoDestino, &iNodeDestino, &nomeOrigem);
    percorrerCaminho(particao, caminhoOrigem, &iNodeOrigem, &nomeOrigem);

    RetornaConteudoArquivo(iNodeOrigem, nomeOrigem, &conteudo);

    criarArquivo(iNodeDestino, nomeOrigem, conteudo);

    deletarItem(iNodeOrigem, nomeOrigem);

    printf("Arquivo Movido com Sucesso!\n");
}

void criarDiretorioParticao(Particao* particao, char* caminho, char* nome) {
    INode* inode;
    char* n;
    size_t tam;
    
    n = (char*) malloc(100*sizeof(char));

    printf("OI\n");

    percorrerCaminho(particao, caminho, &inode, &n);

    printf("OI2\n");

    criarDiretorio(inode, nome);

    tam = sizeof(inode);

    tam = ceil(tam / particao->bloco);
    tam *= particao->bloco;

    // Testando se estourou o espaço livre.
    if(tam+particao->ocupado > particao->particao) {
        deletarItem(inode, nome);
        printf("Particao Cheia. Impossivel criar o diretorio.");
        return;
    }

    particao->ocupado += tam;
}

void criarArquivoParticao(Particao* particao, char* caminho, char* nome, char* conteudo) {
    INode* inode;
    char* n;
    size_t tam;
    
    n = (char*) malloc(100*sizeof(char));

    printf("OI\n");

    percorrerCaminho(particao, caminho, &inode, &n);

    printf("OI2\n");

    criarArquivo(inode, nome, conteudo);

    listarDiretorio(inode);

    tam = sizeof(inode);

    tam = ceil(tam / particao->bloco);
    tam *= particao->bloco;

    // Testando se estourou o espaço livre.
    if(tam+particao->ocupado > particao->particao) {
        deletarItem(inode, nome);
        printf("Particao Cheia. Impossivel inserir o arquivo.");
        return;
    }

    particao->ocupado += tam;
}

void deletarItemParticao(Particao* particao, char* caminho, char* nome) {
    INode* inode;
    char* n;
    size_t tam;
    
    n = (char*) malloc(100*sizeof(char));

    percorrerCaminho(particao, caminho, &inode, &n);

    tam = sizeof(inode);

    deletarItem(inode, nome);

    tam = ceil(tam / particao->bloco);
    tam *= particao->bloco;

    particao->ocupado -= tam;
}

void renomearItemParticao(Particao* particao, char* caminho, char* nomeAtual, char* novoNome) {
    INode* inode;
    char* n;
    size_t tam;
    
    n = (char*) malloc(100*sizeof(char));

    percorrerCaminho(particao, caminho, &inode, &n);

    renomearItem(inode, nomeAtual, novoNome);

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