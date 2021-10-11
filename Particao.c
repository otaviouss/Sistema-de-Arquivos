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

    if(caminho[0] != '/') {
        printf("Diretorio raiz é /\n");
        return;
    }

    ajudante = (INode*) malloc(sizeof(INode));

    *ajudante = particao->raiz;

    for(i=1;i<strlen(caminho);i++) {
        if(caminho[i]!='/') {
            help[cont] = caminho[i];
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

    printf("Diretorio ou Arquivo %s encontrado!\n", *nome);
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