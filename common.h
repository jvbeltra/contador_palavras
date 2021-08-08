#define BUFFER_SIZE 100

int contaOcorrencias(const char *palavra) {
    FILE *fptr;
    fptr = fopen("biblia.txt", "r");
    char str[BUFFER_SIZE];
    char *pos;

    int index, ocorrencias;

    ocorrencias = 0;

    // Faz a leitura de todas as linhas do arquivo
    while ((fgets(str, BUFFER_SIZE, fptr)) != NULL) {
        index = 0;

        // Procura a próxima ocorrencia da palavra  no texto
        while ((pos = strstr(str + index, palavra)) != NULL) {

            //Guarda o indice da palavra encontrada, assim o while consegue encontrar uma ocorrencia diferente da atual
            index = (pos - str) + 1;
            ocorrencias++;
        }
    }
    fclose(fptr);
    return ocorrencias;
}