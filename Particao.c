#include <stdio.h>

#include "Particao.h"
#include "INode.h"

void inicializarParticao(Particao *particao, size_t TamParticao, size_t TamBloco){
    INode inode;

    // Define os tamanhos de bloco e partição
    particao->bloco = (size_t)TamBloco;
    particao->particao = (size_t)TamParticao;
    particao->ocupado = 0;

    // Cria diretório raiz (todos os demais diretórios e arquivos deverão estar dentro deste)
    criarDiretorio(&inode, "/");
    particao->raiz = inode;
}

