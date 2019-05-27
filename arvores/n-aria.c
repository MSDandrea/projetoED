//
// Created by matheus on 24/05/19.
//

#include <stdlib.h>
#include <stdio.h>
#include "n-aria.h"


TNARIA *incializa() {
    TNARIA *result = malloc(sizeof(TNO));
    result->raiz = NULL;
    return result;
}

TNO *buscaNo(TNO *raiz, int id) {
    if (!raiz || raiz->id == id)
        return raiz;
    TNO *busca_irmao = buscaNo(raiz->irmao, id);
    if (busca_irmao == NULL)
        return buscaNo(raiz->filho, id);
    return busca_irmao;
}

TNO *busca(TNARIA *arvore, int id) {
    return buscaNo(arvore->raiz, id);
}


void insere(TNARIA *arvore, int id_pai, int id, TGEOMETRO *geo) {
    TNO *no = malloc(sizeof(TNO));
    no->id = id;
    no->geometro = geo;
    no->filho = NULL;
    no->irmao = NULL;
    if (id_pai == 0) {
        arvore->raiz = no;
        return;
    }
    TNO *pai = buscaNo(arvore->raiz, id_pai);
    no->irmao = pai->filho;
    pai->filho = no;
}

void imprimeUnico(TNO* no){
    if(no==NULL)
        return;
    printf("Id: %d\n Detalhes: ", no->id);
    imprimeDetalhes(no->geometro);
    TNO *filho = no->filho;
    printf(" Filhos: ");
    if (filho != NULL) {
        printf("%d", filho->id);
        TNO *irmao = filho->irmao;
        while (irmao != NULL) {
            printf(" %d", irmao->id);
            irmao = irmao->irmao;
        }
    }
    printf("\n\n");
}

void imprimeNo(TNO *no) {
    imprimeUnico(no);
    if (no->irmao)
        imprimeNo(no->irmao);
    if (no->filho)
        imprimeNo(no->filho);
}

void imprime(TNARIA *arvore) {
    imprimeNo(arvore->raiz);
}
