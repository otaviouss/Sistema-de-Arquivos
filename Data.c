#include <stdio.h>

#include "Data.h"

void setData(Data* data, int dia, int mes, int ano, int hora, int minuto, int segundo) {
    data->dia = dia;
    data->mes = mes + 1;
    data->ano = ano + 1900;
    data->hora = hora;
    data->minuto = minuto;
    data->segundo = segundo;
}

void getData(Data* data) {
    // **data_formatted** servirá caso a gente queira retornar a data (Não sei se será necessário)
    // No momento, apenas escrevendo a data na tela:
    printf("%d/%d/%d - %d:%d:%d\n", data->dia, data->mes, data->ano, data->hora, data->minuto, data->segundo);
}