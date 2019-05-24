//
// Created by matheus on 14/05/19.
//

#ifndef PROJETOED_GEOMETRO_H
#define PROJETOED_GEOMETRO_H
typedef struct geometro {
    char *id;
    double *dimensoes;
} TGEOMETRO;

double calculaArea(TGEOMETRO *geometro);

void imprimeDetalhes(TGEOMETRO *geometro);

TGEOMETRO *criaGeometro(char *id, double *lados);

TGEOMETRO *criaGeometroPorString(char *str);

void mudaDimensoes(TGEOMETRO*geo, char* str_dimensoes);
#endif //PROJETOED_GEOMETRO_H
