//
// Created by matheus on 05/06/19.
//

#include <stdlib.h>
#include <stdio.h>
#include "avl.h"


void liberaAVL(AVno* t){
    if( t != NULL ){
        liberaAVL( t->esq );
        liberaAVL( t->dir );
        free( t );
    }
}

static int calc_alt(AVno *n) {
    if (n == NULL) return -1;
    return n->alt;
}


static int max(int l, int r) {
    return l > r ? l : r;
}


static AVno *rot_dir(AVno *k2) {
    AVno *k1 = NULL;
    k1 = k2->esq;
    k2->esq = k1->dir;
    k1->dir = k2;
    k2->alt = max(calc_alt(k2->esq), calc_alt(k2->dir)) + 1;
    k1->alt = max(calc_alt(k1->esq), k2->alt) + 1;
    return k1; /* AVnova raiz */
}


static AVno *rot_esq(AVno *k1) {
    AVno *k2;
    k2 = k1->dir;
    k1->dir = k2->esq;
    k2->esq = k1;
    k1->alt = max(calc_alt(k1->esq), calc_alt(k1->dir)) + 1;
    k2->alt = max(calc_alt(k2->dir), k1->alt) + 1;
    return k2;  /* AVnova raiz */
}


static AVno *rot_esq_dir(AVno *k3) {
    k3->esq = rot_esq(k3->esq);
    return rot_dir(k3);
}


static AVno *rot_dir_esq(AVno *k1) {
    k1->dir = rot_dir(k1->dir);
    return rot_esq(k1);
}


AVno *insere_avl(int e, TGEOMETRO *geo, AVno *t) {
    if (t == NULL) {
        t = (AVno *) malloc(sizeof(AVno));
        if (t == NULL) {
            fprintf(stderr, "Out of memory!!! (insere)\n");
            exit(1);
        } else {
            t->id = e;
            t->geo = geo;
            t->alt = 0;
            t->esq = t->dir = NULL;
        }
    } else if (e < t->id) {
        t->esq = insere_avl(e, geo, t->esq);
        if (calc_alt(t->esq) - calc_alt(t->dir) == 2)
            t = (e < t->esq->id ? rot_dir : rot_esq_dir)(t);
    } else if (e > t->id) {
        t->dir = insere_avl(e, geo, t->dir);
        if (calc_alt(t->dir) - calc_alt(t->esq) == 2)
            t = (e > t->dir->id ? rot_esq : rot_dir_esq)(t);
    }
    t->alt = max(calc_alt(t->esq), calc_alt(t->dir)) + 1;
    return t;
}


void imprime_est(AVno *a, int andar){
    if(a){
        int j;
        imprime_est(a->esq,andar+1);
        for(j=0; j<=andar; j++) printf("   ");
        printf("%d\n", a->id);
        imprime_est(a->dir,andar+1);
    }
}

void imprime_aux(AVno *a) {
    if (a) {
        printf("Id: %d\n Detalhes: ", a->id);
        imprimeDetalhes(a->geo);
        printf(" Filhos:");
        if (a->esq)
            printf(" %d", a->esq->id);
        if (a->dir)
            printf(" %d", a->dir->id);
        printf("\n\n");
        imprime_aux(a->esq);
        imprime_aux(a->dir);
    }
}


void imprimeAVL(AVno *a) {
    imprime_est(a,0);
    imprime_aux(a);
}