#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "INode.h"

void criarDiretorioInicial(INode* inode, char* nome) {

    // Definindo como Diretório
    inode->tipo = 0;

    // Definindo o nome do novo diretório
    inode->nome = nome;

    // Inicializando lista de arquivos do diretório
    FLVazia(inode);

    // Definindo tamanho inicial ocupado pelo diretório
    inode->tamanho = 0;
    
    // Definindo data atual
    setData(&(inode->dataCriacao));
    
    // Definindo data da última modificação (Data atual)
    setData(&(inode->dataModificacao));
    
    // Definindo data do último acesso (Data Atual)
    setData(&(inode->dataAcesso));
    
    // Definindo conteúdo como vazio (Pois é um diretório)
    inode->conteudo = NULL;

    // Definindo diretório como vazio
    inode->quantidade = 0;

}

void criarDiretorio(INode* inode, char* nome) {

    // Criando novo inode do diretório
    INode in;

    // Definindo como Diretório
    in.tipo = 0;

    // Definindo o nome do novo diretório
    in.nome = nome;

    // Inicializando lista de arquivos do diretório
    FLVazia(&in);

    // Definindo tamanho inicial ocupado pelo diretório
    in.tamanho = 0;
    
    // Definindo data atual
    setData(&(in.dataCriacao));
    
    // Definindo data da última modificação (Data atual)
    setData(&(in.dataModificacao));
    
    // Definindo data do último acesso (Data Atual)
    setData(&(in.dataAcesso));
    
    // Definindo conteúdo como vazio (Pois é um diretório)
    in.conteudo = NULL;

    // Definindo diretório como vazio
    in.quantidade = 0;

    listarDiretorio(*inode);

    // Inserindo novo diretório no diretório atual
    InsereINode(inode, in);

    // Atualiza Quantidade de items no Diretório atual
    inode->quantidade++;

}

void renomearDiretorioAtual(INode* inode, char* nome) {
    
    // Definindo data da última modificação (Data atual)
    setData(&(inode->dataModificacao));
    
    inode->nome = nome;

    // printf("Diretorio Atual Renomeado com Sucesso!\n");
}

int deletarItem(INode* inode, char* nome) {

    if(LehVazia(inode)) {
        printf("Diretorio Vazio!\n");
        return 0;
    }
    
    // Definindo data do último acesso (Data Atual)
    setData(&(inode->dataAcesso));

    if(RetiraINode(inode, nome) != 1) return -1;

    // Definindo data da última modificação (Data atual)
    setData(&(inode->dataModificacao));

    return 1;
    
}

void listarDiretorio(INode inode){

//    // Definindo data do último acesso (Data Atual)
//    setData(&((*inode)->dataAcesso));
    
    printf("Diretorio %s\n", inode.nome);

    printf("Data de Criacao: ");
    getData(&inode.dataCriacao);
    
    printf("Data de Modificacao: ");
    getData(&inode.dataModificacao);
    
    printf("Data de Acesso: ");
    getData(&inode.dataAcesso);

    ImprimeLista(&inode);

}

void criarArquivo(INode* inode, char* nome, char* conteudo){

    // Criando novo inode do arquivo
    INode in;
    
    // Definindo como Arquivo
    in.tipo = 1;

    // Definindo o nome do novo arquivo
    in.nome = nome;

    // Definindo lista de arquivos como vazia (pois um arqquivo não utiliza)
    FLVazia(&in);
    
    // Definindo data atual
    setData(&(in.dataCriacao));
    
    // Definindo data da última modificação (Data atual)
    setData(&(in.dataModificacao));
    
    // Definindo data do último acesso (Data Atual)
    setData(&(in.dataAcesso));
    
    // Definindo conteúdo do arquivo
    in.conteudo = conteudo;

    // 0, pois representa quantidade de items em um diretório (Não é o caso)
    in.quantidade = 0;

    // Definindo tamanho inicial ocupado pelo arquivo
    in.tamanho = sizeof(in);

    // Inserindo INode do arquivo no diretório
    InsereINode(inode, in);

    // Definindo data da última modificação (Data atual)
    setData(&(inode->dataModificacao));
    
    // Definindo data do último acesso (Data Atual)
    setData(&(inode->dataAcesso));
    
    // Atualiza Quantidade de items no Diretório atual
    inode->quantidade++;

}

void renomearItem(INode* inode, char* nomeAtual, char* novoNome) {

    if(LehVazia(inode)) {
        printf("Diretorio Vazio!\n");
        return;
    }
    
    // Definindo data do último acesso (Data Atual)
    setData(&(inode->dataAcesso));
    
    if(RenomearINode(inode, nomeAtual, novoNome) != 1) {
        printf("Nao foi possivel renomear.\n");
        return;
    }

    // Definindo data da última modificação (Data atual)
    setData(&(inode->dataModificacao));

    printf("Arquivo Renomeado com Sucesso!\n");

}

