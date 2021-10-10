#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "INode.h"

void criarDiretorioInicial(INode* inode, char* nome) {
    // Variáveis necessárias para ver horario atual
    time_t rawtime = time(NULL);
    struct tm *timeinfo = localtime(&rawtime);

    // Definindo como Diretório
    inode->tipo = 0;

    // Definindo o nome do novo diretório
    inode->nome = nome;

    // Definindo lista de arquivos do diretório como vazia
    inode->lista = NULL;

    // Definindo tamanho inicial ocupado pelo diretório
    inode->tamanho = 0;
    
    // Definindo data atual
    setData(&(inode->dataCriacao), timeinfo->tm_mday, timeinfo->tm_mon, timeinfo->tm_year, 
                timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
    
    // Definindo data da última modificação (Data atual)
    setData(&(inode->dataModificacao), timeinfo->tm_mday, timeinfo->tm_mon, timeinfo->tm_year, 
                timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
    
    // Definindo data do último acesso (Data Atual)
    setData(&(inode->dataAcesso), timeinfo->tm_mday, timeinfo->tm_mon, timeinfo->tm_year, 
                timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
    
    // Definindo conteúdo como vazio (Pois é um diretório)
    inode->conteudo = NULL;

    // Definindo diretório como vazio
    inode->quantidade = 0;

    // Definindo lixeira como vazia
    inode->lixeira = 0;
}

void criarDiretorio(INode* inode, char* nome) {
    // Variáveis necessárias para ver horario atual
    time_t rawtime = time(NULL);
    struct tm *timeinfo = localtime(&rawtime);

    // Alocar espaço para novo arquivo
    inode->lista = (INode*) realloc(inode->lista, sizeof(INode));

    // Definindo como Diretório
    inode->lista[inode->quantidade].tipo = 0;

    // Definindo o nome do novo diretório
    inode->lista[inode->quantidade].nome = nome;

    // Definindo lista de arquivos do diretório como vazia
    inode->lista[inode->quantidade].lista = NULL;

    // Definindo tamanho inicial ocupado pelo diretório
    inode->lista[inode->quantidade].tamanho = 0;
    
    // Definindo data atual
    setData(&(inode->lista[inode->quantidade].dataCriacao), timeinfo->tm_mday, timeinfo->tm_mon, timeinfo->tm_year, 
                timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
    
    // Definindo data da última modificação (Data atual)
    setData(&(inode->lista[inode->quantidade].dataModificacao), timeinfo->tm_mday, timeinfo->tm_mon, timeinfo->tm_year, 
                timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
    
    // Definindo data do último acesso (Data Atual)
    setData(&(inode->lista[inode->quantidade].dataAcesso), timeinfo->tm_mday, timeinfo->tm_mon, timeinfo->tm_year, 
                timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
    
    // Definindo conteúdo como vazio (Pois é um diretório)
    inode->lista[inode->quantidade].conteudo = NULL;

    // Definindo diretório como vazio
    inode->lista[inode->quantidade].quantidade = 0;

    // Definindo lixeira como vazia
    inode->lista[inode->quantidade].lixeira = 0;

    // Atualiza Quantidade de items no Diretório atual
    inode->quantidade++;

}

void renomearDiretorioAtual(INode* inode, char* nome){
    // Variáveis necessárias para ver horario atual
    time_t rawtime = time(NULL);
    struct tm *timeinfo = localtime(&rawtime);
    
    // Definindo data da última modificação (Data atual)
    setData(&(inode->dataModificacao), timeinfo->tm_mday, timeinfo->tm_mon, timeinfo->tm_year, 
                timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
    
    inode->nome = nome;

    printf("Diretorio Atual Renomeado com Sucesso!\n");
}

void deletarDiretorio(INode* inode, char* nome){
    int i;
    
    // Variáveis necessárias para ver horario atual
    time_t rawtime = time(NULL);
    struct tm *timeinfo = localtime(&rawtime);

    if(inode->lista == NULL) {
        printf("Diretorio Vazio!\n");
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

            printf("Arquivo Deletado com Sucesso!\n");
            return;
        }
    }

    
}

void listarDiretorio(INode* inode){
    int i;
    
    // Variáveis necessárias para ver horario atual
    time_t rawtime = time(NULL);
    struct tm *timeinfo = localtime(&rawtime);
    
    // Definindo data do último acesso (Data Atual)
    setData(&(inode->dataAcesso), timeinfo->tm_mday, timeinfo->tm_mon, timeinfo->tm_year, 
                timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
    
    printf("Diretorio %s\n", inode->nome);

    printf("Data de Criacao: ");
    getData(&inode->dataCriacao);
    
    printf("Data de Modificacao: ");
    getData(&inode->dataModificacao);
    
    printf("Data de Acesso: ");
    getData(&inode->dataAcesso);

    for(i=0;i<inode->quantidade; i++) {
        if(inode->lista[i].tipo == 0)   printf("  Diretorio %s\n", inode->lista[i].nome);
        else if(inode->lista[i].tipo == 1) printf("  Arquivo %s\n", inode->lista[i].nome);
    }

}

void criarArquivo(INode* inode, char* nome, char* conteudo){
    // Variáveis necessárias para ver horario atual
    time_t rawtime = time(NULL);
    struct tm *timeinfo = localtime(&rawtime);

    // Alocar espaço para novo arquivo
    inode->lista = (INode*) realloc(inode->lista, sizeof(INode));
    
    // Definindo como Arquivo
    inode->lista[inode->quantidade].tipo = 1;

    // Definindo o nome do novo arquivo
    inode->lista[inode->quantidade].nome = nome;

    // Definindo lista de arquivos como vazia (pois um arqquivo não utiliza)
    inode->lista[inode->quantidade].lista = NULL;
    
    // Definindo data atual
    setData(&(inode->lista[inode->quantidade].dataCriacao), timeinfo->tm_mday, timeinfo->tm_mon, timeinfo->tm_year, 
                timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
    
    // Definindo data da última modificação (Data atual)
    setData(&(inode->lista[inode->quantidade].dataModificacao), timeinfo->tm_mday, timeinfo->tm_mon, timeinfo->tm_year, 
                timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
    
    // Definindo data do último acesso (Data Atual)
    setData(&(inode->lista[inode->quantidade].dataAcesso), timeinfo->tm_mday, timeinfo->tm_mon, timeinfo->tm_year, 
                timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
    
    // Definindo conteúdo do arquivo
    inode->lista[inode->quantidade].conteudo = conteudo;

    // 0, pois representa quantidade de items em um diretório (Não é o caso)
    inode->lista[inode->quantidade].quantidade = 0;

    // Definindo tamanho inicial ocupado pelo arquivo
    inode->lista[inode->quantidade].tamanho = sizeof(inode);

    // Definindo data da última modificação (Data atual)
    setData(&(inode->dataModificacao), timeinfo->tm_mday, timeinfo->tm_mon, timeinfo->tm_year, 
                timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
    
    // Definindo data do último acesso (Data Atual)
    setData(&(inode->dataAcesso), timeinfo->tm_mday, timeinfo->tm_mon, timeinfo->tm_year, 
                timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
    
    // Atualiza Quantidade de items no Diretório atual
    inode->quantidade++;

    // Definindo lixeira como vazia (Serve apenas para diretório)
    inode->lixeira = 0;
}

void renomearItem(INode* inode, char* nomeAtual, char* novoNome) {
    int i;
    // Variáveis necessárias para ver horario atual
    time_t rawtime = time(NULL);
    struct tm *timeinfo = localtime(&rawtime);

    if(inode->lista == NULL || inode->quantidade==inode->lixeira) {
        printf("Diretorio Vazio!\n");
        return;
    }
    
    // Definindo data do último acesso (Data Atual)
    setData(&(inode->dataAcesso), timeinfo->tm_mday, timeinfo->tm_mon, timeinfo->tm_year, 
                timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
    
    for(i=0;i<inode->quantidade; i++) {
        if(strcmp(inode->lista[i].nome, nomeAtual) == 0) {
            inode->lista[i].nome = novoNome;
            
            // Definindo data da última modificação (Data atual)
            setData(&(inode->dataModificacao), timeinfo->tm_mday, timeinfo->tm_mon, timeinfo->tm_year, 
                        timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
        }
    }

    printf("Arquivo Renomeado com Sucesso!\n");

}

void deletarArquivo(INode* inode, char* nome){
    int i;

    // Variáveis necessárias para ver horario atual
    time_t rawtime = time(NULL);
    struct tm *timeinfo = localtime(&rawtime);

    if(inode->lista == NULL || inode->quantidade==inode->lixeira) {
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
   
}

void deletarArquivoINode(INode* inode) {
    int i;

    // Variáveis necessárias para ver horario atual
    time_t rawtime = time(NULL);
    struct tm *timeinfo = localtime(&rawtime);

    // Definindo data do último acesso (Data Atual)
    setData(&(inode->dataAcesso), timeinfo->tm_mday, timeinfo->tm_mon, timeinfo->tm_year, 
                timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
    
    // Definindo data da última modificação (Data Atual)
    setData(&(inode->dataModificacao), timeinfo->tm_mday, timeinfo->tm_mon, timeinfo->tm_year, 
                timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
    
    inode->tipo = -1;

    // Adicionando item na lixeira
    inode->lixeira++;
    
}

// Apresenta conteúdo dentro de um arquivo com o nome
void listarArquivo(INode* inode, char* nome) {
    int i;

    // Variáveis necessárias para ver horario atual
    time_t rawtime = time(NULL);
    struct tm *timeinfo = localtime(&rawtime);
    
    // Definindo data do último acesso (Data Atual)
    setData(&(inode->dataAcesso), timeinfo->tm_mday, timeinfo->tm_mon, timeinfo->tm_year, 
                timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);

    for(i=0;i<inode->quantidade; i++) {

        if(strcmp(inode->lista[i].nome, nome) == 0) {
            // Definindo data do último acesso (Data Atual)
            setData(&(inode->lista[i].dataAcesso), timeinfo->tm_mday, timeinfo->tm_mon, timeinfo->tm_year, 
                        timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
            
            printf("Conteudo no Arquivo %s\n", inode->lista[i].nome);
            printf("%s\n", inode->lista[i].conteudo);
        }
    }
}

// Apresenta conteúdo dentro de um arquivo
void listarArquivoINode(INode* inode) {
    int i;

    // Variáveis necessárias para ver horario atual
    time_t rawtime = time(NULL);
    struct tm *timeinfo = localtime(&rawtime);
    
    // Definindo data do último acesso (Data Atual)
    setData(&(inode->dataAcesso), timeinfo->tm_mday, timeinfo->tm_mon, timeinfo->tm_year, 
                timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);

    
    printf("Conteudo no Arquivo %s\n", inode->nome);
    printf("%s\n", inode->conteudo);
        
}