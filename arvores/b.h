//
// Created by matheus on 07/06/19.
//
#include "../geometros/geometro.h"

#ifndef PROJETOED_B_H
#define PROJETOED_B_H
typedef struct chave {
    int id;
    TGEOMETRO *geo;
} TCHAVE;

typedef struct ArvB {
    int nchaves, folha;
    TCHAVE **chave;
    struct ArvB **filho;
} TAB;

void Liberatab(TAB *a);

TAB *Inicializa();

TAB *Insere(TAB *T, int k, TGEOMETRO *geo, int t);

void imprimeB(TAB *T);

#endif //PROJETOED_B_H
