#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>

#define BUFFER_SIZE 100

int contaOcorrencias(const char *word) {

    FILE *fptr;
    fptr = fopen("biblia.txt", "r");
    char str[BUFFER_SIZE];
    char *pos;

    int index, ocorrencias;

    ocorrencias = 0;

    while ((fgets(str, BUFFER_SIZE, fptr)) != NULL) {
        index = 0;

        {

            while ((pos = strstr(str + index, word)) != NULL) {

                {
                    index = (pos - str) + 1;
                    ocorrencias++;
                }
            }
        }
    }
    fclose(fptr);
    return ocorrencias;
}

int main() {
    char palavra[12][10] = {" God ", " Jesus ", "Jerusalem", ":", " and ", " Joshua ", " Israel ", " gold ", " king ", " spirit ", " lord ", " they "};
    int ocorrencias = 0;


    omp_set_num_threads(3);

#pragma omp parallel for
    for (int i = 0; i < 3; i++) {
        ocorrencias = contaOcorrencias(palavra[i]);
        printf("A palavra ' %s ' foi encontrada %d vezes.\n", palavra[i], ocorrencias);
    }
}
