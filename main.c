#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

const char *menu = "1 - Imprime\n"
                   "2 - Busca\n"
                   "3 - Modifica\n"
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
                }
                break;
            default:
                break;
        }
    }
    return 0;
}