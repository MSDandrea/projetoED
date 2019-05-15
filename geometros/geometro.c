//
// Created by matheus on 14/05/19.
//

#include "geometro.h"
#include "circulo.h"
#include "quadrado.h"
#include "triangulo.h"
#include "trapezio.h"
#include "retangulo.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct geometro {
    char *id;
} TGEOMETRO;

double calculaArea(void *geometro) {
    TGEOMETRO *castedG = geometro;
    if (strcmp(castedG->id, "QUA") == 0)
        return calculaAreaQuadrado((TQUAD *) geometro);
    else if (strcmp(castedG->id, "CIR") == 0)
        return calculaAreaCirculo((TCIRC *) geometro);
    else if (strcmp(castedG->id, "TRI") == 0)
        return calculaAreaTriangulo((TTRI *) geometro);
    else if (strcmp(castedG->id, "TRA") == 0)
        return calculaAreaTrapezio((TTRA *) geometro);
    else if (strcmp(castedG->id, "RET") == 0)
        return calculaAreaRetangulo((TRET *) geometro);
    else {
        printf("Geômetro de área desconhecida %s", castedG->id);
        exit(1);
    }

}

void *criaGeometro(char *id, double *lados) {
    if (strcmp(id, "QUA") == 0) {
        double lado = lados[0];
        TQUAD *quad = malloc(sizeof(TQUAD));
        quad->id = "QUA";
        quad->lado = lado;
        return quad;
    } else if (strcmp(id, "CIR") == 0) {
        double lado = lados[0];
        TCIRC *circ = malloc(sizeof(TCIRC));
        circ->id = "CIR";
        circ->raio = lado;
        return circ;
    } else if (strcmp(id, "TRI") == 0) {
        double base = lados[0];
        double altura = lados[1];
        TTRI *tri = malloc(sizeof(TTRI));
        tri->id = "TRI";
        tri->base = base;
        tri->altura = altura;
        return tri;
    } else if (strcmp(id, "RET") == 0) {
        double base = lados[0];
        double altura = lados[1];
        TRET *ret = malloc(sizeof(TRET));
        ret->id = "RET";
        ret->base = base;
        ret->altura = altura;
        return ret;
    } else if (strcmp(id, "TRA") == 0) {
        double base_me = lados[0];
        double base_ma = lados[1];
        double altura = lados[2];
        TTRA *tra = malloc(sizeof(TTRA));
        tra->id = "TRA";
        tra->menor_base = base_me;
        tra->maior_base = base_ma;
        tra->altura = altura;
        return tra;
    } else {
        printf("Geômetro desconhecido %s", id);
        exit(1);
    }
}


double *extraiLados(char *str, char delimiter) {
    int pos = -1;
    int index = 0;
    int size = 0;
    double *result = malloc(sizeof(double) * size);
    do {
        pos++;
        if (str[pos] == delimiter || str[pos] == '\0') {
            char piece[pos - index];
            for (int i = 0; i < pos - index; ++i) {
                piece[i] = str[i + index];
            }
            size++;
            result = realloc(result, size);
            double lado = atof(piece);
            result[size - 1] = lado;
            index = pos;
        }
    } while (str[pos] != '\0');
    return result;
}

void *criaGeometroPorString(char *str) {
    double *lados = extraiLados(&(str[4]), ' ');
    char id[4] = {str[0], str[1], str[2], '\0'};
    void *geo = criaGeometro(id, lados);
    free(lados);
    return geo;
}