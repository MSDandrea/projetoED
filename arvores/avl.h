//
// Created by matheus on 05/06/19.
//
#include "../geometros/geometro.h"

#ifndef PROJETOED_AVL_H
#define PROJETOED_AVL_H
typedef struct no {
    TGEOMETRO *geo;
    int id;
    struct no *esq;
    struct no *dir;
    int alt;
} AVno;

AVno *insere_avl(int e, TGEOMETRO* geo, AVno *t);

void liberaAVL(AVno* t);

void imprimeAVL(AVno *a);

#endif //PROJETOED_AVL_H
