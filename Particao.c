#include <stdio.h>
#include "Particao.h"

void setTamanhoParticaoEBloco(Particao *particao, int TamParticao, int TamBloco){
    particao->bloco = (size_t)TamBloco;
    particao->particao = (size_t)TamParticao;
}

