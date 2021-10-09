#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "Interface.h"
#include "INode.h"
#include "Data.h"

int main() {

    //menu();
    
    // Testando data e hora
    time_t rawtime = time(NULL);
    struct tm *timeinfo = localtime(&rawtime);
    Data data;
    char d;
    setData(&data, timeinfo->tm_mday, timeinfo->tm_mon, timeinfo->tm_year, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
    getData(&data, &d);
}