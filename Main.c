#include "Interface.h"
#include "INode.h"
#include <time.h>

int main() {

    //menu();
    //printf("%s", getDataAtual());
//    time_t t = time(NULL);
//    struct tm tm = *localtime(&t);
//    printf("now: %d-%d-%0d %d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

    char data[11];
    getDataAtual(data);
    printf("%s", data);
}