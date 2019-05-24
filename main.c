#include <stdio.h>
#include <stdlib.h>
#include "geometros/geometro.h"

int main() {
    double a = 4;
    void *trap = criaGeometroPorString("TRA 1 2 3");
    void *tri = criaGeometroPorString("TRI 1 4");
    void *ret = criaGeometroPorString("RET 3 3");
    void *circ = criaGeometroPorString("CIR 4");
    void *quad = criaGeometroPorString("QUA 4");
    imprimeDetalhes(trap);
    imprimeDetalhes(tri);
    mudaDimensoes(trap, "2 2 3");
    imprimeDetalhes(ret);
    imprimeDetalhes(circ);
    imprimeDetalhes(quad);
    imprimeDetalhes(trap);
    return 0;
}