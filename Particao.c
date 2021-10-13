#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Particao.h"
#include "INode.h"

int teto(double number) {
    return (int)(number + 0.5);
}

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
void percorrerCaminho(Particao* particao, char* caminho, INode** inode) {
    char cam[110], help[100];
    INode* ajudante;
    int i = 0, cont = 0, flag;

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
    char *conteudo;
    
    conteudo = (char*) malloc(10000*sizeof(char));
    
    percorrerCaminho(particao, caminhoDestino, &iNodeDestino);
    percorrerCaminho(particao, caminhoOrigem, &iNodeOrigem);

    RetornaConteudoArquivo(iNodeOrigem, nome, &conteudo);

    criarArquivo(iNodeDestino, nome, conteudo);

    deletarItem(iNodeOrigem, nome);

    printf("Arquivo Movido com Sucesso!\n");
}

void criarDiretorioParticao(Particao* particao, char* caminho, char* nome) {
    INode* inode;
    size_t tam;

    percorrerCaminho(particao, caminho, &inode);

    criarDiretorio(inode, nome);

    tam = sizeof(*inode);

    tam = teto((float) tam / (float) particao->bloco);
    tam *= particao->bloco;

    // Testando se estourou o espaço livre.
    if(tam+particao->ocupado > particao->particao) {
        deletarItem(inode, nome);
        printf("Particao Cheia. Impossivel criar o diretorio.");
        return;
    }

    particao->ocupado += tam;

    printf("Diretorio Criado com Sucesso!\n");
}

void criarArquivoParticao(Particao* particao, char* caminho, char* nome, char* conteudo) {
    INode* inode;
    size_t tam;

    percorrerCaminho(particao, caminho, &inode);

    criarArquivo(inode, nome, conteudo);

    tam = sizeof(*inode);

    tam = teto((float) tam / (float) particao->bloco);
    tam *= particao->bloco;

    // Testando se estourou o espaço livre.
    if(tam+particao->ocupado > particao->particao) {
        deletarItem(inode, nome);
        printf("Particao Cheia. Impossivel inserir o arquivo.");
        return;
    }

    particao->ocupado += tam;

    printf("Arquivo Criado com Sucesso!\n");
}

void deletarItemParticao(Particao* particao, char* caminho, char* nome) {
    INode* inode;
    size_t tam;

    percorrerCaminho(particao, caminho, &inode);

    tam = sizeof(inode);

    if(deletarItem(inode, nome) == 1) {
        tam = teto((float) tam / (float) particao->bloco);
        tam *= particao->bloco;

        particao->ocupado -= tam;

        printf("Item Deletado com Sucesso!\n");
    } else {
        printf("Nao foi possivel deletar.\n");
    }

    
}

void renomearItemParticao(Particao* particao, char* caminho, char* nomeAtual, char* novoNome) {
    INode* inode;
    size_t tam;

    char *nome = (char*) malloc(sizeof(novoNome));

    strcpy(nome, novoNome);
    
    percorrerCaminho(particao, caminho, &inode);

    renomearItem(inode, nomeAtual, nome);

}

void mostrarArquivoParticao(Particao* particao, char* caminho, char* nome) {
    INode* inode;

    percorrerCaminho(particao, caminho, &inode);

    listarArquivo(inode, nome);
}

void mostrarDiretorioParticao(Particao* particao, char* caminho) {
    INode* inode;

    percorrerCaminho(particao, caminho, &inode);

    listarDiretorio(inode);
}