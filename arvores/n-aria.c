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

void imprimeUnico(TNO *no) {
    if (no == NULL)
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

void freeNo(TNO *no) {
    freeGeo(no->geometro);
    free(no);
}

void limpaNo(TNO *no) {
    if (no->irmao)
        limpaNo(no->irmao);
    if (no->filho)
        limpaNo(no->filho);
    freeNo(no);
}

void deleteNo(TNO *pai, TNO *no, int id) {
    if (!no || !pai) return;
    if (no->id == id) {
        TNO *filho = no->filho;
        TNO *irmao = no->irmao;
        if (!irmao) {
            pai->filho = filho;
        } else {
            pai->filho = irmao;
            TNO *ir = irmao->irmao;
            while (ir) {
                irmao = ir;
                ir = ir->irmao;
            }
            irmao->irmao = filho;
        }
        freeNo(no);
        return;
    }
    TNO *ref = no;
    TNO *irmao = no->irmao;
    while (irmao) {
        if (irmao->id == id) {
            ref->irmao = irmao->irmao;
            while (ref->irmao) ref = ref->irmao;
            ref->irmao = irmao->filho;
            freeNo(irmao);
            break;
        }
        ref = irmao;
        irmao = irmao->irmao;
    }
    if (no->irmao) deleteNo(no->irmao, no->irmao->filho, id);
    deleteNo(no, no->filho, id);

}

void removeNo(TNARIA *arvore, int id) {
    if (arvore->raiz && arvore->raiz->id == id)
        return;
    if (buscaNo(arvore->raiz, id))
        deleteNo(arvore->raiz, arvore->raiz->filho, id);

}

void limpa(TNARIA *arvore) {
    limpaNo(arvore->raiz);
    free(arvore);
}

AVno *transformaNo(TNO *no, AVno *arvore) {
    if (!no) return NULL;
    if (no->filho)
        arvore = transformaNo(no->filho, arvore);
    arvore = insere_avl(no->id, no->geometro, arvore);
    if (no->irmao)
        arvore = transformaNo(no->irmao, arvore);
    return arvore;
}

AVno *transformaAVL(TNARIA *arvore) {
    AVno *raiz = NULL;
    raiz = transformaNo(arvore->raiz, raiz);
    imprimeAVL(raiz);
    liberaAVL(raiz);
    return raiz;

}