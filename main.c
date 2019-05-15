#include <stdio.h>
#include "geometros/geometro.h"

int main() {
    double a = 4;
    void *trap = criaGeometroPorString("TRA 1 2 3");
    void *tri = criaGeometroPorString("TRI 1 2");
    void *ret = criaGeometroPorString("RET 3 3");
    void *circ = criaGeometroPorString("CIR 4");
    void *quad = criaGeometroPorString("QUA 4");
    printf("Area circ: %f; Area quad: %f; Area tri: %f; Area trap: %f; Area ret: %f", calculaArea(circ),
           calculaArea(quad), calculaArea(tri), calculaArea(trap),calculaArea(ret));
    return 0;
}