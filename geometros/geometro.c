//
// Created by matheus on 14/05/19.
//

#include "geometro.h"

#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


double calculaAreaCirculo(TGEOMETRO *pGeometro) {
    return (M_PI * pow(pGeometro->dimensoes[0], 2));
}

double calculaAreaTrapezio(TGEOMETRO *pGeometro) {
    return ((pGeometro->dimensoes[0] + pGeometro->dimensoes[1]) * pGeometro->dimensoes[2]) / 2.0;
}

double calculaAreaTriangulo(TGEOMETRO *pGeometro) {
    return (pGeometro->dimensoes[0] * pGeometro->dimensoes[1]) / 2.0;
}

double calculaAreaRetangulo(TGEOMETRO *pGeometro) {
    return (pGeometro->dimensoes[0] * pGeometro->dimensoes[1]);
}

double calculaAreaQuadrado(TGEOMETRO *pGeometro) {
    return pow(pGeometro->dimensoes[0], 2);
}


double calculaArea(TGEOMETRO *geometro) {
    if (strcmp(geometro->id, "QUA") == 0)
        return calculaAreaQuadrado(geometro);
    else if (strcmp(geometro->id, "CIR") == 0)
        return calculaAreaCirculo(geometro);
    else if (strcmp(geometro->id, "TRI") == 0)
        return calculaAreaTriangulo(geometro);
    else if (strcmp(geometro->id, "TRA") == 0)
        return calculaAreaTrapezio(geometro);
    else if (strcmp(geometro->id, "RET") == 0)
        return calculaAreaRetangulo(geometro);
    else {
        printf("Geômetro de área desconhecida %s", geometro->id);
        exit(1);
    }
}

TGEOMETRO *criaGeometro(char *id, double *lados) {
    TGEOMETRO *geo = malloc(sizeof(TGEOMETRO));
    geo->dimensoes = lados;
    if (strcmp(id, "QUA") == 0) {
        geo->id = "QUA";
        return geo;
    } else if (strcmp(id, "CIR") == 0) {
        geo->id = "CIR";
        return geo;
    } else if (strcmp(id, "TRI") == 0) {
        geo->id = "TRI";
        return geo;
    } else if (strcmp(id, "RET") == 0) {
        geo->id = "RET";
        return geo;
    } else if (strcmp(id, "TRA") == 0) {
        geo->id = "TRA";
        return geo;
    } else {
        printf("Geômetro desconhecido %s", id);
        exit(1);
    }
}


double *extraiLados(char *str, char delimiter) {
    int pos = -1;
    int index = 0;
    int size = 0;
    double *result = malloc(sizeof(double) * 1);
    do {
        pos++;
        if (str[pos] == delimiter || str[pos] == '\0') {
            char piece[pos - index];
            for (int i = 0; i < pos - index; ++i) {
                piece[i] = str[i + index];
            }
            size++;
            result = realloc(result, sizeof(double) * size);
            double lado = atof(piece);
            result[size - 1] = lado;
            index = pos;
        }
    } while (str[pos] != '\0');
    return result;
}

TGEOMETRO *criaGeometroPorString(char *str) {
    double *lados = extraiLados(&(str[4]), ' ');
    char id[4] = {str[0], str[1], str[2], '\0'};
    void *geo = criaGeometro(id, lados);
    return geo;
}

void detalhes(TGEOMETRO *geometro, char *str) {
    char *id = geometro->id;
    char *dim = malloc(sizeof(char)* 80);
    if (strcmp(id, "QUA") == 0) {
        sprintf(dim, "lado: %f", geometro->dimensoes[0]);
    } else if (strcmp(id, "CIR") == 0) {
        sprintf(dim,  "raio: %f", geometro->dimensoes[0]);
    } else if (strcmp(id, "TRI") == 0) {
        sprintf(dim,  "base: %f | altura: %f", geometro->dimensoes[0], geometro->dimensoes[1]);
    } else if (strcmp(id, "RET") == 0) {
        sprintf(dim,  "base: %f | altura: %f", geometro->dimensoes[0], geometro->dimensoes[1]);
    } else if (strcmp(id, "TRA") == 0) {
        sprintf(dim,  "base menor: %f | base maior: %f | altura: %f", geometro->dimensoes[0],
                 geometro->dimensoes[1], geometro->dimensoes[2]);
    } else {
        printf("Geômetro desconhecido %s", id);
        exit(1);
    }
    sprintf(str, "%s -> %s | area: %f", id, dim, calculaArea(geometro));
}



void imprimeDetalhes(TGEOMETRO *geometro) {
    char *t = malloc(sizeof(char) * 100);
    detalhes(geometro, t);
    printf("%s\n", t);
}

void mudaDimensoes(TGEOMETRO *geo, char *str_dimensoes) {
    double *dimensoes = extraiLados(str_dimensoes, ' ');
    free(geo->dimensoes);
    geo->dimensoes = dimensoes;
}