#ifndef DATA_H
#define DATA_H

typedef struct {
    int dia;
    int mes;
    int ano;
    int hora;
    int minuto;
    int segundo;
} Data;

void setData(Data* data);

void getData(Data* data);

#endif