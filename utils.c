//
// Created by matheus on 26/05/19.
//
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

TNARIA *criaDeArquivo(char *arquivo) {
    TNARIA *result = incializa();
    FILE *file = fopen(arquivo, "r");
    if (file != NULL) {
        size_t lineSize = 0;
        ssize_t read = 0;
        char *line = NULL;
        while ((read = getline(&line, &lineSize, file)) != -1) {
            int id, parent;
            char *geo = malloc(sizeof(char) * 250);
            sscanf(line, "%d/%d/%[^\\n]", &id, &parent, geo);
            TGEOMETRO *g = criaGeometroPorString(geo);
            insere(result, parent, id, g);
        }
    }
    fclose(file);
    return result;
}