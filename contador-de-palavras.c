#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

int contaOcorrencias(const char *palavra) {
    FILE *fptr;
    fptr = fopen("biblia.txt", "r");
    char str[BUFFER_SIZE];
    char *pos;

    int index, ocorrencias;

    ocorrencias = 0;

    while ((fgets(str, BUFFER_SIZE, fptr)) != NULL) {
        index = 0;

        while ((pos = strstr(str + index, palavra)) != NULL) {

            index = (pos - str) + 1;

            ocorrencias++;
        }
    }
    fclose(fptr);
    return ocorrencias;
}

int main() {
    char palavra[12][10] = {" God ", " Jesus ", "Jerusalem", ":", " and ", " Joshua ", " Israel ", " gold ", " king ", " spirit ", " lord ", " they "};
    int ocorrencias = 0;

    for (int i = 0; i < 12; i++) {
        ocorrencias = contaOcorrencias(palavra[i]);
        printf("A palavra '%s' foi encontrada %d vezes.\n", palavra[i], ocorrencias);
    }

    return 0;
}
