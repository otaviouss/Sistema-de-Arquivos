#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "Particao.h"
#include "INode.h"

int main() {
    INode* inode;
    char* nome;
    Particao particao;
    //menu();

    // Testando Particao

    inicializarParticao(&particao, 100, 20);

    criarDiretorioParticao(&particao, "/", "Teste");

    criarArquivoParticao(&particao, "/", "NovoArquivo.txt", "Conteudo.");

    criarArquivoParticao(&particao, "/", "NovoArquivo2.txt", "Conteudo2.");
    
    mostrarDiretorioParticao(&particao, "/");

    printf("A\n");

    criarArquivoParticao(&particao, "/Teste", "Haha.txt", "Que graça hein");

    printf("\n\nAqui\n\n");

    mostrarDiretorioParticao(&particao, "/Teste");

    printf("B\n");

    criarDiretorioParticao(&particao, "/Teste", "Dirrrr");

    printf("C\n");

    mostrarDiretorioParticao(&particao, "/Teste");

    return 0;

}