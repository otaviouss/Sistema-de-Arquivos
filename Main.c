#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "Particao.h"
#include "GerenciadorDeArquivos.h"

int main() {
    char* nome;
    Particao particao;
    //menu();

    // Testando Particao
    /*
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

    criarDiretorioParticao(&particao, "/", "Crash");

    deletarItemParticao(&particao, "/", "NovoArquivo2.txt");

    criarDiretorioParticao(&particao, "/", "Crash");
    
    mostrarDiretorioParticao(&particao, "/");
    */
    char *n;

    scanf("%s", nome);

    printf("%s", nome);

    lerArquivo("test.txt", &n);

    Instrucao* inst;
    lerArquivoInstrucoes("test2.txt", &inst);

    printf("OI");

    printf("D: %s %s", inst[0].comando, inst[0].caminho1 );

    return 0;

}