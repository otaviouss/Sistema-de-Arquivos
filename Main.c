#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <Windows.h>

#include "Interface.h"
#include "INode.h"
#include "Data.h"

int main() {

    //menu();
    
    // Testando INode
    INode inode;

    criarDiretorioInicial(&inode, "/");

    Sleep(2000);

    criarArquivo(&inode, "Teste.txt", "Alguma coisa.");

    criarArquivo(&inode, "Teste2.txt", "Alguma coisa 2.");

    Sleep(2000);

    renomearItem(&inode, "Teste.txt", "NovoNome.txt");

    deletarArquivo(&inode, "NovoNome.txt");

    listarDiretorio(&inode);

    Sleep(1000);

    criarDiretorio(&inode, "Home");

    Sleep(2000);

    renomearDiretorioAtual(&inode, "C:/");

    listarDiretorio(&inode);

    return 0;

}