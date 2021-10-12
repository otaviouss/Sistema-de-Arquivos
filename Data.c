#include <stdio.h>
#include <time.h>

#include "Data.h"

void setData(Data* data) {
    // Variáveis necessárias para ver horario atual
    time_t rawtime = time(NULL);
    struct tm *timeinfo = localtime(&rawtime);

    data->dia = timeinfo->tm_mday;
    data->mes =  timeinfo->tm_mon + 1;
    data->ano = timeinfo->tm_year + 1900;
    data->hora = timeinfo->tm_hour;
    data->minuto = timeinfo->tm_min;
    data->segundo = timeinfo->tm_sec;
}

void getData(Data* data) {
    // **data_formatted** servirá caso a gente queira retornar a data (Não sei se será necessário)
    // No momento, apenas escrevendo a data na tela:
    printf("%d/%d/%d - %d:%d:%d\n", data->dia, data->mes, data->ano, data->hora, data->minuto, data->segundo);
}