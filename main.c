#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

const char *menu = "1 - Imprime\n"
                   "2 - Busca\n"
                   "3 - Modifica\n"
                   "4 - Remove\n"
                   "5 - Adiciona\n"
                   "6 - Transforma em AVL\n"
                   "9 - Sair\n";

int main() {
    TNARIA *arv = criaDeArquivo("./exemplo-AG.txt");
    int input = 0;
    while (input != 9) {
        printf(menu);
        scanf("%d", &input);
        int id;
        switch (input) {
            case 1:
                imprime(arv);
                break;
            case 2:
                printf("Qual id?\n");
                scanf("%d", &id);
                TNO *no = busca(arv, id);
                if (no) {
                    imprimeUnico(no);
                }
                break;
            case 3:
                printf("Qual id?\n");
                scanf("%d", &id);
                TNO *noM = busca(arv, id);
                if (noM) {
                    char *dim = malloc(sizeof(char) * 250);
                    printf("Entre as novas dimensoes separadas por ';'.\n");
                    scanf("%s", dim);
                    mudaDimensoes(noM->geometro, dim);
                    free(dim);
                }
                break;
            case 4:
                printf("Qual id?\n");
                scanf("%d", &id);
                removeNo(arv, id);
                break;
            case 5:
                printf("Qual id?\n");
                scanf("%d", &id);
                char *g = malloc(sizeof(char) * 4);
                printf("Qual geometro?\n");
                scanf("%s", g);
                double* faux = malloc(sizeof(double)*1);
                TGEOMETRO* geo = criaGeometro(g,faux);
                free(g);
                char *dim = malloc(sizeof(char) * 250);
                printf("Entre as novas dimensoes separadas por ';'.\n");
                scanf("%s", dim);
                mudaDimensoes(geo, dim);
                free(dim);
                int pai=0;
                printf("Qual o pai?\n");
                scanf("%d", &pai);
                insere(arv,pai,id,geo);
                break;
            case 6:
                transformaAVL(arv);
                break;
            case 9:
                limpa(arv);
                break;
            default:
                break;
        }
    }
    return 0;
}