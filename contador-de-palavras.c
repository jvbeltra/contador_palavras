#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "./common.h"

#define BUFFER_SIZE 100

int main() {
    char palavra[12][10] = {" God ", " Jesus ", "Jerusalem", ":", " and ", " Joshua ", " Israel ", " gold ", " king ", " spirit ", " lord ", " they "};
    int ocorrencias = 0;

    for (int i = 0; i < 12; i++) {
        struct timeval t1, t2;
        gettimeofday(&t1, NULL);

        ocorrencias = contaOcorrencias(palavra[i]);

        gettimeofday(&t2, NULL);
        double t_total = (t2.tv_sec - t1.tv_sec) + ((t2.tv_usec - t1.tv_usec)/1000000.0);

        printf("A palavra '%s' foi encontrada %d vezes. - Tempo de exec: %f seg. \n", palavra[i], ocorrencias, t_total);
    }

    return 0;
}
