//
// Created by matheus on 24/05/19.
//
#include "../geometros/geometro.h"

#ifndef PROJETOED_N_ARIA_H
#define PROJETOED_N_ARIA_H
typedef struct no {
    TGEOMETRO *geometro;
    int id;
    struct no *filho;
    struct no *irmao;
} TNO;

typedef struct naria{
    TNO* raiz;
}TNARIA;

TNARIA *incializa();

void insere(TNARIA *arvore, int id_pai, int id, TGEOMETRO *geo);

TNO *busca(TNARIA *arvore, int id);

void imprime(TNARIA *arvore);

#endif //PROJETOED_N_ARIA_H