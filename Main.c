#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "Particao.h"

int main() {
    char* nome;
    Particao particao;
    //menu();

    // Testando Particao

    inicializarParticao(&particao, 100, 20);

    criarDiretorioParticao(&particao, "/", "Teste");

    criarArquivoParticao(&particao, "/", "NovoArquivo.txt", "Conteudo.");

    criarArquivoParticao(&particao, "/", "NovoArquivo2.txt", "Conteudo2.");
    
    mostrarDiretorioParticao(&particao, "/");

    criarArquivoParticao(&particao, "/Teste", "Haha.txt", "Que graça hein");

    mostrarDiretorioParticao(&particao, "/Teste");

    criarDiretorioParticao(&particao, "/Teste", "Dirrrr");

    mostrarDiretorioParticao(&particao, "/Teste");

    renomearItemParticao(&particao, "/", "Teste", "Home");

    mostrarDiretorioParticao(&particao, "/");

    moverArquivoParticao(&particao, "/", "/Home", "NovoArquivo.txt");

    mostrarDiretorioParticao(&particao, "/");

    mostrarDiretorioParticao(&particao, "/Home");

    mostrarArquivoParticao(&particao, "/Home", "NovoArquivo.txt");

    return 0;

}