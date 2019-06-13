//
// Created by matheus on 07/06/19.
//

#include "b.h"
#include <stdio.h>
#include <stdlib.h>


void imprimeRec(TAB *T);

TAB *Cria(int t) {
    TAB *novo = (TAB *) malloc(sizeof(TAB));
    novo->nchaves = 0;
    novo->chave = (TCHAVE **) malloc(sizeof(TCHAVE *) * ((t * 2) - 1));
    novo->folha = 1;
    novo->filho = (TAB **) malloc(sizeof(TAB *) * t * 2);
    int i;
    for (i = 0; i < (t * 2); i++) novo->filho[i] = NULL;
    for (i = 0; i < (t * 2) - 1; i++) novo->chave[i] = NULL;
    return novo;
}


void Liberatab(TAB *a) {
    if (a) {
        if (!a->folha) {
            int i;
            for (i = 0; i <= a->nchaves; i++) Liberatab(a->filho[i]);
        }
        for (int i = 0; i < a->nchaves; i++) free(a->chave[i]);
        free(a->filho);
        free(a->chave);
        free(a);
    }
}


TAB *Busca(TAB *x, int ch) {
    TAB *resp = NULL;
    if (!x) return resp;
    int i = 0;
    while (i < x->nchaves && ch > x->chave[i]->id) i++;
    if (i < x->nchaves && ch == x->chave[i]->id) return x;
    if (x->folha) return resp;
    return Busca(x->filho[i], ch);
}


TAB *Inicializa() {
    return NULL;
}


TAB *Divisao(TAB *x, int i, TAB *y, int t) {
    TAB *z = Cria(t);
    z->nchaves = t - 1;
    z->folha = y->folha;
    int j;
    for (j = 0; j < t - 1; j++) {
        z->chave[j] = y->chave[j + t];
    }
    if (!y->folha) {
        for (j = 0; j < t; j++) {
            z->filho[j] = y->filho[j + t];
            y->filho[j + t] = NULL;
        }
    }
    y->nchaves = t - 1;
    for (j = x->nchaves; j >= i; j--)
        x->filho[j + 1] = x->filho[j];
    x->filho[i] = z;
    for (j = x->nchaves; j >= i; j--) {
        x->chave[j] = x->chave[j - 1];
    }
    x->chave[i - 1] = y->chave[t - 1];
    x->nchaves++;
    return x;
}


TAB *Insere_Nao_Completo(TAB *x, int k, TGEOMETRO *geo, int t) {
    int i = x->nchaves - 1;
    if (x->folha) {
        while ((i >= 0) && (k < x->chave[i]->id)) {
            x->chave[i + 1] = x->chave[i];
            i--;
        }
        TCHAVE *chave = malloc(sizeof(TCHAVE));
        x->chave[i + 1] = chave;
        x->chave[i + 1]->id = k;
        x->chave[i + 1]->geo = geo;
        x->nchaves++;
        return x;
    }
    while ((i >= 0) && (k < x->chave[i]->id)) i--;
    i++;
    if (x->filho[i]->nchaves == ((2 * t) - 1)) {
        x = Divisao(x, (i + 1), x->filho[i], t);
        if (k > x->chave[i]->id) i++;
    }
    x->filho[i] = Insere_Nao_Completo(x->filho[i], k, geo, t);
    return x;
}


TAB *Insere(TAB *T, int k, TGEOMETRO *geo, int t) {
    if (Busca(T, k)) return T;
    if (!T) {
        T = Cria(t);
        TCHAVE *chave = malloc(sizeof(TCHAVE));
        T->chave[0] = chave;
        T->chave[0]->id = k;
        T->chave[0]->geo = geo;
        T->nchaves = 1;
        return T;
    }
    if (T->nchaves == (2 * t) - 1) {
        TAB *S = Cria(t);
        S->nchaves = 0;
        S->folha = 0;
        S->filho[0] = T;
        S = Divisao(S, 1, T, t);
        S = Insere_Nao_Completo(S, k, geo, t);
        return S;
    }
    T = Insere_Nao_Completo(T, k, geo, t);
    return T;
}

void imprimeEstrutura(TAB *a, int andar) {
    if (a) {
        int i, j;
        for (i = 0; i <= a->nchaves - 1; i++) {
            imprimeEstrutura(a->filho[i], andar + 1);
            for (j = 0; j <= andar; j++) printf("   ");
            printf("%d\n", a->chave[i]->id);
        }
        for (j = 0; j <= andar; j++) printf("   ");
        printf("¯\n");
        imprimeEstrutura(a->filho[i], andar + 1);
    }
}

void imprimeB(TAB *T) {
    imprimeEstrutura(T, 0);
    imprimeRec(T);
}

void imprimeRec(TAB *T) {
    if (!T || !T->chave)
        return;
    printf("Chaves: \n");
    for (int i = 0; i < T->nchaves; ++i) {
        printf("\tId:%d\n\tGeometro:", T->chave[i]->id);
        imprimeDetalhes(T->chave[i]->geo);
        printf("\n\n");
    }
    for (int j = 0; j <= T->nchaves; ++j) {
        if (T->filho[j])
            imprimeRec(T->filho[j]);
    }
}
