#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <Windows.h>

#include "Interface.h"
#include "INode.h"
#include "Data.h"
#include "Particao.h"

int main() {
    INode* inode;
    char* nome;
    Particao particao;
    //menu();

    // Testando Particao
    
    nome = (char*) malloc(100*sizeof(char));

    inicializarParticao(&particao, 1000, 20);

    criarDiretorio(&(particao.raiz), "Home");

    criarDiretorio(&particao.raiz, "ICC");

    listarDiretorio(&particao.raiz);

    percorrerCaminho(&particao, "/ICC/", &inode, &nome);

    listarArquivo(inode, "Teste.txt"); // Tentando listar arquivo inexistente

    listarDiretorio(inode);

    criarDiretorio(inode, "SEINAO");
    
    criarDiretorio(inode, "IC");
    
    criarArquivo(inode, "Teste.txt", "Alguma coisa");

    percorrerCaminho(&particao, "/Home/", &inode, &nome);

    criarDiretorio(inode, "SO");
    
    criarArquivo(inode, "Teste2.txt", "Alguma coisa2");

    listarDiretorio(inode);

    percorrerCaminho(&particao, "/ICC/Teste.txt", &inode, &nome);

    listarDiretorio(inode);

    printf("Listando...\n");
    listarArquivo(inode, nome);
    printf("....\n");

    moverArquivoParticao(&particao, "/ICC/Teste.txt", "/Home/");

    percorrerCaminho(&particao, "/Home/Teste.txt", &inode, &nome);

    printf("Listando...\n");
    listarArquivo(inode, nome);
    printf("....\n");

    return 0;

}