/*
void deletarArquivo(INode* inode, char* nome){
    int i;

    // Variáveis necessárias para ver horario atual
    time_t rawtime = time(NULL);
    struct tm *timeinfo = localtime(&rawtime);

    if(LehVazia(&inode->lista)) {
        printf("Diretorio Atual esta Vazio!\n");
        return;
    }
    
    // Definindo data do último acesso (Data Atual)
    setData(&(inode->dataAcesso), timeinfo->tm_mday, timeinfo->tm_mon, timeinfo->tm_year, 
                timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
    
    for(i=0;i<inode->quantidade; i++) {
        if(strcmp(inode->lista[i].nome, nome) == 0) {
            inode->lista[i].tipo = -1;

            // Adicionando item na lixeira
            inode->lixeira++;
            
            // Definindo data da última modificação (Data atual)
            setData(&(inode->dataModificacao), timeinfo->tm_mday, timeinfo->tm_mon, timeinfo->tm_year, 
                        timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);

            return;
        }
    }
   
}*/

// Apresenta conteúdo dentro de um arquivo com o nome
void listarArquivo(INode* inode, char* nome) {
    
    // Definindo data do último acesso (Data Atual)
    setData(&(inode->dataAcesso));

    if(ImprimeArquivo(inode, nome) != 1) {
        printf("Arquivo Inexistente no caminho especificado.\n");
    }

}

// Apresenta conteúdo dentro de um arquivo
void listarArquivoINode(INode* inode) {
    
    // Definindo data do último acesso (Data Atual)
    setData(&(inode->dataAcesso));

    
    printf("Conteudo no Arquivo %s\n", inode->nome);
    printf("%s\n", inode->conteudo);
}

// Operações para lidar com a lista de arquivos dentro do diretório

void FLVazia(INode* lista) {
    lista->pPrimeiro = (Celula*) malloc(sizeof(Celula));
    // lista->pUltimo = lista->pPrimeiro;
    lista->pPrimeiro->pProx = NULL;
}

int LehVazia(INode* lista) {
    return(lista->pPrimeiro->pProx == NULL);
}

void InsereINode(INode* lista, INode inode) {
    Apontador pAux;

    pAux = lista->pPrimeiro;
    while(pAux->pProx != NULL) {
        pAux = pAux->pProx;
    }
    pAux->pProx = (Apontador) malloc(sizeof(Celula));
    pAux = pAux->pProx;
    pAux->inode = inode;
    pAux->pProx = NULL;
}

int RetiraINode(INode* lista, char* nome) {
    Apontador pAux, pDel;
    
    if(LehVazia(lista)) return -1;

    pAux = lista->pPrimeiro;
    while(pAux->pProx != NULL) {
        if(strcmp(pAux->pProx->inode.nome, nome) == 0) {
            pDel = pAux->pProx;
            pAux->pProx = pAux->pProx->pProx;
            free(pDel);
            return 1;
        }
        pAux = pAux->pProx;
    }
    return 0;
}

int BuscarINode(INode* lista, char* nome, INode* inode) {
    Apontador pAux;
    if(LehVazia(lista)) return -1;

    pAux = lista->pPrimeiro;

    while(pAux->pProx != NULL) {

        if(strcmp(pAux->pProx->inode.nome, nome) == 0) {
            (*inode) = pAux->pProx->inode;

            return 1;
        }
        pAux = pAux->pProx;
    }

    return 0;
}

int RenomearINode(INode* lista, char* nomeAntigo, char* nomeNovo) {
    Apontador pAux;

    //if(LehVazia(lista)) return -1;

    pAux = lista->pPrimeiro->pProx;
    while(pAux != NULL) {
        if(strcmp(pAux->inode.nome, nomeAntigo) == 0) {
            setData(&(pAux->inode.dataModificacao));
            pAux->inode.nome = nomeNovo;
            return 1;
        }
        pAux = pAux->pProx;
    }
    return 0;
}

int ImprimeArquivo(INode* lista, char* nome) {
    Apontador pAux;

    if(LehVazia(lista)) return -1;
    
    pAux = lista->pPrimeiro->pProx;
    while(pAux != NULL) {
        if(strcmp(pAux->inode.nome, nome) == 0) {
            setData(&(pAux->inode.dataAcesso));
            printf("Conteudo no Arquivo %s\n", pAux->inode.nome);
            printf("%s\n", pAux->inode.conteudo);
            return 1;
        }
        pAux = pAux->pProx;
    }
    return 0;
}

int RetornaConteudoArquivo(INode* lista, char* nome, char conteudo[]) {
    Apontador pAux;

    if(LehVazia(lista)) return -1;
    
    pAux = lista->pPrimeiro->pProx;
    while(pAux != NULL) {
        if(strcmp(pAux->inode.nome, nome) == 0) {
            setData(&(pAux->inode.dataAcesso));
            strcpy(conteudo, pAux->inode.conteudo);
            return 1;
        }
        pAux = pAux->pProx;
    }
    return 0;
}

void ImprimeLista(INode* lista) {
    Apontador pAux;

    // if(LehVazia(lista)) return;

    pAux = lista->pPrimeiro->pProx;

    if(pAux == NULL) {
        printf("Diretorio Vazio.\n");
    }

    while(pAux != NULL) {
        if(pAux->inode.tipo == 0)      printf("  Diretorio %s\n", pAux->inode.nome);
        else if(pAux->inode.tipo == 1) printf("  Arquivo %s\n", pAux->inode.nome);
        pAux = pAux->pProx;
    }
}