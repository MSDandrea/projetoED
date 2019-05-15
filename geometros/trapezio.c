//
// Created by matheus on 15/05/19.
//

#include "trapezio.h"

double calculaAreaTrapezio(TTRA *ttra) {
    return ((ttra->maior_base + ttra->menor_base) * ttra->altura) / 2.0;
}
