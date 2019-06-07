//
// Created by matheus on 24/05/19.
//
#include "../geometros/geometro.h"
#include "avl.h"
#include "b.h"

#ifndef PROJETOED_N_ARIA_H
#define PROJETOED_N_ARIA_H
typedef struct Gno {
    TGEOMETRO *geometro;
    int id;
    struct Gno *filho;
    struct Gno *irmao;
} TNO;

typedef struct naria {
    TNO *raiz;
} TNARIA;

TNARIA *incializa();

void insere(TNARIA *arvore, int id_pai, int id, TGEOMETRO *geo);

TNO *busca(TNARIA *arvore, int id);

void removeNo(TNARIA *arvore, int id);

void imprime(TNARIA *arvore);

void imprimeUnico(TNO *no);

void limpa(TNARIA *arvore);

void transformaAVL(TNARIA *arvore);

void transformaB(TNARIA *arvore, int ordem);

#endif //PROJETOED_N_ARIA_H
